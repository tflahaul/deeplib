# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    network.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 19:20:18 by thflahau          #+#    #+#              #
#    Updated: 2020/12/12 22:42:59 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from deeplib.layers import Layer
import deeplib.initializers
import numpy as np

class Network(object):
	def __init__(self, layers=list()) -> None:
		self.layers = layers

	def __batch_generator(self, X : np.ndarray, y : np.ndarray):
		batch_size = min(X.shape[0], max(1, self.batch_size))
		steps = np.arange(0, X.shape[0], batch_size)
		if self.shuffle == True:
			np.random.shuffle(steps)
		for start in steps:
			end = start + batch_size
			yield (X[start:end], y[start:end])

	def feed(self, X : np.ndarray) -> np.ndarray:
		for layer in self.layers:
			X = layer.forward(X)
		return X

	def __bprop(self, gradients : np.ndarray) -> None:
		for layer in reversed(self.layers):
			gradients = layer.backward(gradients)

	def add(self, layer : Layer) -> None:
		self.layers.append(layer)

	def prepare(self, optimizer, loss, batch_size=32, shuffle=False) -> None:
		self.optimizer = optimizer
		self.loss = loss
		self.batch_size = batch_size
		self.shuffle = shuffle

	def fit(self, X : np.ndarray, y : np.ndarray, epochs=500, patience=1e-7) -> None:
		costs = np.zeros(shape=2)
		for epoch in range(epochs):
			costs[1] = costs[0]; costs[0] = 0.0
			for _X, _y in self.__batch_generator(X, y):
				output = self.feed(_X)
				costs[0] += self.loss.cost(output, _y)
				gradients = self.loss.derivative(output, _y)
				self.__bprop(gradients)
				self.optimizer.update(self.layers)
			print(f'epoch {epoch}/{epochs}, loss={costs[0]}')
			if np.absolute(costs[0] - costs[1]) < patience:
				break
