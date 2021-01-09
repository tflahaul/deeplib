# deeplib
Lightweight deep learning framework to easily implement different kinds of neural networks.

### How to use
Building a simple network,
```py
from deeplib.network import Network
from deeplib.layers import Dense, Activation, Dropout
from deeplib.loss import BinaryCrossEntropy as BCE
from deeplib.optimizers import RMSprop

model = Network()
model.add(Dense(512, 300, init='regular_scaled'))
model.add(Activation('tanh'))
model.add(Dropout(rate=0.4))
model.add(Dense(300, 100, init='uniform', seed=42))
model.add(Activation('tanh'))
model.add(Dense(100, 3, init='normal'))
model.add(Activation('sigmoid'))
```

Training the model,
```py
solver = RMSprop(model.layers, lr=0.005)
model.prepare(solver, BCE(), batch_size=32, shuffle=True)
model.fit(X, y, epochs=800, patience=12)
```

### Current capabilities
 - Layers: dense, dropout, activation
 - Loss functions: MAE, MSE, CE, BCE
 - Activations: linear, sigmoid, tanh, leaky, relu
 - Initializers: regular, regular scaled, uniform, normal
 - Optimizers: SGD, AdaGrad, RMSprop, Adam
 - Weight constraints: non neg
 - Regularizers: early stopping

#### TODO
 - [X] adam optimizer
 - [ ] implement k-fold cross validation
 - [ ] max norm & min-max norm weight constraints
 - [ ] advanced activations layer
 - [ ] ability to export and load models
 - [ ] convolutional and pooling layers
 - [ ] GPU support?
