/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropout.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:11:19 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/01 18:26:43 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DROPOUT_HPP__
#define __DROPOUT_HPP__

#include "../core/unit.h"
#include <iostream>
#include <random>
#include <vector>

/*!
 * \brief Regular dropout neural network layer : applies dropout to the input
 */
class				Dropout
{
private:
	float			_rate;
public:
	std::vector<t_unit>	units;

	void			forward(std::vector<t_unit> &);
	void			backward(std::vector<t_unit> &);
	friend std::ostream&	operator<<(std::ostream &, Dropout &);

	Dropout(unsigned int, double);
};

void		Dropout::forward(std::vector<t_unit> & output) {
	std::random_device dev;
	std::mt19937 generator(dev());
	std::uniform_real_distribution<double>	rng(0.0, 1.0);
	for (register unsigned int idx = 0; idx < this->units.size(); ++idx)
		this->units[idx].value = output[idx].value * (rng(generator) >= this->_rate);
}

void		Dropout::backward([[maybe_unused]] std::vector<t_unit> & output) {}

std::ostream&	operator<<(std::ostream & stream, Dropout & instance) {
	stream << "Layer: type=dropout, shape=(" << instance.units.size() << ")";
	stream << ", droprate=" << instance._rate;
	return (stream);
}

/*!
 * \param in		Number of units of the previous layer
 * \param rate		Fraction of the input units to drop (between 0 and 1)
 */
Dropout::Dropout(unsigned int in, double rate) : units(in) {
	this->_rate = static_cast<float>(std::min(1.0, std::max(0.0, rate)));
}

#endif /* __DROPOUT_HPP__ */
