/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:16:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:23:31 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initializers/regular.class.hpp"
#include "../../include/core/matrix.struct.hpp"
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <ctime>

namespace initializer {

void		Regular::init(struct Matrix * weights, std::vector<float> * biases) {
	if (weights != NULL && biases != NULL) {
		for (uint_fast32_t x = 0; x < weights->xdim; ++x)
			for (uint_fast32_t y = 0; y < weights->ydim; ++y)
				weights->values[x][y] = static_cast<float>(rand()) / RAND_MAX;
		for (uint_fast32_t idx = 0; idx < biases->size(); ++idx)
			(*biases)[idx] = static_cast<float>(rand()) / (RAND_MAX / 2) - 1.0;
	}
}

Regular::Regular(unsigned int const seed) {
	srand(seed);
}

Regular::Regular(void) {
	srand(time(NULL));
}

} /* namespace initializer */
