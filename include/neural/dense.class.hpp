/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:54:00 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_CLASS_HPP__
#define __DENSE_CLASS_HPP__

#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"
#include <cstdint>

using namespace std;

class			Dense : virtual public Layer {
private:
	Tensor		biases;
	Tensor		bgrads;
	Matrix		weights;
	Matrix		wgrads;
public:
	Tensor *	get_biases(void);
	Matrix *	get_weights(void);
	void		forward(Tensor const &);
	void		backward(Tensor const &);
	Dense(uint32_t, uint32_t);
};

Tensor *		Dense::get_biases(void) {
	return (&(this->biases));
}

Matrix *		Dense::get_weights(void) {
	return (&(this->weights));
}

void			Dense::forward(Tensor const & input) {
	for (uint_fast32_t x = 0; x < this->weights.xdim; ++x) {
		this->units[x] = this->biases[x];
		for (uint_fast32_t y = 0; y < this->weights.ydim; ++y)
			this->units[x] += input[y] * this->weights.values[x][y];
	}
}

void			Dense::backward([[maybe_unused]] Tensor const & grads) {}

Dense::Dense(uint32_t in, uint32_t out) : Layer(out),
	biases(out), bgrads(out), weights(out, in), wgrads(out, in) {}

#endif /* __DENSE_CLASS_HPP__ */
