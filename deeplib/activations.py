# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    activations.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 19:23:02 by thflahau          #+#    #+#              #
#    Updated: 2020/12/11 16:19:33 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import sys

def get(identifier : str):
	return getattr(sys.modules[__name__], identifier)

class ActivationFunction:
	def __init__(self, name : str) -> None:
		self.name = name
		self.call = None
		self.derivative = None

class linear(ActivationFunction):
	def __init__(self) -> None:
		super().__init__('linear')
		self.call = lambda x : x
		self.derivative = lambda x : 1.0

class sigmoid(ActivationFunction):
	def __init__(self) -> None:
		super().__init__('sigmoid')
		self.call = lambda x : 1.0 / (1.0 + np.exp(-x))
		self.derivative = lambda x : x * (1.0 - x)

class relu(ActivationFunction):
	def __init__(self) -> None:
		super().__init__('relu')
		self.call = lambda x : x * (x >= 0.0)
		self.derivative = lambda x : x > 0.0

class leaky(ActivationFunction):
	def __init__(self) -> None:
		super().__init__('leaky')
		self.call = lambda x : x * ((x > 0.0) * 0.1)
		self.derivative = lambda x : 0.1 if x < 0.0 else 1.0

class tanh(ActivationFunction):
	def __init__(self) -> None:
		super().__init__('tanh')
		self.call = lambda x : (np.exp((x) * 2.0) - 1.0) / (np.exp((x) * 2.0) + 1.0)
		self.derivative = lambda x : 1.0 - (x * x)

class softmax(ActivationFunction):
	def __init__(self) -> None:
		super().__init__('softmax')
