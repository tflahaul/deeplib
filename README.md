# deeplib
Python deep learning framework to easily implement different types of neural networks.

### Examples
Building a simple network,
```py
model = Network([
	Dense(512, 300, init='uniform'),
	Activation('tanh'),
	Dropout(rate=0.5),
	Dense(300, 10, init='regular', seed=42),
	Activation('sigmoid')])
```

Training the model,
```py
opti = SGD(lr=0.1, max_norm=True)
model.prepare(optimizer=opti, loss=BinaryCrossEntropy(), batch_size=10)
model.fit(X, y)
```

### Current capabilities
 - Layers: dense, dropout, activation, normalization
 - Loss functions: MAE, MSE, BCE
 - Activations: linear, sigmoid, tanh, leaky, relu
 - Initializers: regular, uniform
 - Optimizers: SGD
 - Regularizers/Constraints: max norm, early stopping

#### TODO
 - [ ] make max norm & future regularizers more modular
 - [ ] advanced activations layer
 - [ ] more loss functions (if necessary)
 - [ ] more & better optimizers
 - [ ] convolutional layers
 - [ ] and only then multi-threading & GPU support?
