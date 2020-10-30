/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/30 18:24:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_HPP__
#define __DENSE_HPP__

#include "../core.hpp"
#include "../activations/activation.hpp"
#include <iostream>
#include <string>

/*!
 * \brief Regular densely-connected neural network layer
 */
class				Dense : public Layer
{
private:
	Activation		_activation;
public:
	void			forward(Layer const &);
	void			backward(Layer const &);
	friend std::ostream&	operator<<(std::ostream &, Dense &);

	Dense(unsigned int, unsigned int);
	Dense(unsigned int, unsigned int, std::string const &);
};

void		Dense::forward(Layer const &instance) {
	for (register unsigned int idx = 0; idx < this->units.size(); ++idx) {
		for (unsigned int x = 0; x < instance.units.size(); ++x)
			this->units[idx].value += instance.units[x].value * this->weights[idx + x];
		this->units[idx].value += this->units[idx].bias;
	}
	this->_activation.call(this->units);
}
void		Dense::backward([[maybe_unused]] Layer const &instance) {}

std::ostream&	operator<<(std::ostream &stream, Dense &instance) {
	stream << "Layer: type=dense, shape=(" << std::get<0>(instance.shape());
	stream << "," << std::get<1>(instance.shape()) << ")";
	stream << ", activation=" << instance._activation.get_name();
	return (stream);
}

/*!
 * \param prev	Number of units of the previous layer
 * \param size	Number of units for the current layer
 */
Dense::Dense(unsigned int prev, unsigned int size) : Layer(prev, size), _activation(Activation("linear")) {}

/*!
 * \param prev	Number of units of the previous layer
 * \param size	Number of units for the current layer
 * \param name	Activation function to use
 */
Dense::Dense(unsigned int prev, unsigned int size, std::string const &name) : Layer(prev, size), _activation(name) {}

#endif /* __DENSE_HPP__ */
