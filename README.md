# deeplib
Lightweight deep learning framework to easily implement different kinds of neural networks.

### How to use
Building a simple network,
```py
from deeplib.network import Network
import deeplib.optimizers
import deeplib.layers

model = Network([
	deeplib.layers.Dense(784, 128, kernel_init='regular_scaled'),
	deeplib.layers.Activation('elu'),
	deeplib.layers.Dropout(0.25),
	deeplib.layers.Dense(128, 10, kernel_init='uniform', seed=42),
	deeplib.layers.Activation('sigmoid')
])
```

Training the model,
```py
model.prepare(
	optimizer=deeplib.optimizers.Adam(model.layers, lr=0.005),
	loss='binary_crossentropy',
	batch_size=300
)
model.fit(X, y)
```

### Current capabilities
 - Layers: dense, dropout, activation, flatten
 - Loss functions: mean absolute error, mean squared error, (binary) cross entropy
 - Activations: linear, sigmoid, tanh, leaky, relu, elu, softmax
 - Initializers: regular, regular scaled, uniform, he uniform, normal, he normal
 - Optimizers: SGD, AdaGrad, RMSprop, Adam
 - Weight constraints: non neg
 - Regularizers: early stopping

#### TODO
 - [X] adam optimizer
 - [ ] implement k-fold cross validation
 - [ ] max norm & min-max norm weight constraints
 - [X] ability to export and load models
 - [ ] convolutional and pooling layers
 - [ ] GPU support?
