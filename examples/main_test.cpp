#include "../include/neural.hpp"
#include "../include/core.hpp"
#include "../include/activations/activation.hpp"
#include <iostream>

int			main(void)
{
	Dense		dense(200, "sigmoid");
	Dropout		dropout(200, 0.25);

	std::cout << dense << std::endl << dropout << std::endl;
	return (0);
}
