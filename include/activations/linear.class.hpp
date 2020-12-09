/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:52:16 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:53:14 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LINEAR_CLASS_HPP__
#define __LINEAR_CLASS_HPP__

#include "../core/activation_function.class.hpp"
#include "../core/matrix.struct.hpp"
#include <cstdint>

namespace activation {

struct		linear : public ActivationFunction {
	void	call(Tensor &) const;
	void	derivative(Tensor &) const;
};

void		linear::call([[maybe_unused]] Tensor & units) const {}

void		linear::derivative(Tensor & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0;
}

} /* namespace activation */

#endif /* __LINEAR_CLASS_HPP__ */
