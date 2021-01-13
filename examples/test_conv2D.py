""" Program used to test the Convolution2D layer """

import sys
sys.path.append('..')
from deeplib.layers import Convolution2D
import numpy

if __name__ == '__main__':
	inputs = numpy.random.ranf(size=(10, 10))
	x = Convolution2D(2, 2, filters=5, padding=1, init='regular_scaled')
	print('W', x.weights)
	print('b', x.biases)
	print('output', x.forward(inputs))
