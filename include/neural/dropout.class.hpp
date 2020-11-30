/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropout.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:11:19 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/27 20:46:27 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DROPOUT_CLASS_HPP__
#define __DROPOUT_CLASS_HPP__

#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"
#include <cstdint>
#include <random>

using namespace std;

/*!
 * \brief Regular dropout NN layer : applies dropout to the input
 */
class			Dropout : virtual public Layer {
private:
	double		_rate;
public:
	Tensor *	get_biases(void);
	Matrix *	get_weights(void);
	void		forward(Tensor const &);
	void		backward(Tensor const &);
	Dropout(unsigned int, double);
};

Matrix *	Dropout::get_weights(void) {
	return (NULL);
}

Tensor *	Dropout::get_biases(void) {
	return (NULL);
}

void		Dropout::forward(Tensor const & input) {
	random_device		dev;
	mt19937			generator(dev());
	bernoulli_distribution	rng(this->_rate);
	for (uint_fast32_t idx = 0; idx < this->units.size(); ++idx)
		this->units[idx] = input[idx] * rng(generator) * (1.0 / this->_rate);
}

void		Dropout::backward([[maybe_unused]] Tensor const & input) {}

Dropout::Dropout(unsigned int in, double rate) : Layer(in) {
	this->_rate = 1.0 - min(1.0, max(0.0, rate));
}

#endif /* __DROPOUT_CLASS_HPP__ */
