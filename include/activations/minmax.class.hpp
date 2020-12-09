/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:58:41 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:52:56 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINMAX_CLASS_HPP__
#define __MINMAX_CLASS_HPP__

#include "../core/activation_function.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>

namespace activation {

struct		minmax : public ActivationFunction {
	void	call(Tensor &) const;
	void	derivative(Tensor &) const;
};

void		minmax::call(Tensor & units) const {
	float	max = units[0], min = units[0];
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx) {
		if (max < units[idx])
			max = units[idx];
		if (min > units[idx])
			min = units[idx];
	}
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] - min) / (max - min);
}

void		minmax::derivative([[maybe_unused]] Tensor & units) const {}

} /* namespace activation */

#endif /* __MINMAX_CLASS_HPP__ */
