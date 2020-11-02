/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/01 18:26:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_HPP__
#define __DENSE_HPP__

#include "../core.hpp"
#include "../activations/activation.hpp"
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

/*!
 * \brief Regular densely-connected neural network layer
 */
class				Dense : public Layer
{
private:
	Activation		_activation;
public:
	void			forward(std::vector<t_unit> &);
	void			backward(std::vector<t_unit> &);
	friend std::ostream&	operator<<(std::ostream &, Dense &);

	Dense(uint32_t, uint32_t);
	Dense(uint32_t, uint32_t, std::string const &);
};

void		Dense::forward(std::vector<t_unit> & output) {
	for (register uint_fast32_t x = 0; x < this->units.size(); ++x) {
		for (register uint_fast32_t y = 0; y < output.size(); ++y)
			this->units[x].value += output[y].value * this->weights[x + y];
		this->units[x].value += this->units[x].bias;
	}
	this->_activation.call(this->units);
}

void		Dense::backward([[maybe_unused]] std::vector<t_unit> & output) {}

std::ostream&	operator<<(std::ostream & stream, Dense & instance) {
	stream << "Layer: type=dense, shape=(" << std::get<0>(instance.shape());
	stream << "," << std::get<1>(instance.shape()) << ")";
	stream << ", activation=" << instance._activation.get_name();
	return (stream);
}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 */
Dense::Dense(uint32_t in, uint32_t out) : Layer(in, out), _activation("linear") {}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 * \param name	Activation function to use
 */
Dense::Dense(uint32_t in, uint32_t out, std::string const &name) : Layer(in, out), _activation(name) {}

#endif /* __DENSE_HPP__ */
