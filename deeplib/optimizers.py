# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    optimizers.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 12:38:57 by thflahau          #+#    #+#              #
#    Updated: 2020/12/22 09:33:05 by thflahau         ###   ########.fr        #
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
		self.acc = [None] * len(self.layers)
		for idx, layer in enumerate(self.layers):
			self.acc[idx] = {
				'weights' : np.full_like(layer.wgrads, initial_accumulator),
				'biases' : np.full_like(layer.bgrads, initial_accumulator)
			}
		self.eps = epsilon

	def update(self) -> None:
		for idx, layer in enumerate(self.layers):
			self.acc[idx]['weights'] += layer.wgrads ** 2
			self.acc[idx]['biases'] += layer.bgrads ** 2
			layer.weights -= self.lr * layer.wgrads / np.sqrt(self.eps + self.acc[idx]['weights'])
			layer.biases -= self.lr * layer.bgrads / np.sqrt(self.eps + self.acc[idx]['biases'])
			if self.constraint is not None:
				layer.weights = self.constraint(layer.weights)

class RMSProp(Optimizer):
	def __init__(self, layers, lr=0.01, decay=0.9, epsilon=1e-8, initial_accumulator=0.1) -> None:
		super(RMSProp, self).__init__(layers, lr)
		self.acc = [None] * len(self.layers)
		for idx, layer in enumerate(self.layers):
			self.acc[idx] = {
				'weights' : np.full_like(layer.wgrads, initial_accumulator),
				'biases' : np.full_like(layer.bgrads, initial_accumulator)
			}
		self.decay = decay
		self.eps = epsilon

	def update(self) -> None:
		for idx, layer in enumerate(self.layers):
			self.acc[idx]['weights'] = self.decay * self.acc[idx]['weights'] + (1.0 - self.decay) * layer.wgrads ** 2
			self.acc[idx]['biases'] = self.decay * self.acc[idx]['biases'] + (1.0 - self.decay) * layer.bgrads ** 2
			layer.weights -= self.lr * layer.wgrads / np.sqrt(self.acc[idx]['weights'] + self.eps)
			layer.biases -= self.lr * layer.bgrads / np.sqrt(self.acc[idx]['biases'] + self.eps)
			if self.constraint is not None:
				layer.weights = self.constraint(layer.weights)
