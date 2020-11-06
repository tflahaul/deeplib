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
	Network		model;

	model.add<Input>(Input(8));
	model.add<Dense>(Dense(8, 16, "relu"));
	model.add<Dropout>(Dropout(16, 0.4));
	model.add<Dense>(Dense(16, 4, "softmax"));
	try {
		model.build<build::Uniform>();
	} catch (std::logic_error const & ex) {
		std::cerr << "Error: " << ex.what() << std::endl;
	}
	model.describe();
	return (EXIT_SUCCESS);
}
