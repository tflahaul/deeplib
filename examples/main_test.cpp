#include "../include/activations/activation.class.hpp"
#include "../include/network.hpp"
#include "../include/neural.hpp"
#include "../include/core.hpp"
#include <iostream>
#include <vector>

#define INPUT_SIZE	5
#define HIDDEN_SIZE	10

int			main(void)
{
	Network		network;

	network._layers.push_back(new Input(INPUT_SIZE, "minmax"));
	network._layers.push_back(new Dense(INPUT_SIZE, HIDDEN_SIZE, "sigmoid"));
	network._layers.push_back(new Dropout(HIDDEN_SIZE, 0.2));
	network._layers.push_back(new Dense(HIDDEN_SIZE, 4, "softmax"));

	network.describe();
	std::cout << std::endl;

	std::vector<t_unit>	input(INPUT_SIZE);
	for (unsigned int idx = 0; idx < INPUT_SIZE; ++idx)
		input[idx].value = static_cast<float>(idx);
	std::cout << std::endl;
	network.fit(input);
	return (0);
}
