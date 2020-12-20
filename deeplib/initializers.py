# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    initializers.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 15:03:31 by thflahau          #+#    #+#              #
#    Updated: 2020/12/19 15:35:15 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def regular(shape):
	return np.random.ranf(size=shape).astype(float)

def regular_scaled(shape):
	return np.random.ranf(size=shape).astype(float) * 0.01

def uniform(shape):
	return np.random.uniform(-1.0, 1.0, size=shape).astype(float)
