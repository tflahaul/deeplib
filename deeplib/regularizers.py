# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    regularizers.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 17:27:49 by thflahau          #+#    #+#              #
#    Updated: 2020/12/17 14:52:16 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import sys

def get(identifier : str):
	return getattr(sys.modules[__name__], identifier)

class Regularizer(object):
	def __init__(self) -> None:
		pass

	def update(self, tensor) -> np.ndarray:
		raise NotImplementedError

class max_norm(Regularizer):
	def __init__(self, limit=3.0) -> None:
		self.limit = limit

	def update(self, tensor) -> np.ndarray:
		return np.clip(tensor, -self.limit, self.limit)
