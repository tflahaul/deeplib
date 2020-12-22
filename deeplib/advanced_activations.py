# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    advanced_activations.py                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 17:59:53 by thflahau          #+#    #+#              #
#    Updated: 2020/12/22 09:26:26 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import sys

def get(identifier : str):
	return getattr(sys.modules[__name__], identifier)

class AdvancedActivationFunction:
	def __init__(self, name : str) -> None:
		self.name = name

	def forward(self, inputs):
		raise NotImplementedError

	def backward(self, gradients):
		raise NotImplementedError

class softmax(AdvancedActivationFunction):
	def __init__(self) -> None:
		super(softmax, self).__init__('softmax')

	def forward(self, inputs) -> np.ndarray:
		e = np.exp(inputs - np.max(inputs))
		return e / np.sum(e)
