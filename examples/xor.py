""" Program used to test the framework with the XOR dataset """

import sys
sys.path.append('..')
from deeplib.layers import Dense, Activation
from deeplib.network import Network
from deeplib.optimizers import Adam
import deeplib.regularizers
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
	plt.title('Areas of predictions')
	plt.show()

if __name__ == '__main__':
	model = Network([
		Dense(2, 8, kernel_init='uniform', kernel_constraint=deeplib.regularizers.NonNeg()),
		Activation('tanh'),
		Dense(8, 1, kernel_init='normal', seed=42),
		Activation('sigmoid')
	])
	model.prepare(
		optimizer=Adam(model.layers),
		loss='binary_crossentropy',
		batch_size=4
	)
	model.fit(X, y, patience=50)
	visualize(model)
