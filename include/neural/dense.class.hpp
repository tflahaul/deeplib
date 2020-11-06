/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/06 19:19:58 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_CLASS_HPP__
#define __DENSE_CLASS_HPP__

#include "../activations/activation.class.hpp"
#include "../core/layer.class.hpp"
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

/*!
 * \brief Regular fully-connected neural network layer
 */
class				Dense : public Layer {
private:
	float			_bias = static_cast<float>(rand()) / RAND_MAX;
	Activation		_activation;
public:
	std::vector<float>	weights;

	void			forward(std::vector<float> &);
	void			backward(std::vector<float> &);
	virtual void		describe(std::ostream &) const;

	Dense(uint32_t, uint32_t);
	Dense(uint32_t, uint32_t, std::string const &);
};

void		Dense::forward(std::vector<float> & input) {
	for (register uint_fast32_t x = 0; x < this->units.size(); ++x) {
		for (register uint_fast32_t y = 0; y < input.size(); ++y)
			this->units[x] += input[y] * this->weights[x + y];
		this->units[x] = this->units[x] + this->_bias;
	}
	this->_activation.call(this->units);
}

void		Dense::backward([[maybe_unused]] std::vector<float> & input) {}

void		Dense::describe(std::ostream & stream) const {
	stream << "type=dense, shape=(" << this->weights.size() / this->units.size();
	stream << "," << this->units.size() << "), activation=" << this->_activation.name();
}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 */
Dense::Dense(uint32_t in, uint32_t out) : Layer(out, true), _activation("linear"), weights(in * out) {}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 * \param name	Activation function to use
 */
Dense::Dense(uint32_t in, uint32_t out, std::string const &name) : Layer(out, true), _activation(name), weights(in * out) {}

#endif /* __DENSE_CLASS_HPP__ */
