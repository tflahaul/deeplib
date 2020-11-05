/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:44:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/05 15:45:23 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UNIFORM_CLASS_HPP__
#define __UNIFORM_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include <cstdint>
#include <vector>
#include <random>

namespace build {

/*!
 * \brief Initialize weights with uniform distribution of values using the
 *	  Mersenne Twister Engine
 */
class			Uniform : public Initializer {
private:
	std::mt19937	_generator;
public:
	virtual void	init(std::vector<float> &);
	Uniform(unsigned int const);
	Uniform(void);
	~Uniform();
};

void			Uniform::init(std::vector<float> & weights) {
	std::uniform_real_distribution<float>	rng(0.0, 1.0);
	for (register uint_fast32_t idx = 0; idx < weights.size(); ++idx)
		weights[idx] = rng(this->_generator);
}

Uniform::Uniform(unsigned int const seed) {
	this->_generator.seed(seed);
}

Uniform::Uniform(void) {
	std::random_device	device;
	this->_generator.seed(device());
}

Uniform::~Uniform() {}

} /* namespace build */

#endif /* __UNIFORM_CLASS_HPP__ */
