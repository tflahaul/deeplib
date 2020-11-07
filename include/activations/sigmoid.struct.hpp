/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigmoid.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:52:55 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 21:55:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SIGMOID_CLASS_HPP__
#define __SIGMOID_CLASS_HPP__

#include "activation.class.hpp"
#include <cstdint>
#include <vector>
#include <cmath>

namespace activation {

struct		sigmoid : public Activation {
	void	call(std::vector<float> &) const;
	sigmoid(void);
};

void		sigmoid::call(std::vector<float> & units) const {
	for (register uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = 1.0 / (1.0 + expf(-(units[idx])));
}

sigmoid::sigmoid(void) : Activation("sigmoid") {}

} /* namespace activation */

#endif /* __SIGMOID_CLASS_HPP__ */
