/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropout.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:11:19 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/12 20:09:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DROPOUT_CLASS_HPP__
#define __DROPOUT_CLASS_HPP__

#include "../core/layer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <random>
#include <vector>

using namespace std;

/*!
 * \brief Regular dropout NN layer : applies dropout to the input
 */
class			Dropout : virtual public Layer {
private:
	float		_rate;
public:
	vector<float> *	get_biases(void);
	Matrix *	get_weights(void);
	void		forward(vector<float> const &);
	void		backward(vector<float> const &);
	Dropout(unsigned int, double);
};

Matrix *	Dropout::get_weights(void) {
	return (NULL);
}

vector<float> *	Dropout::get_biases(void) {
	return (NULL);
}

void		Dropout::forward(vector<float> const & input) {
	random_device		dev;
	mt19937			generator(dev());
	bernoulli_distribution	rng(this->_rate);
	for (uint_fast32_t idx = 0; idx < this->units.size(); ++idx)
		this->units[idx] = input[idx] * rng(generator) * (1.0 / this->_rate);
}

void		Dropout::backward([[maybe_unused]] vector<float> const & input) {}

/*!
 * \param in	Number of units of the previous layer
 * \param rate	Fraction of the input units TO DROP (between 0.0 and 1.0)
 */
Dropout::Dropout(unsigned int in, double rate) : Layer(in) {
	this->_rate = 1.0 - static_cast<float>(min(1.0, max(0.0, rate)));
}

#endif /* __DROPOUT_CLASS_HPP__ */
