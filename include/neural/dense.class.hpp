/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/04 22:57:45 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_CLASS_HPP__
#define __DENSE_CLASS_HPP__

#include "../activations/activation.class.hpp"
#include "../core.hpp"
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

/*!
 * \brief Regular fully-connected neural network layer
 */
class				Dense : public Layer
{
private:
	Activation		_activation;
public:
	std::vector<float>	weights;

	void			forward(std::vector<t_unit> &);
	void			backward(std::vector<t_unit> &);
	virtual void		describe(std::ostream &) const;

	Dense(uint32_t, uint32_t);
	Dense(uint32_t, uint32_t, std::string const &);
};

void		Dense::forward(std::vector<t_unit> & input) {
	for (register uint_fast32_t x = 0; x < this->units.size(); ++x) {
		for (register uint_fast32_t y = 0; y < input.size(); ++y)
			this->units[x].value += input[y].value * this->weights[x + y];
		this->units[x].value += this->units[x].bias;
	}
	this->_activation.call(this->units);
}

void		Dense::backward([[maybe_unused]] std::vector<t_unit> & input) {}

void		Dense::describe(std::ostream & stream) const {
	stream << "Layer: type=dense, shape=(" << this->weights.size() / this->units.size();
	stream << "," << this->units.size() << "), activation=" << this->_activation.name();
}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 */
Dense::Dense(uint32_t in, uint32_t out) : Layer(out, DENSE), _activation("linear"), weights(in * out) {}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 * \param name	Activation function to use
 */
Dense::Dense(uint32_t in, uint32_t out, std::string const &name) : Layer(out, DENSE), _activation(name), weights(in * out) {}

#endif /* __DENSE_CLASS_HPP__ */
