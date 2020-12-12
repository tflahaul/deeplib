# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    optimizers.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 12:38:57 by thflahau          #+#    #+#              #
#    Updated: 2020/12/12 23:14:28 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from deeplib.layers import Layer
import numpy as np

class Optimizer(object):
	def __init__(self, learning_rate) -> None:
		self.lr = learning_rate

	def update(self, layers : list) -> None:
		raise NotImplementedError

class SGD(Optimizer):
	def __init__(self, lr=0.01, max_norm=False, limit=3.0) -> None:
		super().__init__(lr)
		self.max_norm = max_norm
		self.limit = limit

	def update(self, layers : list) -> None:
		for layer in layers:
			if layer.trainable == True:
				layer.weights = layer.weights - (self.lr * layer.wgrads.T)
				layer.biases = layer.biases - (self.lr * layer.bgrads)
				if self.max_norm == True:
					layer.weights = np.clip(layer.weights, -(self.limit), self.limit)
					layer.biases = np.clip(layer.biases, -(self.limit), self.limit)
