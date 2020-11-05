/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:38:38 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/05 15:46:00 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONSTANT_CLASS_HPP__
#define __CONSTANT_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include <cstdint>
#include <vector>

namespace build {

class			Constant : public Initializer {
private:
	float		_value;
public:
	virtual void	init(std::vector<float> &);
	Constant(float const);
	~Constant();
};

void			Constant::init(std::vector<float> & weights) {
	for (register uint_fast32_t idx = 0; idx < weights.size(); ++idx)
		weights[idx] = this->_value;
}

Constant::Constant(float const x) : _value(x) {}
Constant::~Constant() {}

} /* namespace build */

#endif /* __CONSTANT_CLASS_HPP__ */
