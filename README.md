# deeplib
Deep learning framework written in Python to easily implement different kinds of neural networks.

### How to use
Imports,
```py
from deeplib.network import Network
from deeplib.layers import Dense, Activation, Dropout
from deeplib.loss import BinaryCrossEntropy as BCE
from deeplib.optimizers import AdaGrad
```

Building a simple network,
```py
model = Network([
	Dense(512, 300, init='regular_scaled'),
	Activation('tanh'),
	Dropout(rate=0.5),
	Dense(300, 10, init='uniform', seed=42),
	Activation('sigmoid')
])
```

Training the model,
```py
solver = AdaGrad(lr=0.1, epsilon=1e-7)
model.prepare(optimizer=solver, loss=BCE(), batch_size=16, shuffle=True)
model.fit(X, y, epochs=800, patience=2e-4)
```

### Current capabilities
 - Layers: dense, dropout, activation, normalization
 - Loss functions: MAE, MSE, CE, BCE
 - Activations: linear, sigmoid, tanh, leaky, relu
 - Initializers: regular, regular scaled, uniform
 - Optimizers: SGD, AdaGrad
 - Weight constraints: min-max norm

#### TODO
 - [X] more loss functions (if necessary)
 - [X] more & better optimizers
 - [ ] advanced activations layer
 - [ ] abitily to export the model
 - [ ] convolutional layers
 - [ ] and only then multi-threading & GPU support?
