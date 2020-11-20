/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relu.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:42:33 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/09 19:21:51 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RELU_CLASS_HPP__
#define __RELU_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <cstdint>
#include <vector>

namespace activation {

struct		relu : public Activation {
	void	call(std::vector<float> &) const;
	relu(void);
};

void		relu::call(std::vector<float> & units) const {
	for (uint_fast32_t idx = 0; idx < units.size(); ++idx)
		units[idx] = units[idx] * (units[idx] > 0.0);
}

relu::relu(void) : Activation("relu") {}

} /* namespace activation */

#endif /* __RELU_CLASS_HPP__ */
