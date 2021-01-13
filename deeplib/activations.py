# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    activations.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 19:23:02 by thflahau          #+#    #+#              #
#    Updated: 2021/01/13 18:21:50 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import sys

def get(identifier : str):
	return getattr(sys.modules[__name__], identifier)

class ActivationFunction:
	def __init__(self, name : str = 'linear') -> None:
		self.name = name
		self.call = lambda x : x
		self.derivative = lambda x : 1.0

class sigmoid(ActivationFunction):
	def __init__(self) -> None:
		super(sigmoid, self).__init__('sigmoid')
		self.call = lambda x : 1.0 / (1.0 + np.exp(-x))
		self.derivative = lambda x : x * (1.0 - x)

class relu(ActivationFunction):
	def __init__(self) -> None:
		super(relu, self).__init__('relu')
		self.call = lambda x : np.maximum(x, 0.0)
		self.derivative = lambda x : x > 0.0

class elu(ActivationFunction):
	def __init__(self) -> None:
		super(elu, self).__init__('elu')
		self.call = lambda x : (x >= 0.0) * x + (x < 0.0) * (np.exp(x) - 1.0)
		self.derivative = lambda x : (x >= 0.0) + (x < 0.0) * (x + 1.0)

class leaky(ActivationFunction):
	def __init__(self) -> None:
		super(leaky, self).__init__('leaky')
		self.call = lambda x : x * ((x > 0.0) * 0.1)
		self.derivative = lambda x : 0.1 if x < 0.0 else 1.0

class tanh(ActivationFunction):
	def __init__(self) -> None:
		super(tanh, self).__init__('tanh')
		self.call = lambda x : (np.exp((x) * 2.0) - 1.0) / (np.exp((x) * 2.0) + 1.0)
		self.derivative = lambda x : 1.0 - (x ** 2)
