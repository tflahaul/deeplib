/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropout.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:11:19 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/29 11:45:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DROPOUT_HPP__
#define __DROPOUT_HPP__

#include "../core/layer.hpp"
#include <iostream>

/*!
 * \brief Regular dropout neural network layer : applies dropout to its input.
 */
class				Dropout : public Layer
{
private:
	double			_rate;
public:
	void			forward(Layer const &);
	void			backward(Layer const &);
	friend std::ostream&	operator<<(std::ostream &, Dropout &);
	Dropout(unsigned int const, double const);
};

void		Dropout::forward([[maybe_unused]] Layer const &instance) {}
void		Dropout::backward([[maybe_unused]] Layer const &instance) {}

std::ostream&	operator<<(std::ostream &stream, Dropout &instance) {
	stream << "Layer: type=dropout, shape=" << instance.shape();
	stream << ", droprate=" << instance._rate;
	return (stream);
}

/*!
 * \param shape		Output size of the layer.
 * \param rate		Fraction of the input units to drop.
 */
Dropout::Dropout(unsigned int const shape, double const rate) : Layer(shape) {
	this->_rate = std::min(1., std::max(0., rate));
}

#endif /* __DROPOUT_HPP__ */
