/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:01:37 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:03:53 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/activations/linear.class.hpp"
#include <cstdint>
#include <vector>

namespace activation {

void		linear::call([[maybe_unused]] std::vector<float> & units) const {}

void		linear::derivative([[maybe_unused]] std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0;
}

linear::linear(void) : Activation("linear") {}

} /* namespace activation */
