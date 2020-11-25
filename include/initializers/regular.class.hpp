/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:18:30 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/25 14:12:24 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REGULAR_CLASS_HPP__
#define __REGULAR_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <ctime>

namespace initializer {

/*!
 * \brief Initialize weights using a regular distribution of values
 */
class		Regular : public Initializer {
public:
	void	init(struct Matrix *, std::vector<float> *);
	Regular(unsigned int const);
	Regular(void);
};

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

#endif /* __REGULAR_CLASS_HPP__ */
