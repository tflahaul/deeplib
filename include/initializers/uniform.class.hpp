/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:44:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 22:55:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UNIFORM_CLASS_HPP__
#define __UNIFORM_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>
#include <vector>
#include <random>

namespace initializer {

/*!
 * \brief Initialize weights using an uniform distribution of values
 */
struct			Uniform : public Initializer {
private:
	std::mt19937	_generator;
public:
	virtual void	init(struct Matrix &);
	Uniform(unsigned int const);
	Uniform(void);
};

void			Uniform::init(struct Matrix & weights) {
	std::uniform_real_distribution<float> rng(0., 1.);
	for (register uint_fast32_t x = 0; x < weights.xdim; ++x)
		for (register uint_fast32_t y = 0; y < weights.ydim; ++y)
			weights.values[x][y] = rng(this->_generator);
}

Uniform::Uniform(unsigned int const seed) {
	this->_generator.seed(seed);
}

Uniform::Uniform(void) {
	std::random_device	device;
	this->_generator.seed(device());
}

} /* namespace initializer */

#endif /* __UNIFORM_CLASS_HPP__ */
