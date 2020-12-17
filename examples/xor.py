""" Program used to test the framework with the XOR dataset """

import sys
sys.path.append('..')
from deeplib.layers import Dense, Activation
from deeplib.network import Network
from deeplib.loss import BinaryCrossEntropy as BCE
from deeplib.optimizers import SGD
import matplotlib.pyplot as plt
import numpy as np

X = np.array([
	[0.0, 0.0],
	[0.0, 1.0],
	[1.0, 0.0],
	[1.0, 1.0]])

y = np.array([
	[0.0],
	[1.0],
	[1.0],
	[0.0]])

def visualize(model):
	array = np.zeros(shape=(100, 100))
	for x in range(100):
		for y in range(100):
			array[x][y] = model.predict(np.array([x * 0.01, y * 0.01]))
	plt.imshow(array, interpolation='nearest')
	plt.show()

if __name__ == '__main__':
	model = Network([
		Dense(in_size=2, out_size=4, init='uniform'),
		Activation('tanh'),
		Dense(in_size=4, out_size=1, init='regular_scaled'),
		Activation('sigmoid')])
	solver = SGD(lr=0.1)
	model.prepare(optimizer=solver, loss=BCE(), batch_size=4)
	model.fit(X, y)
	visualize(model)
