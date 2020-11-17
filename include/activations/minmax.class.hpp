/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:58:41 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 22:00:19 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINMAX_CLASS_HPP__
#define __MINMAX_CLASS_HPP__

#include "activation.class.hpp"
#include <cstdint>
#include <vector>

namespace activation {

struct		norm_minmax : public Activation {
	void	call(std::vector<float> &) const;
	norm_minmax(void);
};

void		norm_minmax::call(std::vector<float> & units) const {
	float	max = units[0], min = units[0];

	for (uint_fast32_t idx = 0; idx < units.size(); ++idx) {
		if (max < units[idx])
			max = units[idx];
		if (min > units[idx])
			min = units[idx];
	}
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = (units[idx] - min) / (max - min);
}

norm_minmax::norm_minmax(void) : Activation("minmax") {}

} /* namespace activation */

#endif /* __MINMAX_CLASS_HPP__ */
