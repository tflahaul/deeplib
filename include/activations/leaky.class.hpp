/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaky.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:49:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/27 20:32:50 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEAKY_CLASS_HPP__
#define __LEAKY_CLASS_HPP__

#include "../core/activation.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>

namespace activation {

struct		leaky : public Activation {
	void	call(Tensor &) const;
	void	derivative(Tensor &) const;
	leaky(void);
};

void		leaky::call(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] > 0.0) ? (units[idx] * 0.1) : (units[idx]);
}

void		leaky::derivative(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] > 0.0) ? 1.0 : 0.1;
}

leaky::leaky(void) : Activation("leaky") {}

} /* namespace activation */

#endif /* __LEAKY_CLASS_HPP__ */

