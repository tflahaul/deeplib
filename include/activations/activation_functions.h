/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:21:17 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/28 23:23:34 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_FUNCTIONS_H__
#define __ACTIVATION_FUNCTIONS_H__

extern "C" {

#include "../core/vector.hpp"
#include <math.h>

void		linear_activate(__attribute__((unused)) struct vector const *output) {}

void		sigmoid_activate(struct vector const *output) {
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		output->ptr[idx] = 1.0 / (1.0 + expf(-output->ptr[idx]));
}

void		relu_activate(struct vector const *output) {
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		output->ptr[idx] = output->ptr[idx] * (output->ptr[idx] > 0);
}

void		tanh_activate(struct vector const *output) {
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		output->ptr[idx] = (expf(output->ptr[idx] * 2) - 1) / (expf(output->ptr[idx] * 2) + 1);
}

void		leaky_activate(struct vector const *output) {
	for (register unsigned int idx = 0; idx < output->shape; ++idx)
		if (output->ptr[idx] > 0)
			output->ptr[idx] = output->ptr[idx] * 0.1;
}

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

} /* extern C */

#endif /* __ACTIVATION_FUNCTIONS_H__ */
