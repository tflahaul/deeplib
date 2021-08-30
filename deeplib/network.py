# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    network.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 19:20:18 by thflahau          #+#    #+#              #
#    Updated: 2021/04/14 22:29:46 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from numpy.random import MT19937
import deeplib.metrics
import deeplib.layers
import deeplib.losses
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

	def add(self, layer : deeplib.layers.Layer) -> None:
		self.layers.append(layer)

	def prepare(self, optimizer, loss, batch_size=32, shuffle=True):
		self.optimizer = optimizer
		self.batch_size = batch_size
		self.shuffle = shuffle
		if isinstance(loss, str):
			self.loss = deeplib.losses.get(loss)()
		else:
			self.loss = loss

	def fit(self, X, y, X_valid=None, y_valid=None, epochs=100, early_stop=None, metrics=[]):
		assert X.shape[0] == y.shape[0], 'X and y shapes differ'
		costs = list()
		for epoch in range(epochs):
			epoch_cost = 0.0
			for _X, _y in self.__batch_generator(X, y):
				output = self.__feed(_X)
				epoch_cost += self.loss.cost(output, _y)
				gradients = self.loss.derivative(output, _y)
				self.__bprop(gradients)
				self.optimizer.update()
			costs.append(epoch_cost)
			verbose_format = f'Epoch {epoch + 1:02d}/{epochs}, loss={epoch_cost:.8f}'
			if any(metrics) and X_valid is not None and y_valid is not None:
				for item in metrics:
					verbose_format += f', {item}={deeplib.metrics.get(item)(self, X_valid, y_valid):.4f}'
			print(verbose_format)
			if early_stop and early_stop(costs) == True:
				break

	def predict(self, X : np.ndarray) -> np.ndarray:
		temp = self.layers
		self.layers = [x for x in self.layers if not isinstance(x, deeplib.layers.Dropout)]
		output = self.__feed(X)
		self.layers = temp
		return output

	def validation_loss(self, X, y):
		return sum([self.loss.cost(self.__feed(_X), _y) for _X, _y in self.__batch_generator(X, y)])

	def export(self, name : str) -> None:
		assert any(self.layers), 'network is empty, aborting'
		objects = list()
		for layer in self.layers:
			obj = dict({'name' : type(layer), 'data' : layer.__dict__})
			if type(layer) is deeplib.layers.Activation:
				obj['data'] = layer.activation.name
			objects.append(obj)
		np.save(name, objects, allow_pickle=True)
		print('\'' + name + '\' successfully saved on disk')
