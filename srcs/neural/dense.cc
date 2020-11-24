/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:30:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:32:04 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/neural/dense.class.hpp"
#include "../../include/core/matrix.struct.hpp"
#include <cstdint>
#include <vector>

using namespace std;

template<class T> vector<float> * Dense<T>::get_biases(void) {
	return (&(this->biases));
}

template<class T> Matrix * Dense<T>::get_weights(void) {
	return (&(this->weights));
}

template<class T> void	Dense<T>::forward(vector<float> const & input) {
	static T const activation;
	for (uint_fast32_t x = 0; x < this->weights.xdim; ++x) {
		this->units[x] = this->biases[x];
		for (uint_fast32_t y = 0; y < this->weights.ydim; ++y)
			this->units[x] += input[y] * this->weights.values[x][y];
	}
	activation.call(this->units);
}

template<class T> void	Dense<T>::backward([[maybe_unused]] vector<float> const & grads) {}

template<class T> Dense<T>::Dense(uint32_t in, uint32_t out) : Layer(out),
	biases(out), bgrads(out), weights(out, in), wgrads(out, in) {}
