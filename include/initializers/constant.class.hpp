/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:38:38 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 22:55:15 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONSTANT_CLASS_HPP__
#define __CONSTANT_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>
#include <vector>

namespace initializer {

struct			Constant : public Initializer {
	float		constant = 0.0;
	virtual void	init(struct Matrix &);
	Constant(float const);
};

void			Constant::init(struct Matrix & weights) {
	for (register uint_fast32_t x = 0; x < weights.xdim; ++x)
		for (register uint_fast32_t y = 0; y < weights.ydim; ++y)
			weights.values[x][y] = this->constant;
}

Constant::Constant(float const x) : constant(x) {}

} /* namespace initializer */

#endif /* __CONSTANT_CLASS_HPP__ */
