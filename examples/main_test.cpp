#include "../include/activations/activation.class.hpp"
#include "../include/network.hpp"
#include "../include/neural.hpp"
#include "../include/core.hpp"

int			main(void)
{
	Network		network;

	network._layers.push_back(new Input(8, "minmax"));
	network._layers.push_back(new Dense(8, 16, "relu"));
	network._layers.push_back(new Dropout(16, 0.25));
	network._layers.push_back(new Dense(16, 4, "softmax"));
	network.describe();
	return (0);
}
