/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/06 15:33:35 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_CLASS_HPP__
#define __INPUT_CLASS_HPP__

#include "../activations/activation.class.hpp"
#include "../core/layer.class.hpp"
#include "../core/unit.struct.h"
#include <iostream>
#include <string>
#include <vector>

/*!
 * \brief Regular input layer
 */
class			Input : public Layer {
private:
	Activation	_activation;
public:
	void		forward(std::vector<t_unit> &);
	void		backward(std::vector<t_unit> &);
	virtual void	describe(std::ostream &) const;

	Input(unsigned int);
	Input(unsigned int, std::string const &);
	~Input();
};

void		Input::forward(std::vector<t_unit> & input) {
	this->units = input;
	this->_activation.call(this->units);
}

void		Input::backward([[maybe_unused]] std::vector<t_unit> & input) {}

void		Input::describe(std::ostream & stream) const {
	stream << "Layer: type=input, shape=(" << this->units.size() << ")";
	stream << ", normalization=" << this->_activation.name();
}

/*!
 * \param size	Number of units for the input layer
 */
Input::Input(unsigned int size) : Layer(size, INPUT), _activation("linear") {}

/*!
 * \param size	Number of units for the input layer
 * \param name	Normalization function to use
 */
Input::Input(unsigned int size, std::string const &name) : Layer(size, INPUT), _activation(name) {}
Input::~Input() {}

#endif /* __INPUT_CLASS_HPP__ */
