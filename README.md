# deeplib
C++ deep learning framework to easily implement different types of neural networks without compromising on performance.

### Examples
Building a simple network,
```cpp
class Network          model;

model.add(new Input<norm_minmax>(512));
model.add(new Dense<relu>(512, 300));
model.add(new Dropout(300, 0.50));
model.add(new Dense<softmax>(300, 6));

model.build<initializer::Uniform>();
```

TODO:
 - [X] more & better initializers
 - [ ] improve dropout implementation
 - [ ] convolutional layers
 - [ ] loss functions
 - [ ] optimizers
 - [ ] BATCHES!!!

and only then multi-threading & GPU support?
