/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/03 15:35:01 by thflahau         ###   ########.fr       */
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
	std::vector<float>	_weights;
	Activation		_activation;

	void			_init(uint32_t const, uint32_t const);
public:
	void			forward(std::vector<t_unit> &);
	void			backward(std::vector<t_unit> &);
	virtual void		describe(std::ostream &) const;

	Dense(uint32_t, uint32_t);
	Dense(uint32_t, uint32_t, std::string const &);
};

void		Dense::forward(std::vector<t_unit> & output) {
	for (register uint_fast32_t x = 0; x < this->units.size(); ++x) {
		for (register uint_fast32_t y = 0; y < output.size(); ++y)
			this->units[x].value += output[y].value * this->_weights[x + y];
		this->units[x].value += this->units[x].bias;
	}
	this->_activation.call(this->units);
}

void		Dense::backward([[maybe_unused]] std::vector<t_unit> & output) {}

void		Dense::describe(std::ostream & stream) const {
	stream << "Layer: type=dense, shape=(" << this->_weights.size() / this->units.size();
	stream << "," << this->units.size() << "), activation=" << this->_activation.name();
}

void		Dense::_init(uint32_t const in, uint32_t const out) {
	for (register uint_fast32_t idx = 0; idx < in * out; ++idx)
		this->_weights[idx] = (static_cast<float>(std::rand()) / RAND_MAX) - 0.5;
	for (register uint_fast32_t idx = 0; idx < out; ++idx)
		this->units[idx].bias = static_cast<float>(std::rand()) / RAND_MAX;
}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 */
Dense::Dense(uint32_t in, uint32_t out) : Layer(out), _weights(in * out), _activation("linear") {
	this->_init(in, out);
}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 * \param name	Activation function to use
 */
Dense::Dense(uint32_t in, uint32_t out, std::string const &name) : Layer(out), _weights(in * out), _activation(name) {
	this->_init(in, out);
}

#endif /* __DENSE_CLASS_HPP__ */
