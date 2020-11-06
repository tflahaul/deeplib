/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation_functions.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:21:17 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/06 19:18:06 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_FUNCTIONS_HPP__
#define __ACTIVATION_FUNCTIONS_HPP__

#include <cstdint>
#include <vector>
#include <cmath>

#define __sigmoid(x)	(1.0 / (1.0 + expf(-(x))))
#define __leaky(x)	((x) > 0.0 ? (x) * 0.1 : (x))
#define __tanh(x)	((expf((x) * 2) - 1) / (expf((x) * 2) + 1))
#define __relu(x)	((x) * ((x) > 0.0))

void			linear([[maybe_unused]] std::vector<float> & units) {}

void			sigmoid(std::vector<float> & units) {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = __sigmoid(units[idx]);
}

void			relu(std::vector<float> & units) {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = __relu(units[idx]);
}

void			leaky(std::vector<float> & units) {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = __leaky(units[idx]);
}

void			tanh(std::vector<float> & units) {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = __tanh(units[idx]);
}

void			softmax(std::vector<float> & units) {
	float		max = units[0], sum = 0.0, offset;

	for (register unsigned int idx = 1; idx < units.size(); ++idx)
		if (max < units[idx])
			max = units[idx];
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		sum = sum + expf(units[idx] - max);
	offset = max + log(sum);
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx] = expf(units[idx] - offset);
}

void			minmax(std::vector<float> & units) {
	float		max = units[0], min = units[0];

	for (register unsigned int idx = 0; idx < units.size(); ++idx) {
		if (max < units[idx])
			max = units[idx];
		if (min > units[idx])
			min = units[idx];
	}
	for (register unsigned int idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] - min) / (max - min);
}

#endif /* __ACTIVATION_FUNCTIONS_HPP__ */
