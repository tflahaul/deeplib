/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   softmax.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:09:15 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:10:15 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/activations/softmax.class.hpp"
#include <cstdint>
#include <vector>
#include <cmath>

namespace activation {

void		softmax::call(std::vector<float> & units) const {
	float	max = units[0], sum = 0.0, offset;
	for (uint_fast32_t idx = 1; idx < units.size(); ++idx)
		if (max < units[idx])
			max = units[idx];
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		sum = sum + expf(units[idx] - max);
	offset = max + log(sum);
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = expf(units[idx] - offset);
}

void		softmax::derivative([[maybe_unused]] std::vector<float> & units) const {}

softmax::softmax(void) : Activation("softmax") {}

} /* namespace activation */