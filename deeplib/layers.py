# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    layers.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 19:11:31 by thflahau          #+#    #+#              #
#    Updated: 2021/01/23 17:34:01 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import deeplib.initializers as initializers
import deeplib.activations
import numpy as np

class Layer(object):
	def __init__(self, **kwargs) -> None:
		available_args = ['trainable', 'kernel_init', 'kernel_constraint', 'seed']
		for argument in kwargs:
			if argument not in available_args:
				raise AttributeError('Unknown argument : ' + argument)
		self.trainable = kwargs.get('trainable', True)
		self.initializer = getattr(initializers, kwargs.get('kernel_init', 'regular'))
		self.kernel_constraint = kwargs.get('kernel_constraint', None)
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
		self.wgrads = np.empty_like(self.weights)
		self.bgrads = np.empty_like(self.biases)

	def forward(self, inputs) -> np.ndarray:
		self.cached = inputs.copy()
		return inputs.dot(self.weights) + self.biases

	def backward(self, gradients) -> np.ndarray:
		self.bgrads = np.sum(gradients, axis=0)
		self.wgrads = np.dot(self.cached.T, gradients)
		return np.dot(gradients, self.weights.T)

class Activation(Layer):
	def __init__(self, function='linear') -> None:
		super(Activation, self).__init__(trainable=False)
		self.activation = deeplib.activations.get(function)()

	def forward(self, inputs) -> np.ndarray:
		self.cached = np.array(self.activation.call(inputs))
		return self.cached

	def backward(self, gradients) -> np.ndarray:
		return np.array(self.activation.derivative(self.cached)) * gradients

class Convolution2D(Layer):
	def __init__(self, kernel_height, kernel_width, filters, padding=0, **kwargs) -> None:
		super(Convolution2D, self).__init__(**kwargs)
		self.W_shape = (max(1, filters), max(1, kernel_height), max(1, kernel_width))
		self.weights = self.initializer(self.W_shape)
		self.biases = np.zeros(shape=(self.W_shape[0],), dtype=float)
		self.p = padding

	def forward(self, inputs) -> np.ndarray:
		self.cached = inputs.copy()
		inputs = np.pad(inputs, pad_width=(0, self.p), mode='constant', constant_values=0.0)
		return inputs

class Dropout(Layer):
	def __init__(self, rate : float) -> None:
		super(Dropout, self).__init__(trainable=False)
		self.rate = 1.0 - min(1.0, max(0.0, rate))

	def forward(self, inputs) -> np.ndarray:
		self.mask = np.random.binomial(1, self.rate, size=inputs.shape)
		return inputs * self.mask

	def backward(self, gradients) -> np.ndarray:
		return gradients * self.mask

class Flatten(Layer):
	def __init__(self) -> None:
		super(Flatten, self).__init__(trainable=False)

	def forward(self, inputs) -> np.ndarray:
		self.input_shape = inputs.shape
		return inputs.flatten()

	def backward(self, gradients) -> np.ndarray:
		return gradients.reshape(self.input_shape)

class Normalization(Layer):
	def __init__(self, epsilon=1e-7) -> None:
		super(Normalization, self).__init__(trainable=False)
		self.eps = epsilon

	def forward(self, inputs) -> np.ndarray:
		self.cached = inputs.copy()
		return (inputs - inputs.mean(keepdims=True)) / (self.eps + inputs.std(keepdims=True))
