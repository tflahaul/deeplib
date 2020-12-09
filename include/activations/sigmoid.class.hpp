/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigmoid.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:52:55 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:53:01 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SIGMOID_CLASS_HPP__
#define __SIGMOID_CLASS_HPP__

#include "../core/activation_function.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>
#include <cmath>

namespace activation {

struct		sigmoid : public ActivationFunction {
	void	call(Tensor &) const;
	void	derivative(Tensor &) const;
	sigmoid(void);
};

void		sigmoid::call(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0 / (1.0 + expf(-(units[idx])));
}

void		sigmoid::derivative(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = units[idx] * (1.0 - units[idx]);
}

} /* namespace activation */

#endif /* __SIGMOID_CLASS_HPP__ */
