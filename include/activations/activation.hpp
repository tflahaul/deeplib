/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:25:03 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/28 23:30:15 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_HPP__
#define __ACTIVATION_HPP__

#include "./activation_functions.h"
#include "../core/vector.hpp"
#include <iostream>
#include <string>
#include <map>

static const std::map<std::string, void (*)(struct vector const *)> activations = {
	{"softmax", &softmax_activate},
	{"sigmoid", &sigmoid_activate},
	{"linear", &linear_activate},
	{"leaky", &leaky_activate},
	{"relu", &relu_activate},
	{"tanh", &tanh_activate}
};

class			Activation
{
private:
	std::string	_name = "linear";
public:
	void		(*call)(struct vector const *) = &linear_activate;
	std::string	get_name(void);
	Activation(void);
	Activation(std::string const &);
	~Activation();
};

std::string	Activation::get_name(void) {
	return (this->_name);
}

Activation::Activation(void) {}
Activation::Activation(std::string const &name) : call(activations.at(name)), _name(name) {}
Activation::~Activation() {}

#endif /* __ACTIVATION_HPP__ */
