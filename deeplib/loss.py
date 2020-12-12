# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    loss.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 21:22:26 by thflahau          #+#    #+#              #
#    Updated: 2020/12/12 13:58:47 by thflahau         ###   ########.fr        #
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
		return np.mean(-((target * np.log(output)) + ((1. - target) * np.log(1. - output))))

	def derivative(self, output, target):
		return (output - target) / (output * (1. - output))

class MeanSquaredError(LossFunction):
	def __init__(self, regularization=None):
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return np.mean((output - target) * (output - target))

	def derivative(self, output, target):
		return 2. * (output - target)

class MeanAbsoluteError(LossFunction):
	def __init__(self, regularization=None):
		if regularization is not None:
			raise NotImplementedError

	def cost(self, output, target):
		return np.mean(np.abs(output - target))

	def derivative(self, output, target):
		return output - target
