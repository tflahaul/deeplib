# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    optimizers.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 12:38:57 by thflahau          #+#    #+#              #
#    Updated: 2020/12/11 16:21:02 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from deeplib.layers import Layer

class Optimizer(object):
	def __init__(self, learning_rate) -> None:
		self.lr = learning_rate

	def update(self, layers : list) -> None:
		raise NotImplementedError

class SGD(Optimizer):
	def __init__(self, learning_rate=0.01) -> None:
		super().__init__(learning_rate)

	def update(self, layers : list) -> None:
		for layer in layers:
			if layer.trainable == True:
				layer.weights = layer.weights - (self.lr * layer.wgrads.T)
				layer.biases = layer.biases - (self.lr * layer.bgrads)
