# deeplib
C++ deep learning framework to easily implement different types of neural networks without compromising on performance.

### Examples
Building a simple network,
```cpp
Network          model;

model.add<Input>(Input(512));
model.add<Dense>(Dense(512, 300, "relu"));
model.add<Dropout>(Dropout(300, 0.50));
model.add<Dense>(Dense(300, 6, "softmax"));

model.build<build::Uniform>(); // init all weights with an uniform distribution of values
```
