# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    losses.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 21:22:26 by thflahau          #+#    #+#              #
#    Updated: 2021/04/14 21:28:11 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import sys

def get(identifier : str):
	return getattr(sys.modules[__name__], identifier)

class LossFunction(object):
	def __init__(self):
		pass

	def cost(self, output, target):
		raise NotImplementedError

	def derivative(self, output, target):
		raise NotImplementedError

class CrossEntropy(LossFunction):
	def __init__(self, regularization=None, epsilon=1e-7) -> None:
		if regularization is not None:
			raise NotImplementedError
		self.eps = epsilon

	def cost(self, output, target):
		self.cached = np.clip(output, self.eps, 1.0 - self.eps)
		return (-(target * np.log(self.cached) + (1.0 - target) * np.log(1.0 - self.cached))).mean()

	def derivative(self, output, target):
		return (self.cached - target) / (self.cached * (1.0 - self.cached))

class MeanSquaredError(LossFunction):
	def __init__(self, regularization=None) -> None:
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return np.square(output - target).mean()

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

crossentropy = CrossEntropy
binary_crossentropy = crossentropy
mean_squared_error = MeanSquaredError
mean_absolute_error = MeanAbsoluteError
