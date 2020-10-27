#include "../include/neural.hpp"
#include "../include/core.hpp"
#include "../include/activations/activations.h"
#include <iostream>

int			main(void)
{
	Dense		dense(200, &relu_activate);
	Dropout		dropout(200, 0.25);

	std::cout << dense << std::endl << dropout << std::endl;
	return (0);
}
