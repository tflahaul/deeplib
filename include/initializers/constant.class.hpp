/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:38:38 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/06 18:52:57 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONSTANT_CLASS_HPP__
#define __CONSTANT_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include <cstdint>
#include <vector>

namespace initializer {

struct			Constant : public Initializer {
	float		constant;
	virtual void	init(std::vector<float> &);
	Constant(float const);
};

void			Constant::init(std::vector<float> & weights) {
	for (register uint_fast32_t idx = 0; idx < weights.size(); ++idx)
		weights[idx] = this->constant;
}

Constant::Constant(float const x) : constant(x) {}

} /* namespace initializer */

#endif /* __CONSTANT_CLASS_HPP__ */
