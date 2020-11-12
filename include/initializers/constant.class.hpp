/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:38:38 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/12 21:01:38 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONSTANT_CLASS_HPP__
#define __CONSTANT_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>
#include <vector>

using namespace std;

namespace initializer {

class		Constant : public Initializer {
private:
	float	_constant = 0.0;
public:
	void	init(Matrix *, vector<float> *);
	Constant(float const);
};

void		Constant::init(Matrix * weights, vector<float> * biases) {
	if (weights != NULL) {
		for (register uint_fast32_t x = 0; x < weights->xdim; ++x)
			for (register uint_fast32_t y = 0; y < weights->ydim; ++y)
				weights->values[x][y] = this->_constant;
	}
	if (biases != NULL) {
		for (register uint_fast32_t idx = 0; idx < biases->size(); ++idx)
			(*biases)[idx] = this->_constant;
	}
}

Constant::Constant(float const x) : _constant(x) {}

} /* namespace initializer */

#endif /* __CONSTANT_CLASS_HPP__ */
