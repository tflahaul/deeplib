/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   softmax.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:56:12 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 22:00:45 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SOFTMAX_CLASS_HPP__
#define __SOFTMAX_CLASS_HPP__

#include "activation.class.hpp"
#include <cstdint>
#include <vector>
#include <cmath>

namespace activation {

struct		softmax : public Activation {
	void	call(std::vector<float> &) const;
	softmax(void);
};

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

softmax::softmax(void) : Activation("softmax") {}

} /* namespace activation */

#endif /* __SOFTMAX_CLASS_HPP__ */
