#include "../include/neural/neural.hpp"
#include <iostream>

int			main(void)
{
	Dense		dense(200);
	Dropout		dropout(200, 0.25);

	std::cout << dense << std::endl << dropout << std::endl;
	return (0);
}
