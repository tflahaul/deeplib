""" Very simple ANN trained to classify handwritten digits from the MNIST dataset """

import sys
sys.path.append('..')
from deeplib.network import Network
import deeplib.layers
import deeplib.optimizers
import requests, gzip, struct
import numpy

def get(file : str) -> bytes:
	URL = 'http://yann.lecun.com/exdb/mnist/'
	print(f'Fetching data from {URL + file}...')
	response = requests.get(URL + file)
	return gzip.decompress(response.content)

def fit_model(X, y):
	model = Network([
		deeplib.layers.Dense((28 * 28), 128, kernel_init='uniform'),
		deeplib.layers.Activation('tanh'),
		deeplib.layers.Dense(128, 10, kernel_init='regular_scaled'),
		deeplib.layers.Activation('sigmoid')
	])
	model.prepare(
		optimizer=deeplib.optimizers.Adam(model.layers, lr=0.005),
		loss='crossentropy',
		batch_size=600
	)
	model.fit(X, y, epochs=16)
	return model

if __name__ == '__main__':
	train_images = get('train-images-idx3-ubyte.gz')
	train_labels = get('train-labels-idx1-ubyte.gz')
	magic, samples = struct.unpack('>ii', train_images[:8])
	rows, cols = struct.unpack('>ii', train_images[8:16])
	train_images = numpy.array([struct.unpack_from('B', train_images, offset=(16 + off))[0] for off in range(samples * (rows * cols))], dtype=float)
	train_images = numpy.reshape((train_images / 255.0), (samples, rows * cols))
	train_labels = [struct.unpack_from('B', train_labels, offset=(8 + off))[0] for off in range(samples)]
	train_labels = numpy.eye(10)[train_labels]
	model = fit_model(train_images, train_labels)

	test_images = get('t10k-images-idx3-ubyte.gz')
	test_labels = get('t10k-labels-idx1-ubyte.gz')
	magic, samples = struct.unpack('>ii', test_images[:8])
	rows, cols = struct.unpack('>ii', test_images[8:16])
	test_images = numpy.array([struct.unpack_from('B', test_images, offset=(16 + off))[0] for off in range(samples * (rows * cols))], dtype=float)
	test_images = numpy.reshape((test_images / 255.0), (samples, rows * cols))
	test_labels = [struct.unpack_from('B', test_labels, offset=(8 + off))[0] for off in range(samples)]
	h = model.predict(test_images)
	print('Validation accuracy=' + str((numpy.argmax(h, axis=-1) == test_labels).mean()))
