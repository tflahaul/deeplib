# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    initializers.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 15:03:31 by thflahau          #+#    #+#              #
#    Updated: 2021/01/11 20:09:37 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy.random as nrand

def regular(shape, dtype=float):
	return nrand.ranf(size=shape).astype(dtype)

def regular_scaled(shape, dtype=float):
	return nrand.ranf(size=shape).astype(dtype) * 0.01

def uniform(shape, dtype=float):
	return nrand.uniform(-1.0, 1.0, size=shape).astype(dtype)

def normal(shape, dtype=float):
	return nrand.normal(size=shape).astype(dtype)
