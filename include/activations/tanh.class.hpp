/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tanh.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:54:46 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:53:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TANH_CLASS_HPP__
#define __TANH_CLASS_HPP__

#include "../core/activation_function.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>
#include <cmath>

namespace activation {

struct		tanh : public ActivationFunction {
	void	call(Tensor &) const;
	void	derivative(Tensor &) const;
};

void		tanh::call(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (expf((units[idx]) * 2.0) - 1.0) / (expf((units[idx]) * 2.0) + 1.0);
}

void		tanh::derivative(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0 - (units[idx] * units[idx]);
}

} /* namespace activation */

#endif /* __TANH_CLASS_HPP__ */
