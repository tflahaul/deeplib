""" Program used to test the Convolution2D layer """

import sys
sys.path.append('..')
import deeplib.layers
import numpy

if __name__ == '__main__':
	inputs = numpy.random.ranf(size=(4, 4)) * 10
	x = deeplib.layers.Convolution2D(2, 2, filters=1, padding=1, init='regular_scaled')
	print('W\n', x.weights)
	print('b\n', x.biases)
	print('inputs\n', inputs)
	print('output\n', x.forward(inputs))
