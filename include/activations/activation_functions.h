/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:21:17 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/29 11:27:40 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_FUNCTIONS_HPP__
#define __ACTIVATION_FUNCTIONS_HPP__

#include <vector>
#include <cmath>

void		linear_activate([[maybe_unused]] std::vector<float> & units) {}

void		sigmoid_activate(std::vector<float> & units) {
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0 / (1.0 + expf(-units[idx]));
}

void		relu_activate(std::vector<float> & units) {
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx] = units[idx] * (units[idx] > 0);
}

void		tanh_activate(std::vector<float> & units) {
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx] = (expf(units[idx] * 2) - 1) / (expf(units[idx] * 2) + 1);
}

void		leaky_activate(std::vector<float> & units) {
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		if (units[idx] > 0)
			units[idx] = units[idx] * 0.1;
}

void		softmax_activate(std::vector<float> & units) {
	float	max = units[0], sum = 0.0, offset;

	for (register unsigned int idx = 1; idx < units.size(); ++idx)
		if (max < units[idx])
			max = units[idx];
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		sum = sum + expf(units[idx] - max);
	offset = max + log(sum);
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx] = expf(units[idx] - offset);
}

#endif /* __ACTIVATION_FUNCTIONS_HPP__ */
