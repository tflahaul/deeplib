#include "../include/neural.hpp"
#include "../include/core.hpp"
#include "../include/activations/activation.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define INPUT_SIZE	5
#define HIDDEN_SIZE	20

int			main(void)
{
	Input		input(INPUT_SIZE, "minmax");
	Dense		hidden(INPUT_SIZE, HIDDEN_SIZE, "tanh");
	Dropout		dropout(HIDDEN_SIZE, 0.2);
	Dense		hidden2(HIDDEN_SIZE, 3, "softmax");

	std::cout << input << std::endl << hidden << std::endl << dropout << std::endl << hidden2 << std::endl;
	std::cout << std::endl;
	input.units[0].value = 6564.1;
	input.units[1].value = 899.7;
	input.units[2].value = -66.3;
	input.units[3].value = 976.0;
	input.units[4].value = 0.987;
	for (unsigned int idx = 0; idx < INPUT_SIZE; ++idx)
		printf("%.2f ", input.units[idx].value);
	std::cout << std::endl;
	input.forward();
	for (unsigned int idx = 0; idx < INPUT_SIZE; ++idx)
		printf("%.2f ", input.units[idx].value);
	std::cout << std::endl;
	hidden.forward(input.units);
	for (unsigned int idx = 0; idx < HIDDEN_SIZE; ++idx)
		printf("%.2f ", hidden.units[idx].value);
	std::cout << std::endl;
	dropout.forward(hidden.units);
	for (unsigned int idx = 0; idx < HIDDEN_SIZE; ++idx)
		printf("%.2f ", dropout.units[idx].value);
	std::cout << std::endl;
	hidden2.forward(dropout.units);
	for (unsigned int idx = 0; idx < 3; ++idx)
		printf("%.2f ", hidden2.units[idx].value);
	std::cout << std::endl;
	return (0);
}
