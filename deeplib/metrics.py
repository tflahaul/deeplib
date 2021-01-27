# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    metrics.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 14:48:05 by thflahau          #+#    #+#              #
#    Updated: 2021/01/27 19:24:48 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import sys

def get(identifier : str):
	return getattr(sys.modules[__name__], identifier)

def accuracy(model, X : np.ndarray, y : np.ndarray) -> float:
	""" Multiclass accuracy """
#	return np.mean([np.argmax(model.predict(_X)) == np.argmax(_y) for _X, _y in zip(X, y)])
	return np.mean(np.argmax(model.predict(X), axis=-1) == y)

def sc_accuracy(model, X : np.ndarray, y : np.ndarray) -> float:
	""" Single class accuracy """
	return np.mean([round(model.predict(_X)[0]) == _y for _X, _y in zip(X, y)])
