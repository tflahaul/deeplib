/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:25:03 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/27 20:35:35 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_CLASS_HPP__
#define __ACTIVATION_CLASS_HPP__

#include "matrix.struct.hpp"
#include <string>

namespace activation {

class			Activation {
private:
	std::string	_name;
public:
	virtual void	call(Tensor &) const = 0;
	virtual void	derivative(Tensor &) const = 0;
	std::string	name(void) const;

	Activation(std::string const &);
	~Activation();
};

std::string	Activation::name(void) const {
	return (this->_name);
}

Activation::Activation(std::string const &name) : _name(name) {}
Activation::~Activation() {}

} /* namespace activation */

#endif /* __ACTIVATION_CLASS_HPP__ */
