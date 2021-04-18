# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    optimizers.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 12:38:57 by thflahau          #+#    #+#              #
#    Updated: 2021/04/14 21:23:03 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from deeplib.layers import Layer
import numpy as np

class Optimizer(object):
	def __init__(self, layers, learning_rate) -> None:
		self.layers = [item for item in layers if item.trainable == True]
		self.lr = learning_rate

	def update(self) -> None:
		raise NotImplementedError

class SGD(Optimizer):
	def __init__(self, layers, lr=0.01) -> None:
		super(SGD, self).__init__(layers, lr)

	def update(self) -> None:
		for layer in self.layers:
			layer.weights -= self.lr * layer.wgrads
			layer.biases -= self.lr * layer.bgrads
			if layer.kernel_constraint is not None:
				layer.weights = layer.kernel_constraint(layer.weights)

class AdaGrad(Optimizer):
	def __init__(self, layers, lr=0.01, epsilon=1e-7, initial_accumulator=0.1) -> None:
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
			acc['weights'] += np.square(layer.wgrads)
			acc['biases'] += np.square(layer.bgrads)
			layer.weights -= self.lr * (layer.wgrads / np.sqrt(self.eps + acc.get('weights')))
			layer.biases -= self.lr * (layer.bgrads / np.sqrt(self.eps + acc.get('biases')))
			if layer.kernel_constraint is not None:
				layer.weights = layer.kernel_constraint(layer.weights)

class RMSprop(Optimizer):
	def __init__(self, layers, lr=0.01, decay=0.9, epsilon=1e-7) -> None:
		super(RMSprop, self).__init__(layers, lr)
		self.vector = [None] * len(self.layers)
		for index, layer in enumerate(self.layers):
			self.vector[index] = dict({
				'weights' : np.zeros_like(layer.wgrads),
				'biases' : np.zeros_like(layer.bgrads)
			})
		self.decay = decay
		self.eps = epsilon

	def update(self) -> None:
		for vec, layer in zip(self.vector, self.layers):
			vec['weights'] = self.decay * vec['weights'] + (1.0 - self.decay) * np.square(layer.wgrads)
			vec['biases'] = self.decay * vec['biases'] + (1.0 - self.decay) * np.square(layer.bgrads)
			layer.weights -= self.lr * layer.wgrads / np.sqrt(self.eps + vec.get('weights'))
			layer.biases -= self.lr * layer.bgrads / np.sqrt(self.eps + vec.get('biases'))
			if layer.kernel_constraint is not None:
				layer.weights = layer.kernel_constraint(layer.weights)

class Adam(Optimizer):
	def __init__(self, layers, lr=0.01, b1=0.9, b2=0.999, epsilon=1e-7) -> None:
		super(Adam, self).__init__(layers, lr)
		self.vector = [None] * len(self.layers)
		for index, layer in enumerate(self.layers):
			self.vector[index] = dict({
				'm_weights' : np.zeros_like(layer.wgrads),
				'v_weights' : np.zeros_like(layer.wgrads),
				'm_biases' : np.zeros_like(layer.bgrads),
				'v_biases' : np.zeros_like(layer.bgrads)
			})
		self.eps = epsilon
		self.b1 = b1
		self.b2 = b2

	def update(self) -> None:
		for vec, layer in zip(self.vector, self.layers):
			vec['m_weights'] = self.b1 * vec['m_weights'] + (1.0 - self.b1) * layer.wgrads
			vec['v_weights'] = self.b2 * vec['v_weights'] + (1.0 - self.b2) * np.square(layer.wgrads)
			vec['m_biases'] = self.b1 * vec['m_biases'] + (1.0 - self.b1) * layer.bgrads
			vec['v_biases'] = self.b2 * vec['v_biases'] + (1.0 - self.b2) * np.square(layer.bgrads)
			layer.weights -= self.lr * vec.get('m_weights') / (self.eps + np.sqrt(vec.get('v_weights')))
			layer.biases -= self.lr * vec.get('m_biases') / (self.eps + np.sqrt(vec.get('v_biases')))
			if layer.kernel_constraint is not None:
				layer.weights = layer.kernel_constraint(layer.weights)
