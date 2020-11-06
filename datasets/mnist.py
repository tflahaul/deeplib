# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mnist.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 19:50:33 by thflahau          #+#    #+#              #
#    Updated: 2020/11/06 15:21:09 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

""" Import the MNIST dataset from internet """

from module.Network import Network

def save_file(name, data):
	with open(name, 'wb') as file:
		file.write(data)

def main():
	network = Network('http://yann.lecun.com/exdb/mnist/')
	save_file('mnist_images_train.bin', network.get('train-images-idx3-ubyte.gz', unzip=True))
	save_file('mnist_labels_train.bin', network.get('train-labels-idx1-ubyte.gz', unzip=True))
	save_file('mnist_images_test.bin', network.get('t10k-images-idx3-ubyte.gz', unzip=True))
	save_file('mnist_labels_test.bin', network.get('t10k-labels-idx1-ubyte.gz', unzip=True))

if __name__ == '__main__':
	main()
