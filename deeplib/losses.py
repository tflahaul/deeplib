# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    losses.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 21:22:26 by thflahau          #+#    #+#              #
#    Updated: 2021/01/18 13:17:57 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import sys

def get(identifier : str):
	return dict({
		'crossentropy' : getattr(sys.modules[__name__], 'CrossEntropy'),
		'binary_crossentropy' : getattr(sys.modules[__name__], 'BinaryCrossEntropy'),
		'mean_squared_error' : getattr(sys.modules[__name__], 'MeanSquaredError'),
		'mean_absolute_error' : getattr(sys.modules[__name__], 'MeanAbsoluteError')
	})[identifier]

class LossFunction(object):
	def __init__(self):
		pass

	def cost(self, output, target):
		raise NotImplementedError

	def derivative(self, output, target):
		raise NotImplementedError

class CrossEntropy(LossFunction):
	def __init__(self, regularization=None) -> None:
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return -(target * np.log(output)).mean()

	def derivative(self, output, target):
		return output - target

class BinaryCrossEntropy(LossFunction):
	def __init__(self, regularization=None, epsilon=1e-7) -> None:
		if regularization is not None:
			raise NotImplementedError
		self.eps = epsilon

	def cost(self, output, target):
		output = np.clip(output, self.eps, 1.0 - self.eps)
		return (-(target * np.log(output) + (1.0 - target) * np.log(1.0 - output))).mean()

	def derivative(self, output, target):
		output = np.clip(output, self.eps, 1.0 - self.eps)
		return (output - target) / (output * (1.0 - output))

class MeanSquaredError(LossFunction):
	def __init__(self, regularization=None) -> None:
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return ((output - target) ** 2).mean()

	def derivative(self, output, target):
		return 2.0 * (output - target)

class MeanAbsoluteError(LossFunction):
	def __init__(self, regularization=None) -> None:
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return np.abs(output - target).mean()

	def derivative(self, output, target):
		return output - target
