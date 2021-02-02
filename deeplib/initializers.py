# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    initializers.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 15:03:31 by thflahau          #+#    #+#              #
#    Updated: 2021/02/02 19:15:10 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import numpy.random as nrand

def regular(shape, dtype='float32'):
	return nrand.ranf(size=shape).astype(dtype)

def regular_scaled(shape, dtype='float32'):
	return nrand.ranf(size=shape).astype(dtype) * 0.1

def uniform(shape, dtype='float32'):
	return nrand.uniform(-1.0, 1.0, size=shape).astype(dtype)

def normal(shape, dtype='float32'):
	return nrand.normal(size=shape).astype(dtype)

def he_uniform(shape, dtype='float32'):
	scale = np.sqrt(6.0 / shape[1])
	return nrand.uniform(-scale, scale, size=shape).astype(dtype)

def he_normal(shape, dtype='float32'):
	return nrand.normal(0.0, np.sqrt(2.0 / shape[1]), size=shape).astype(dtype)
