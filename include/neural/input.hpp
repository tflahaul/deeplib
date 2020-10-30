/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/30 22:14:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include "../core/unit.h"
#include "../activations/activation.hpp"
#include <iostream>
#include <string>
#include <vector>

/*!
 * \brief Regular input layer
 */
class				Input
{
private:
	Activation		_activation;
public:
	std::vector<t_unit>	units;

	friend std::ostream&	operator<<(std::ostream &, Input &);
	void			forward(void);

	Input(unsigned int);
	Input(unsigned int, std::string const &);
	~Input();
};

void		Input::forward(void) {
	this->_activation.call(this->units);
}

std::ostream&	operator<<(std::ostream & stream, Input & instance) {
	stream << "Layer: type=input, shape=(" << instance.units.size() << ")";
	stream << ", normalization=" << instance._activation.get_name();
	return (stream);
}

/*!
 * \param size	Number of units for the input layer
 */
Input::Input(unsigned int size) : _activation("linear"), units(size) {}

/*!
 * \param size	Number of units for the input layer
 * \param name	Normalization function to use
 */
Input::Input(unsigned int size, std::string const &name) : _activation(name), units(size) {}

Input::~Input() {}

#endif /* __INPUT_HPP__ */
