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

	model.add(new Input<minmax>(512));
	model.add(new Dense<relu>(512, 300));
	model.add(new Dropout(300, 0.50));
	model.add(new Dense<softmax>(300, 6));

	model.build("uniform");
	return (EXIT_SUCCESS);
}
