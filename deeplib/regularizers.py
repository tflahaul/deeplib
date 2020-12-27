# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    regularizers.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 17:27:49 by thflahau          #+#    #+#              #
#    Updated: 2020/12/27 13:56:37 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import sys

def get(identifier : str):
	return getattr(sys.modules[__name__], identifier)

class Regularizer(object):
	def __init__(self) -> None:
		pass

	def __call__(self, tensor) -> np.ndarray:
		raise NotImplementedError

class NonNeg(Regularizer):
	def __init__(self) -> None:
		pass

	def __call__(self, weights) -> np.ndarray:
		return weights * (weights >= 0.0)

class EarlyStopping(Regularizer):
	def __init__(self, patience=10, gap=2e-7) -> None:
		self.patience = patience
		self.gap = gap

	def __call__(self, validation_loss : list):
		if len(validation_loss) > self.patience:
			start = len(validation_loss) - self.patience
			minimum = validation_loss[start]
			for value in validation_loss[start:]:
				if value < (minimum - self.gap):
					minimum = value
			return minimum == validation_loss[start]
		else:
			return False
