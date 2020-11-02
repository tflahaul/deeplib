/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:25:03 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/02 22:06:38 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_HPP__
#define __ACTIVATION_HPP__

#include "./activation_functions.hpp"
#include "../core/unit.h"
#include <string>
#include <vector>
#include <map>

static const std::map<std::string, void (*)(std::vector<t_unit>&)> activations = {
	{"sigmoid", &sigmoid},
	{"softmax", &softmax},
	{"linear", &linear},
	{"leaky", &leaky},
	{"relu", &relu},
	{"tanh", &tanh},
	{"minmax", &minmax}
};

class			Activation
{
private:
	std::string	_name = "linear";
public:
	void		(*call)(std::vector<t_unit> &) = &linear;

	std::string	name(void) const;
	bool		need_vector_input(void) const;

	Activation(void);
	Activation(std::string const &);
	~Activation();
};

std::string	Activation::name(void) const {
	return (this->_name);
}

Activation::Activation(void) {}
Activation::Activation(std::string const &name) : _name(name), call(activations.at(name)) {}
Activation::~Activation() {}

#endif /* __ACTIVATION_HPP__ */
