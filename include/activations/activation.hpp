/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:25:03 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/29 11:46:14 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_HPP__
#define __ACTIVATION_HPP__

#include "./activation_functions.h"
#include <string>
#include <vector>
#include <map>

static const std::map<std::string, void (*)(std::vector<float> &)> activations = {
	{"softmax", &softmax_activate},
	{"sigmoid", &sigmoid_activate},
	{"linear", &linear_activate},
	{"leaky", &leaky_activate},
	{"relu", &relu_activate},
	{"tanh", &tanh_activate}
};

/*!
 * \brief Generic activation layer class.
 * This layer has no weights since it only applies an activation function to the input.
 */
class			Activation
{
private:
	std::string	_name = "linear";
public:
	void		(*call)(std::vector<float> &) = &linear_activate;
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
