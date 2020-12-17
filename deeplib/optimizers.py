# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    optimizers.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 12:38:57 by thflahau          #+#    #+#              #
#    Updated: 2020/12/17 15:17:02 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from deeplib.layers import Layer
import deeplib.regularizers as regularizers
import numpy as np

class Optimizer(object):
	def __init__(self, learning_rate, regularizer=None) -> None:
		self.lr = learning_rate
		if regularizer is not None:
			self.regularizer = regularizers.get(regularizer)()
		else:
			self.regularizer = None

	def update(self, layers : list) -> None:
		raise NotImplementedError

class SGD(Optimizer):
	def __init__(self, lr=0.01, regularizer=None) -> None:
		super().__init__(lr, regularizer)

	def update(self, layers : list) -> None:
		for layer in filter(lambda x : x.trainable == True, layers):
			layer.weights -= self.lr * layer.wgrads
			layer.biases -= self.lr * layer.bgrads
			if self.regularizer is not None:
				layer.weights = self.regularizer.update(layer.weights)
				layer.biases = self.regularizer.update(layer.biases)
