# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    loss.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 21:22:26 by thflahau          #+#    #+#              #
#    Updated: 2020/12/17 14:53:04 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

class LossFunction(object):
	def __init__(self):
		pass

	def cost(self, output, target):
		raise NotImplementedError

	def derivative(self, output, target):
		raise NotImplementedError

class BinaryCrossEntropy(LossFunction):
	def __init__(self, regularization=None):
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return (-target * np.log(output) - (1. - target) * np.log(1. - output)).mean()

	def derivative(self, output, target):
		return (output - target) / (output * (1. - output))

class MeanSquaredError(LossFunction):
	def __init__(self, regularization=None):
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return ((output - target) * (output - target)).mean()

	def derivative(self, output, target):
		return 2. * (output - target)

class MeanAbsoluteError(LossFunction):
	def __init__(self, regularization=None):
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return np.abs(output - target).mean()

	def derivative(self, output, target):
		return output - target
