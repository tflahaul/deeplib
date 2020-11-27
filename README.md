# deeplib
C++ deep learning framework to easily implement different types of neural networks without compromising on performance.

### Examples
Building a simple network,
```cxx
class Network          model;

model.add(new Input<activation::minmax>(512));
model.add(new Dense<activation::tanh>(512, 300));
model.add(new Dropout(300, 0.35));
model.add(new Dense<activation::softmax>(300, 6));

model.build<initializer::Uniform>();
```

### Current capabilities
**Layers**: dense, dropout, activation
**Loss functions**: mean squared error, binary cross-entropy
**Activations**: linear, sigmoid, tanh, leaky, relu, softmax
**Preprocessing**: min-max
**Initializers**: regular, uniform, constant
**Optimizers**: none

#### TODO
 - [X] more & better initializers
 - [X] improve dropout implementation
 - [X] loss functions
 - [ ] optimizers
 - [ ] BATCHES!!!
 - [ ] convolutional layers

and only then multi-threading & GPU support?
