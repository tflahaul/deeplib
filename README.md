# deeplib
C++ deep learning framework to easily implement different types of neural networks without compromising on performance.

### Examples
Building a simple network,
```cpp
class Network          model;

model.add<Input>(Input(512, "minmax"));
model.add<Dense>(Dense(512, 300, "relu"));
model.add<Dropout>(Dropout(300, 0.50));
model.add<Dense>(Dense(300, 6, "softmax"));

model.build<initializer::Uniform>();
```
The describe method will output informations on the network,
```cpp
model.describe();
```
```bash
Layer -> type=input, shape=(512), normalization=minmax
Layer -> type=dense, shape=(512,300), activation=relu
Layer -> type=dropout, shape=(300), droprate=0.5
Layer -> type=dense, shape=(300,6), activation=softmax
```

TODO:
 - more & better initializers
 - improve dropout implementation
 - convolutional layers
 - loss functions
 - optimizers
 - BATCHES!!!
 - and only then multi-threading & GPU support?
