/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:38:38 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/09 18:58:17 by thflahau         ###   ########.fr       */
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

struct			Constant : public Initializer {
	float		constant = 0.0;
	virtual void	init(struct Matrix &, vector<float> &);
	Constant(float const);
};

void			Constant::init(struct Matrix & weights, vector<float> & biases) {
	for (register uint_fast32_t x = 0; x < weights.xdim; ++x)
		for (register uint_fast32_t y = 0; y < weights.ydim; ++y)
			weights.values[x][y] = this->constant;
	for (register uint_fast32_t idx = 0; idx < biases.size(); ++idx)
		biases[idx] = this->constant;
}

Constant::Constant(float const x) : constant(x) {}

} /* namespace initializer */

#endif /* __CONSTANT_CLASS_HPP__ */
