/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activations.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:16:06 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/27 15:29:18 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATIONS_H__
#define __ACTIVATIONS_H__

extern "C" {

#include "../core/vector.hpp"
#include <stdint.h>
#include <math.h>

void		softmax_activate(struct vector const *output) {
	float	max = output->ptr[0], sum = 0.0, offset;

	for (register unsigned int idx = 1; idx < output->shape; ++idx)
		if (max < output->ptr[idx])
			max = output->ptr[idx];
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		sum = sum + expf(output->ptr[idx] - max);
	offset = max + log(sum);
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		output->ptr[idx] = expf(output->ptr[idx] - offset);
}

void		sigmoid_activate(struct vector const *output) {
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		output->ptr[idx] = 1.0 / (1.0 + std::exp(-output->ptr[idx]));
}

void		linear_activate(__attribute__((unused)) struct vector const *output) {}

void		leaky_activate(struct vector const *output) {
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		if (output->ptr[idx] > 0)
			output->ptr[idx] = output->ptr[idx] * 0.1;
}

void		relu_activate(struct vector const *output) {
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		output->ptr[idx] = output->ptr[idx] * (output->ptr[idx] > 0);
}

void		tanh_activate(struct vector const *output) {
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		output->ptr[idx] = (expf(output->ptr[idx] * 2) - 1) / (expf(output->ptr[idx] * 2) + 1);
}

} /* extern C */

#endif /* __ACTIVATIONS_H__ */
