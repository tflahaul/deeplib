# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    layers.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 19:11:31 by thflahau          #+#    #+#              #
#    Updated: 2020/12/11 17:34:39 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import deeplib.initializers as initializers
import deeplib.activations as activations
import numpy as np

class Layer:
	def __init__(self, trainable) -> None:
		self.trainable = trainable

	def forward(self, inputs):
		raise NotImplementedError

	def backward(self, gradients):
		raise NotImplementedError

class Dense(Layer):
	def __init__(self, in_size, out_size, init='regular', seed=None) -> None:
		super().__init__(trainable=True)
		self.biases = np.ones(shape=(out_size,))
		np.random.seed(seed)
		self.weights = getattr(initializers, init)((out_size, in_size))

	def forward(self, inputs) -> np.ndarray:
		self.inputs = inputs
		return inputs.dot(self.weights.T) + self.biases

	def backward(self, gradients) -> np.ndarray:
		self.bgrads = np.sum(gradients, axis=0)
		self.wgrads = np.dot(self.inputs.T, gradients)
		return np.dot(gradients, self.weights)

class Activation(Layer):
	def __init__(self, function='linear') -> None:
		super().__init__(trainable=False)
		self.activation = activations.get(function)()

	def forward(self, inputs) -> np.ndarray:
		self.inputs = np.array([self.activation.call(x) for x in inputs])
		return self.inputs

	def backward(self, gradients) -> np.ndarray:
		return np.array([self.activation.derivative(x) for x in self.inputs]) * gradients

class Dropout(Layer):
	def __init__(self, rate : float) -> None:
		super().__init__(trainable=False)
		self.rate = 1.0 - min(1.0, max(0.0, rate))

	def forward(self, inputs : np.ndarray) -> np.ndarray:
		self.mask = np.random.binomial(1, self.rate, size=inputs.shape)
		return inputs * self.mask

	def backward(self, gradients) -> np.ndarray:
		return gradients * self.mask

class Normalization(Layer):
	def __init__(self) -> None:
		super().__init__(trainable=False)

	def forward(self, inputs) -> np.ndarray:
		return (inputs - min(inputs)) / (max(inputs) - min(inputs))

	def backward(self, gradients):
		pass
