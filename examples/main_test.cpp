#include "../include/initializers.hpp"
#include "../include/activations.hpp"
#include "../include/network.hpp"
#include "../include/neural.hpp"
#include "../include/core.hpp"
#include <cstdio>
#include <vector>

static inline void	print_vector(vector<float> const & v) {
	for (unsigned int index = 0; index < v.size(); ++index)
		printf("%.3f\n", v[index]);
}

int			main(void)
{
	class Network	model;

	model.add(new Input<activation::minmax>(5));
	model.add(new Dense<activation::tanh>(5, 10));
	model.add(new Dropout(10, 0.25));
	model.add(new Dense<activation::softmax>(10, 4));

	model.build<initializer::Regular>();

	std::vector<float> X = {2.4, 7.8, -7.0, 4.11, 0.567};
	print_vector(model.feed(X));
	return (EXIT_SUCCESS);
}
