#include "../include/neural.hpp"
#include "../include/core.hpp"
#include "../include/activations/activation.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define INPUT_SIZE	4
#define HIDDEN_SIZE	20

int			main(void)
{
	Dense		input(1, INPUT_SIZE);
	Dense		hidden(INPUT_SIZE, HIDDEN_SIZE, "tanh");
	Dropout		dropout(HIDDEN_SIZE, 0.2);

	srand(time(0));
	std::cout << input << std::endl << hidden << std::endl << dropout << std::endl << std::endl;
	input.units[0].value = 0.29;
	input.units[1].value = 0.5;
	input.units[2].value = -0.7;
	input.units[3].value = 0.12;
	hidden.forward(input);
	std::cout << "After feed forwarding: ";
	for (unsigned int idx = 0; idx < HIDDEN_SIZE; ++idx)
		printf("%.2f ", hidden.units[idx].value);
	std::cout << std::endl;
	dropout.forward(hidden);
	std::cout << "After dropout: ";
	for (unsigned int idx = 0; idx < HIDDEN_SIZE; ++idx)
		printf("%.2f ", dropout.units[idx]);
	std::cout << std::endl;
	return (0);
}
