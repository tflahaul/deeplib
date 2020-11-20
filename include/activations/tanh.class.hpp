/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tanh.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:54:46 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 21:58:51 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TANH_CLASS_HPP__
#define __TANH_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <cstdint>
#include <vector>
#include <cmath>

namespace activation {

struct		tanh : public Activation {
	void	call(std::vector<float> &) const;
	void	derivative(std::vector<float> &) const;
	tanh(void);
};

void		tanh::call(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (expf((units[idx]) * 2) - 1) / (expf((units[idx]) * 2) + 1);
}

void		tanh::derivative(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0 - units[idx] * units[idx];
}

tanh::tanh(void) : Activation("tanh") {}

} /* namespace activation */

#endif /* __TANH_CLASS_HPP__ */
