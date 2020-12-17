# deeplib
Python deep learning framework to easily implement different types of neural networks.

### Examples
Building a simple network,
```py
model = Network([
	Dense(512, 300, init='uniform'),
	Activation('tanh'),
	Dropout(rate=0.5),
	Dense(300, 10, init='regular_scaled', seed=42),
	Activation('sigmoid')
])
```

Training the model,
```py
solver = SGD(lr=0.1, regularizer='max_norm')
model.prepare(optimizer=solver, loss=BinaryCrossEntropy(), batch_size=10)
model.fit(X, y, epochs=800, patience=2e-4)
```

### Current capabilities
 - Layers: dense, dropout, activation, normalization
 - Loss functions: MAE, MSE, BCE
 - Activations: linear, sigmoid, tanh, leaky, relu
 - Initializers: regular, uniform, regular_scaled
 - Optimizers: SGD
 - Regularizers/Constraints: max norm, early stopping

#### TODO
 - [X] make max norm & future regularizers more modular
 - [ ] advanced activations layer
 - [X] more loss functions (if necessary)
 - [ ] can export model
 - [ ] more & better optimizers
 - [ ] convolutional layers
 - [ ] and only then multi-threading & GPU support?
