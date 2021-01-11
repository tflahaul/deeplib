# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    network.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 19:20:18 by thflahau          #+#    #+#              #
#    Updated: 2021/01/11 20:10:40 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from deeplib.regularizers import EarlyStopping
from deeplib.layers import Layer
from numpy.random import MT19937
import numpy as np

class Network(object):
	def __init__(self, layers=list()) -> None:
		self.layers = layers

	def __batch_generator(self, X : np.ndarray, y : np.ndarray):
		batch_size = min(X.shape[0], max(1, self.batch_size))
		steps = np.arange(0, X.shape[0], batch_size)
		if self.shuffle == True:
			np.random.Generator(MT19937()).shuffle(steps)
		for start in steps:
			end = start + batch_size
			yield (X[start:end], y[start:end])

	def __feed(self, X : np.ndarray) -> np.ndarray:
		output = X.copy()
		for layer in self.layers:
			output = layer.forward(output)
		return output

	def __bprop(self, gradients : np.ndarray) -> None:
		for layer in reversed(self.layers):
			gradients = layer.backward(gradients)

	def add(self, layer : Layer) -> None:
		self.layers.append(layer)

	def prepare(self, optimizer, loss, batch_size=32, shuffle=False):
		self.optimizer = optimizer
		self.loss = loss
		self.batch_size = batch_size
		self.shuffle = shuffle

	def fit(self, X : np.ndarray, y : np.ndarray, epochs=500, patience=5):
		assert X.shape[0] == y.shape[0], 'X and y shapes differ'
		metrics = list()
		early_stop = EarlyStopping(patience=patience)
		for epoch in range(epochs):
			epoch_cost = 0.0
			for _X, _y in self.__batch_generator(X, y):
				output = self.__feed(_X)
				epoch_cost += self.loss.cost(output, _y)
				gradients = self.loss.derivative(output, _y)
				self.__bprop(gradients)
				self.optimizer.update()
			metrics.append(epoch_cost)
			print(f'epoch {epoch + 1}/{epochs}, loss={epoch_cost:.9f}')
			if early_stop(metrics) == True:
				break
		return metrics

	def predict(self, X):
		return self.__feed(X)
