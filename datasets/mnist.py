# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mnist.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 19:50:33 by thflahau          #+#    #+#              #
#    Updated: 2020/11/05 19:50:34 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

""" Import the MNIST dataset from internet """

import pandas as pd, numpy as np
import requests, gzip

URL = 'http://yann.lecun.com/exdb/mnist/'

def dataset_from_internet(file) -> bytes:
	try:
		print('Fetching data from', URL + file)
		response = requests.get(URL + file)
		data = gzip.decompress(response.content)
	except Exception as ex:
		print('Error:' + str(ex))
	return data

def write_bfile(name, data):
	with open(name, 'wb') as file:
		file.write(data)

def main():
	write_bfile('mnist_images_train.bin', dataset_from_internet('train-images-idx3-ubyte.gz'))
	write_bfile('mnist_labels_train.bin', dataset_from_internet('train-labels-idx1-ubyte.gz'))
	write_bfile('mnist_images_test.bin', dataset_from_internet('t10k-images-idx3-ubyte.gz'))
	write_bfile('mnist_labels_test.bin', dataset_from_internet('t10k-labels-idx1-ubyte.gz'))

if __name__ == '__main__':
	main()
