#include "../include/neural.hpp"
#include "../include/core.hpp"
#include "../include/activations/activation.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define INPUT_SIZE	4
#define HIDDEN_SIZE	16

int			main(void)
{
	Input		input(INPUT_SIZE, "minmax");
	Dense		hidden(INPUT_SIZE, HIDDEN_SIZE, "relu");
	Dropout		dropout(HIDDEN_SIZE, 0.25);
	Dense		hidden2(HIDDEN_SIZE, 3, "softmax");

	srand(time(0));
	std::cout << input << std::endl << hidden << std::endl << dropout << std::endl << hidden2 << std::endl;
	std::cout << std::endl;
	input.units[0].value = 65.87;
	input.units[1].value = 58.7;
	input.units[2].value = 0.87;
	input.units[3].value = -5.87;
	for (unsigned int idx = 0; idx < input.units.size(); ++idx)
		printf("%.3f ", input.units[idx].value);
	std::cout << std::endl;
	input.forward();
	for (unsigned int idx = 0; idx < input.units.size(); ++idx)
		printf("%.3f ", input.units[idx].value);
	std::cout << std::endl;
	hidden.forward(input.units);
	for (unsigned int idx = 0; idx < hidden.units.size(); ++idx)
		printf("%.3f ", hidden.units[idx].value);
	std::cout << std::endl;
	dropout.forward(hidden.units);
	for (unsigned int idx = 0; idx < dropout.units.size(); ++idx)
		printf("%.3f ", dropout.units[idx].value);
	std::cout << std::endl;
	hidden2.forward(dropout.units);
	for (unsigned int idx = 0; idx < hidden2.units.size(); ++idx)
		printf("%.3f ", hidden2.units[idx].value);
	std::cout << std::endl;
	return (0);
}
