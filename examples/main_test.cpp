#include "../include/initializers.hpp"
#include "../include/activations.hpp"
#include "../include/network.hpp"
#include "../include/neural.hpp"
#include "../include/core.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace activation;

int			main(void)
{
	class Network	model;

	model.add(Input<minmax>(512));
	model.add(Dense<ReLU>(512, 300));
	model.add(Dropout(300, 0.50));
	model.add(Dense<softmax>(300, 6));

	model.build<initializer::Uniform>();

	model.describe();
	return (EXIT_SUCCESS);
}
