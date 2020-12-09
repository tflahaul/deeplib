/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   softmax.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:56:12 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:53:05 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SOFTMAX_CLASS_HPP__
#define __SOFTMAX_CLASS_HPP__

#include "../core/activation_function.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>
#include <cmath>

namespace activation {

struct		softmax : public ActivationFunction {
	void	call(Tensor &) const;
	void	derivative(Tensor &) const;
};

void		softmax::call(Tensor & units) const {
	float	max = units[0], sum = 0.0, offset;
	for (uint_fast32_t idx = 1; idx < units.size(); ++idx)
		if (max < units[idx])
			max = units[idx];
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		sum = sum + expf(units[idx] - max);
	offset = max + log(sum);
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = expf(units[idx] - offset);
}

void		softmax::derivative([[maybe_unused]] Tensor & units) const {}

} /* namespace activation */

#endif /* __SOFTMAX_CLASS_HPP__ */
