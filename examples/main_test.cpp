#include "../include/initializers.hpp"
#include "../include/activations.hpp"
#include "../include/optimizers.hpp"
#include "../include/network.hpp"
#include "../include/neural.hpp"
#include "../include/core.hpp"
#include "../include/loss.hpp"
#include <cstdio>
#include <vector>

int			main(void)
{
	class Network	model;

	model.add(new Input<activation::minmax>(5));
	model.add(new Dense<activation::tanh>(5, 10));
	model.add(new Dropout(10, 0.25));
	model.add(new Dense<activation::tanh>(10, 8));
	model.add(new Dense<activation::sigmoid>(8, 1));

	model.build<initializer::Uniform>();

	std::vector<float> X = {2.4, 7.8, -7.0, 4.11, 0.567};
	std::vector<float> y = {0.0};
	auto output = model.feed(X);

	printf("loss=%.3f\n", loss::BCE().error(output, y));
	return (EXIT_SUCCESS);
}
