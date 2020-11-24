/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigmoid.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:07:54 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:08:58 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/activations/sigmoid.class.hpp"
#include <cstdint>
#include <vector>
#include <cmath>

namespace activation {

void		sigmoid::call(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0 / (1.0 + expf(-(units[idx])));
}

void		sigmoid::derivative(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (1.0 - units[idx]) * units[idx];
}

sigmoid::sigmoid(void) : Activation("sigmoid") {}

} /* namespace activation */
