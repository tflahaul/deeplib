/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:44:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/12 21:13:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UNIFORM_CLASS_HPP__
#define __UNIFORM_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>
#include <vector>
#include <random>

using namespace std;

namespace initializer {

/*!
 * \brief Initialize weights using an uniform distribution of values
 */
class		Uniform : public Initializer {
private:
	mt19937	_generator;
public:
	void	init(struct Matrix *, vector<float> *);
	Uniform(void);
	Uniform(unsigned int const);
};

void		Uniform::init(struct Matrix * weights, vector<float> * biases) {
	uniform_real_distribution<float> rng(-1., 1.);
	if (weights != NULL && biases != NULL) {
		for (uint_fast32_t x = 0; x < weights->xdim; ++x)
			for (uint_fast32_t y = 0; y < weights->ydim; ++y)
				weights->values[x][y] = rng(this->_generator);
		for (uint_fast32_t idx = 0; idx < biases->size(); ++idx)
			(*biases)[idx] = rng(this->_generator);
	}
}

Uniform::Uniform(void) {
	random_device	device;
	this->_generator.seed(device());
}

Uniform::Uniform(unsigned int const seed) {
	this->_generator.seed(seed);
}

} /* namespace initializer */

#endif /* __UNIFORM_CLASS_HPP__ */
