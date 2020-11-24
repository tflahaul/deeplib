/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:20:56 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:53:52 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initializers/constant.class.hpp"
#include "../../include/core/matrix.struct.hpp"
#include <cstdint>
#include <vector>

namespace initializer {

void		Constant::init(struct Matrix * weights, std::vector<float> * biases) {
	if (weights != NULL && biases != NULL) {
		for (uint_fast32_t x = 0; x < weights->xdim; ++x)
			for (uint_fast32_t y = 0; y < weights->ydim; ++y)
				weights->values[x][y] = this->_constant;
		for (uint_fast32_t idx = 0; idx < biases->size(); ++idx)
			(*biases)[idx] = this->_constant;
	}
}

Constant::Constant(float const x) : _constant(x) {}

} /* namespace initializer */
