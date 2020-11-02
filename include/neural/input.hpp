/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/02 22:24:16 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include "../core.hpp"
#include "../activations/activation.hpp"
#include <iostream>
#include <string>
#include <vector>

/*!
 * \brief Regular input layer
 */
class			Input : public Layer
{
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

void		Input::forward([[maybe_unused]] std::vector<t_unit> &) {
	this->_activation.call(this->units);
}

void		Input::backward([[maybe_unused]] std::vector<t_unit> &) {}

void		Input::describe(std::ostream & stream) const {
	stream << "Layer: type=input, shape=(" << this->units.size() << ")";
	stream << ", normalization=" << this->_activation.name();
}

/*!
 * \param size	Number of units for the input layer
 */
Input::Input(unsigned int size) : Layer(size), _activation("linear") {}

/*!
 * \param size	Number of units for the input layer
 * \param name	Normalization function to use
 */
Input::Input(unsigned int size, std::string const &name) : Layer(size), _activation(name) {}
Input::~Input() {}

#endif /* __INPUT_HPP__ */
