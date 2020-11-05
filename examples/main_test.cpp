#include "../include/initializers/uniform.class.hpp"
#include "../include/initializers/constant.class.hpp"
#include "../include/initializers/regular.class.hpp"
#include "../include/activations/activation.class.hpp"
#include "../network.hpp"
#include "../neural.hpp"
#include "../core.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

int			main(void)
{
	Network		net(new build::Uniform());

	net.layers.push_back(new Input(512));
	net.layers.push_back(new Dense(512, 2048, "relu"));
	try {
		net.build();
	} catch (std::logic_error const & ex) {
		std::cerr << "Error: " << ex.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
