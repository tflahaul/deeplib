/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropout.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:11:19 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/03 18:13:38 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DROPOUT_CLASS_HPP__
#define __DROPOUT_CLASS_HPP__

#include "../core/unit.struct.h"
#include <iostream>
#include <random>
#include <vector>

/*!
 * \brief Regular dropout neural network layer : applies dropout to the input
 */
class				Dropout : public Layer
{
private:
	float			_rate;
public:
	void			forward(std::vector<t_unit> &);
	void			backward(std::vector<t_unit> &);
	virtual void		describe(std::ostream &) const;

	Dropout(unsigned int, double);
};

/*!
 * \brief	Apply dropout to the input using the Mersenne Twister RNG (mt19937)
 *		to generate evenly distributed numbers
 */
void		Dropout::forward(std::vector<t_unit> & input) {
	std::random_device	dev;
	std::mt19937		generator(dev());
	std::uniform_real_distribution<double>	rng(0.0, 1.0);
	for (register unsigned int idx = 0; idx < this->units.size(); ++idx)
		this->units[idx].value = input[idx].value * (rng(generator) >= this->_rate);
}

void		Dropout::backward([[maybe_unused]] std::vector<t_unit> & input) {}

void		Dropout::describe(std::ostream & stream) const {
	stream << "Layer: type=dropout, shape=(" << this->units.size() << ")";
	stream << ", droprate=" << this->_rate;
}

/*!
 * \param in		Number of units of the previous layer
 * \param rate		Fraction of the input units to drop (between 0 and 1)
 */
Dropout::Dropout(unsigned int in, double rate) : Layer(in) {
	this->_rate = static_cast<float>(std::min(1.0, std::max(0.0, rate)));
}

#endif /* __DROPOUT_CLASS_HPP__ */
