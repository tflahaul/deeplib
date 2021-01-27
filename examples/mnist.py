"""
Very simple ANN trained to classify handwritten digits from the MNIST dataset.
The goal here is to showcase what the framework can do, not having the best possible accuracy.
"""

import sys
sys.path.append('..')
from deeplib.network import Network
import deeplib.layers
import deeplib.optimizers
import requests, gzip, struct
import numpy

def get(file : str) -> bytes:
	URL = 'http://yann.lecun.com/exdb/mnist/' + file
	print(f'Fetching data from {URL}...')
	response = requests.get(URL)
	return gzip.decompress(response.content)

def training(X, y, X_valid, y_valid):
	model = Network([
		deeplib.layers.Dense((28 * 28), 128, kernel_init='uniform'),
		deeplib.layers.Activation('tanh'),
		deeplib.layers.Dense(128, 10, kernel_init='regular_scaled'),
		deeplib.layers.Activation('sigmoid')
	])
	model.prepare(
		optimizer=deeplib.optimizers.Adam(model.layers, lr=0.005),
		loss='crossentropy',
		batch_size=256
	)
	model.fit(X, y, X_valid, y_valid, epochs=10, measures=['accuracy'])

def parse_mnist_images(images):
	_, samples = struct.unpack('>ii', images[:8])
	rows, cols = struct.unpack('>ii', images[8:16])
	images = numpy.array([struct.unpack_from('B', images, offset=(16 + off))[0] for off in range(samples * (rows * cols))])
	images = numpy.reshape((images / 255.0), (samples, rows * cols))
	return images

def parse_mnist_labels(labels, to_categorical=True):
	_, samples = struct.unpack('>ii', labels[:8])
	labels = [struct.unpack_from('B', labels, offset=(8 + off))[0] for off in range(samples)]
	if to_categorical is True:
		labels = numpy.eye(10)[labels]
	return labels

if __name__ == '__main__':
	train_images = get('train-images-idx3-ubyte.gz')
	train_labels = get('train-labels-idx1-ubyte.gz')
	test_images = get('t10k-images-idx3-ubyte.gz')
	test_labels = get('t10k-labels-idx1-ubyte.gz')
	train_images = parse_mnist_images(train_images)
	test_images = parse_mnist_images(test_images)
	train_labels = parse_mnist_labels(train_labels)
	test_labels = parse_mnist_labels(test_labels, to_categorical=False)
	training(train_images, train_labels, test_images, test_labels)
