/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:52:16 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/27 20:33:10 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LINEAR_CLASS_HPP__
#define __LINEAR_CLASS_HPP__

#include "../core/activation.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>

namespace activation {

struct		linear : public Activation {
	void	call(Tensor &) const;
	void	derivative(Tensor &) const;
	linear(void);
};

void		linear::call([[maybe_unused]] Tensor & units) const {}

void		linear::derivative([[maybe_unused]] Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0;
}

linear::linear(void) : Activation("linear") {}

} /* namespace activation */

#endif /* __LINEAR_CLASS_HPP__ */
