/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:04:37 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:05:45 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/activations/minmax.class.hpp"
#include <cstdint>
#include <vector>

namespace activation {

void		minmax::call(std::vector<float> & units) const {
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

void		minmax::derivative([[maybe_unused]] std::vector<float> & units) const {}

minmax::minmax(void) : Activation("minmax") {}

} /* namespace activation */
