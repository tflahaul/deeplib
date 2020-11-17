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

	model.add(new Input<norm_minmax>(2073600));
	model.add(new Dense<relu>(2073600, 500));
	model.add(new Dropout(500, 0.25));
	model.add(new Dense<softmax>(500, 10));

	model.build<initializer::Uniform>();
	return (EXIT_SUCCESS);
}
