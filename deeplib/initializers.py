# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    initializers.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 15:03:31 by thflahau          #+#    #+#              #
#    Updated: 2020/12/24 13:22:17 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy.random as nrand

def regular(shape):
	return nrand.ranf(size=shape).astype(float)

def regular_scaled(shape):
	return nrand.ranf(size=shape).astype(float) * 0.01

def uniform(shape):
	return nrand.uniform(-1.0, 1.0, size=shape).astype(float)

def normal(shape):
	return nrand.normal(size=shape).astype(float)
