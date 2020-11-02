/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation_functions.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:21:17 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/02 22:38:15 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_FUNCTIONS_HPP__
#define __ACTIVATION_FUNCTIONS_HPP__

#include "../core/unit.struct.h"
#include <cstdint>
#include <vector>
#include <cmath>

#define __sigmoid(x)	(1.0 / (1.0 + expf(-(x))))
#define __leaky(x)	((x) > 0.0 ? (x) * 0.1 : (x))
#define __tanh(x)	((expf((x) * 2) - 1) / (expf((x) * 2) + 1))
#define __relu(x)	((x) * ((x) > 0.0))

void			linear([[maybe_unused]] std::vector<t_unit> & units) {}

void			sigmoid(std::vector<t_unit> & units) {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx].value = __sigmoid(units[idx].value);
}

void			relu(std::vector<t_unit> & units) {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx].value = __relu(units[idx].value);
}

void			leaky(std::vector<t_unit> & units) {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx].value = __leaky(units[idx].value);
}

void			tanh(std::vector<t_unit> & units) {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx].value = __tanh(units[idx].value);
}

void			softmax(std::vector<t_unit> & units) {
	float		max = units[0].value, sum = 0.0, offset;

	for (register unsigned int idx = 1; idx < units.size(); ++idx)
		if (max < units[idx].value)
			max = units[idx].value;
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		sum = sum + expf(units[idx].value - max);
	offset = max + log(sum);
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx].value = expf(units[idx].value - offset);
}

void			minmax(std::vector<t_unit> & units) {
	float		max = units[0].value, min = units[0].value;

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
