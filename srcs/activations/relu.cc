/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relu.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:06:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:07:13 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/activations/relu.class.hpp"
#include <cstdint>
#include <vector>

namespace activation {

void		relu::call(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = units[idx] * (units[idx] > 0.0);
}

void		relu::derivative(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] > 0.0);
}

relu::relu(void) : Activation("relu") {}

} /* namespace activation */
