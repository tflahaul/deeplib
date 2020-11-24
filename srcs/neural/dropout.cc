/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropout.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:32:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:33:40 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/neural/dropout.class.hpp"
#include "../../include/core/matrix.struct.hpp"
#include <random>
#include <vector>

using namespace std;

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

Dropout::Dropout(unsigned int in, double rate) : Layer(in) {
	this->_rate = 1.0 - static_cast<float>(min(1.0, max(0.0, rate)));
}
