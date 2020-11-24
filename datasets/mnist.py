# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mnist.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 19:50:33 by thflahau          #+#    #+#              #
#    Updated: 2020/11/09 19:29:20 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

""" Download the MNIST dataset from internet """

import requests, gzip

URL = 'http://yann.lecun.com/exdb/mnist/'

def save_file(name : str, data : bytes):
	with open(name, 'wb') as file:
		file.write(data)

def get(output : str, file):
	print(f'Fetching data from {URL + file}...')
	response = requests.get(URL + file)
	save_file(output, gzip.decompress(response.content))

if __name__ == '__main__':
	get('mnist_images_train.bin','train-images-idx3-ubyte.gz')
	get('mnist_labels_train.bin','train-labels-idx1-ubyte.gz')
	get('mnist_images_test.bin', 't10k-images-idx3-ubyte.gz')
	get('mnist_labels_test.bin', 't10k-labels-idx1-ubyte.gz')
