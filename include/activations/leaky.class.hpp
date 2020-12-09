/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaky.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:49:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:53:10 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEAKY_CLASS_HPP__
#define __LEAKY_CLASS_HPP__

#include "../core/activation_function.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>

namespace activation {

struct		leaky : public ActivationFunction {
	void	call(Tensor &) const;
	void	derivative(Tensor &) const;
};

void		leaky::call(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] > 0.0) ? (units[idx] * 0.1) : (units[idx]);
}

void		leaky::derivative(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] > 0.0) ? 1.0 : 0.1;
}

} /* namespace activation */

#endif /* __LEAKY_CLASS_HPP__ */

