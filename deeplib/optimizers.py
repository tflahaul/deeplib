# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    optimizers.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 12:38:57 by thflahau          #+#    #+#              #
#    Updated: 2020/12/20 13:26:36 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from deeplib.layers import Layer
import deeplib.regularizers as regularizers
import numpy as np

class Optimizer(object):
	def __init__(self, layers, learning_rate) -> None:
		self.layers = [item for item in layers if item.trainable == True]
		self.lr = learning_rate
		self.regularizer = None

	def set_constraint(self, identifier : str) -> None:
		self.regularizer = regularizers.get(identifier)()

	def update(self) -> None:
		raise NotImplementedError

class SGD(Optimizer):
	def __init__(self, layers, lr=0.01) -> None:
		super(SGD, self).__init__(layers, lr)

	def update(self) -> None:
		for layer in self.layers:
			layer.weights -= self.lr * layer.wgrads
			layer.biases -= self.lr * layer.bgrads
			if self.regularizer is not None:
				layer.weights = self.regularizer(layer.weights)
				layer.biases = self.regularizer(layer.biases)

class AdaGrad(Optimizer):
	def __init__(self, layers, lr=0.01, epsilon=1e-8, initial_accumulator=0.1) -> None:
		super(AdaGrad, self).__init__(layers, lr)
		self.h = [None] * len(self.layers)
		for idx, layer in enumerate(self.layers):
			self.h[idx] = {
				'weights' : np.full_like(layer.wgrads, initial_accumulator),
				'biases' : np.full_like(layer.bgrads, initial_accumulator)
			}
		self.eps = epsilon

	def update(self) -> None:
		for idx, layer in enumerate(self.layers):
			self.h[idx]['weights'] += (layer.wgrads * layer.wgrads)
			self.h[idx]['biases'] += (layer.bgrads * layer.bgrads)
			layer.weights -= self.lr * (layer.wgrads / np.sqrt(self.eps + self.h[idx]['weights']))
			layer.biases -= self.lr * (layer.bgrads / np.sqrt(self.eps + self.h[idx]['biases']))
			if self.regularizer is not None:
				layer.weights = self.regularizer(layer.weights)
				layer.biases = self.regularizer(layer.biases)

class RMSProp(Optimizer):
	def __init__(self, layers, lr=0.01, decay=0.9, epsilon=1e-8) -> None:
		super(RMSProp, self).__init__(layers, lr)
		self.decay = decay
		self.eps = epsilon

	def update(self) -> None:
		pass
