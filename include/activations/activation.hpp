/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:25:03 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/30 16:57:41 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_HPP__
#define __ACTIVATION_HPP__

#include "./activation_functions.hpp"
#include "../core/unit.hpp"
#include <string>
#include <vector>
#include <map>

static const std::map<std::string, void (*)(std::vector<t_unit> &)> activations = {
	{"softmax", &softmax_activate},
	{"sigmoid", &sigmoid_activate},
	{"linear", &linear_activate},
	{"leaky", &leaky_activate},
	{"relu", &relu_activate},
	{"tanh", &tanh_activate}
};

/*!
 * \brief Generic activation layer class. This particular layer has no weights
 *        since it only applies an activation function to the input.
 */
class			Activation
{
private:
	std::string	_name = "linear";
public:
	void		(*call)(std::vector<t_unit> &) = &linear_activate;
	std::string	get_name(void) const;
	Activation(void);
	Activation(std::string const &);
	~Activation();
};

std::string	Activation::get_name(void) const {
	return (this->_name);
}

Activation::Activation(void) {}
Activation::Activation(std::string const &name) : _name(name), call(activations.at(name)) {}
Activation::~Activation() {}

#endif /* __ACTIVATION_HPP__ */
