# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    optimizers.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 12:38:57 by thflahau          #+#    #+#              #
#    Updated: 2020/12/24 21:00:40 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from deeplib.layers import Layer
import deeplib.regularizers as regularizers
import numpy as np

class Optimizer(object):
	def __init__(self, layers, learning_rate) -> None:
		self.layers = [item for item in layers if item.trainable == True]
		self.lr = learning_rate
		self.constraint = None

	def set_constraint(self, identifier : str) -> None:
		self.constraint = regularizers.get(identifier)()

	def update(self) -> None:
		raise NotImplementedError

class SGD(Optimizer):
	def __init__(self, layers, lr=0.01) -> None:
		super(SGD, self).__init__(layers, lr)

	def update(self) -> None:
		for layer in self.layers:
			layer.weights -= self.lr * layer.wgrads
			layer.biases -= self.lr * layer.bgrads
			if self.constraint is not None:
				layer.weights = self.constraint(layer.weights)

class AdaGrad(Optimizer):
	def __init__(self, layers, lr=0.01, epsilon=1e-8, initial_accumulator=0.1) -> None:
		super(AdaGrad, self).__init__(layers, lr)
		self.accumulator = [None] * len(self.layers)
		for index, layer in enumerate(self.layers):
			self.accumulator[index] = dict({
				'weights' : np.full_like(layer.wgrads, initial_accumulator),
				'biases' : np.full_like(layer.bgrads, initial_accumulator)
			})
		self.eps = epsilon

	def update(self) -> None:
		for acc, layer in zip(self.accumulator, self.layers):
			acc['weights'] += layer.wgrads ** 2
			acc['biases'] += layer.bgrads ** 2
			layer.weights -= self.lr * (layer.wgrads / np.sqrt(self.eps + acc['weights']))
			layer.biases -= self.lr * (layer.bgrads / np.sqrt(self.eps + acc['biases']))
			if self.constraint is not None:
				layer.weights = self.constraint(layer.weights)

class RMSprop(Optimizer):
	def __init__(self, layers, lr=0.01, decay=0.9, epsilon=1e-8) -> None:
		super(RMSprop, self).__init__(layers, lr)
		self.vector = [None] * len(self.layers)
		for index, layer in enumerate(self.layers):
			self.vector[index] = dict({
				'weights' : np.zeros_like(layer.wgrads, dtype=float),
				'biases' : np.zeros_like(layer.bgrads, dtype=float)
			})
		self.decay = decay
		self.eps = epsilon

	def update(self) -> None:
		for vec, layer in zip(self.vector, self.layers):
			vec['weights'] = self.decay * vec['weights'] + (1.0 - self.decay) * (layer.wgrads ** 2)
			vec['biases'] = self.decay * vec['biases'] + (1.0 - self.decay) * (layer.bgrads ** 2)
			layer.weights -= self.lr * layer.wgrads / np.sqrt(self.eps + vec['weights'])
			layer.biases -= self.lr * layer.bgrads / np.sqrt(self.eps + vec['biases'])
			if self.constraint is not None:
				layer.weights = self.constraint(layer.weights)

class Adam(Optimizer):
	def __init__(self, layers, lr=0.01, b1=0.9, b2=0.999, epsilon=1e-8) -> None:
		super(Adam, self).__init__(layers, lr)
		self.eps = epsilon
		self.b1 = b1
		self.b2 = b2
