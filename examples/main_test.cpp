#include "../include/core/initializer.class.hpp"
#include "../include/initializers/uniform.class.hpp"
#include "../include/initializers/constant.class.hpp"
#include "../include/initializers/regular.class.hpp"
#include "../include/activations/activation.class.hpp"
#include "../include/network/network.class.hpp"
#include "../include/neural/dense.class.hpp"
#include "../include/neural/input.class.hpp"
#include "../include/neural/dropout.class.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

int			main(void)
{
	class Network	model;

	model.add<Input>(Input(512, "minmax"));
	model.add<Dense>(Dense(512, 300, "relu"));
	model.add<Dropout>(Dropout(300, 0.50));
	model.add<Dense>(Dense(300, 6, "softmax"));
	try {
		model.build<initializer::Uniform>();
	} catch (std::logic_error const & ex) {
		std::cerr << "Error: " << ex.what() << std::endl;
	}
	model.describe();
	return (EXIT_SUCCESS);
}
