/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaky.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:58:20 by thomas            #+#    #+#             */
/*   Updated: 2020/11/24 15:03:14 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/activations/leaky.class.hpp"
#include <cstdint>
#include <vector>

namespace activation {

void		leaky::call(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] > 0.0) ? (units[idx] * 0.1) : (units[idx]);
}

void		leaky::derivative(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] > 0.0) ? 1.0 : 0.1;
}

leaky::leaky(void) : Activation("leaky") {}

} /* namespace activation */
