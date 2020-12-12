# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    initializers.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 15:03:31 by thflahau          #+#    #+#              #
#    Updated: 2020/12/09 18:37:52 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def regular(shape):
	return 2.0 * np.random.ranf(size=shape) - 1.0

def uniform(shape):
	return np.random.uniform(low=-1.0, high=1.0, size=shape)

def logistic(shape):
	return np.random.logistic(size=shape)
