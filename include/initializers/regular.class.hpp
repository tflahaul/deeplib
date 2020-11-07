/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:18:30 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 22:55:08 by thflahau         ###   ########.fr       */
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
struct			Regular : public Initializer {
	virtual void	init(struct Matrix &);
	Regular(unsigned int const);
	Regular(void);
};

void			Regular::init(struct Matrix & weights) {
	for (register uint_fast32_t x = 0; x < weights.xdim; ++x)
		for (register uint_fast32_t y = 0; y < weights.ydim; ++y)
			weights.values[x][y] = static_cast<float>(std::rand()) / RAND_MAX;
}

Regular::Regular(unsigned int const seed) {
	std::srand(seed);
}

Regular::Regular(void) {
	std::srand(time(NULL));
}

} /* namespace initializer */

#endif /* __REGULAR_CLASS_HPP__ */
