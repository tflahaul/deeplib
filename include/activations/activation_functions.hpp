/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation_functions.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:21:17 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/30 22:13:39 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_FUNCTIONS_HPP__
#define __ACTIVATION_FUNCTIONS_HPP__

#include "../core/unit.h"
#include <vector>
#include <cmath>

void		linear_activate([[maybe_unused]] std::vector<t_unit> & units) {}

void		sigmoid_activate(std::vector<t_unit> & units) {
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx].value = 1.0 / (1.0 + expf(-units[idx].value));
}

void		relu_activate(std::vector<t_unit> & units) {
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx].value = units[idx].value * (units[idx].value > 0);
}

void		tanh_activate(std::vector<t_unit> & units) {
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx].value = (expf(units[idx].value * 2) - 1) / (expf(units[idx].value * 2) + 1);
}

void		leaky_activate(std::vector<t_unit> & units) {
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		if (units[idx].value > 0)
			units[idx].value = units[idx].value * 0.1;
}

void		softmax_activate(std::vector<t_unit> & units) {
	float	max = units[0].value, sum = 0.0, offset;

	for (register unsigned int idx = 1; idx < units.size(); ++idx)
		if (max < units[idx].value)
			max = units[idx].value;
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		sum = sum + expf(units[idx].value - max);
	offset = max + log(sum);
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx].value = expf(units[idx].value - offset);
}

void		minmax_normalize(std::vector<t_unit> & units) {
	float	max = units[0].value, min = units[0].value;

	for (register unsigned int idx = 0; idx < units.size(); ++idx) {
		if (max < units[idx].value)
			max = units[idx].value;
		if (min > units[idx].value)
			min = units[idx].value;
	}
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx].value = (units[idx].value - min) / (max - min);
}

#endif /* __ACTIVATION_FUNCTIONS_HPP__ */
