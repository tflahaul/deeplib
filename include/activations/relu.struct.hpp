/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relu.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:42:33 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 21:47:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RELU_CLASS_HPP__
#define __RELU_CLASS_HPP__

#include "activation.class.hpp"
#include <cstdint>
#include <vector>

namespace activation {

struct		ReLU : public Activation {
	void	call(std::vector<float> &) const;
	ReLU(void);
};

void		ReLU::call(std::vector<float> & units) const {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = units[idx] * (units[idx] > 0.0);
}

ReLU::ReLU(void) : Activation("ReLU") {}

} /* namespace activation */

#endif /* __RELU_CLASS_HPP__ */
