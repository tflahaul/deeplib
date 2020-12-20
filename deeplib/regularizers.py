# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    regularizers.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 17:27:49 by thflahau          #+#    #+#              #
#    Updated: 2020/12/20 13:25:54 by thflahau         ###   ########.fr        #
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

class max_norm(Regularizer):
	def __init__(self, limit=3.0) -> None:
		self.limit = limit

	def __call__(self, tensor) -> np.ndarray:
		return np.clip(tensor, -self.limit, self.limit)
