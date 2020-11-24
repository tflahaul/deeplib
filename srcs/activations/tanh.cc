/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tanh.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:11:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:12:04 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/activations/tanh.class.hpp"
#include <cstdint>
#include <vector>
#include <cmath>

namespace activation {

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
