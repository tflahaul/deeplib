# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    layers.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 19:11:31 by thflahau          #+#    #+#              #
#    Updated: 2021/01/13 18:16:20 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import deeplib.initializers as initializers
import deeplib.activations as activations
import numpy as np

class Layer(object):
	def __init__(self, **kwargs) -> None:
		self.trainable = kwargs.get('trainable', True)
		self.kernel_constraint = kwargs.get('kernel_constraint', None)
		self.initializer = getattr(initializers, kwargs.get('init', 'regular'))
		np.random.seed(kwargs.get('seed', None))

	def forward(self, inputs):
		raise NotImplementedError

	def backward(self, gradients):
		raise NotImplementedError

class Dense(Layer):
	def __init__(self, in_size, out_size, **kwargs) -> None:
		super(Dense, self).__init__(**kwargs)
		self.weights = self.initializer((in_size, out_size))
		self.biases = np.zeros(shape=(out_size,), dtype=float)
		self.wgrads = np.empty_like(self.weights, dtype=float)
		self.bgrads = np.empty_like(self.biases, dtype=float)

	def forward(self, inputs) -> np.ndarray:
		self.inputs = inputs.copy()
		return inputs.dot(self.weights) + self.biases

	def backward(self, gradients) -> np.ndarray:
		self.bgrads = np.sum(gradients, axis=0, dtype=float)
		self.wgrads = np.dot(self.inputs.T, gradients)
		return np.dot(gradients, self.weights.T)

class Activation(Layer):
	def __init__(self, function='linear') -> None:
		super(Activation, self).__init__(trainable=False)
		self.activation = activations.get(function)()

	def forward(self, inputs) -> np.ndarray:
		self.output = np.array(self.activation.call(inputs), dtype=float)
		return self.output

	def backward(self, gradients) -> np.ndarray:
		return np.array(self.activation.derivative(self.output), dtype=float) * gradients

class Convolution2D(Layer):
	def __init__(self, kernel_height, kernel_width, filters, padding=0, **kwargs) -> None:
		super(Convolution2D, self).__init__(**kwargs)
		self.W_shape = (max(1, filters), max(1, kernel_height), max(1, kernel_width))
		self.weights = self.initializer(self.W_shape)
		self.biases = np.zeros(shape=(self.W_shape[0],), dtype=float)
		self.P = padding

	def forward(self, inputs : np.ndarray) -> np.ndarray:
		self.inputs = inputs.copy()
		inputs = np.pad(inputs, pad_width=(self.P, self.P), mode='constant', constant_values=0)
		return inputs

class Dropout(Layer):
	def __init__(self, rate : float) -> None:
		super(Dropout, self).__init__(trainable=False)
		self.rate = 1.0 - min(1.0, max(0.0, rate))

	def forward(self, inputs : np.ndarray) -> np.ndarray:
		self.mask = np.random.binomial(1, self.rate, size=inputs.shape) * (1.0 / self.rate)
		return inputs * self.mask

	def backward(self, gradients) -> np.ndarray:
		return gradients * self.mask

class Normalization(Layer):
	def __init__(self) -> None:
		super(Normalization, self).__init__(trainable=False)
		raise DeprecationWarning

	def forward(self, inputs) -> np.ndarray:
		return (inputs - np.min(inputs)) / (np.max(inputs) - np.min(inputs))

	def backward(self, gradients):
		pass
