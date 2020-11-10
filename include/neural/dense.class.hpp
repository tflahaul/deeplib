/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/09 20:01:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_CLASS_HPP__
#define __DENSE_CLASS_HPP__

#include "../activations/activation.class.hpp"
#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"
#include <cstdint>
#include <vector>

/*!
 * \brief Regular fully-connected neural network layer
 */
template<typename Activation>
struct				Dense : virtual public Layer {
	std::vector<float>	biases;
	std::vector<float>	bgrad;
	struct Matrix		weights;
	struct Matrix		wgrad;
	void			forward(std::vector<float> &);
	void			backward(std::vector<float> &);
	Dense(uint32_t, uint32_t);
};

template<class T> void	Dense<T>::forward(std::vector<float> & input) {
	T const		activation;
	for (register uint_fast32_t x = 0; x < this->weights.xdim; ++x) {
		this->units[x] = this->biases[x];
		for (register uint_fast32_t y = 0; y < this->weights.ydim; ++y)
			this->units[x] += input[y] * this->weights.values[x][y];
	}
	activation.call(this->units);
}

template<class T> void	Dense<T>::backward([[maybe_unused]] std::vector<float> & input) {}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 */
template<class T> Dense<T>::Dense(uint32_t in, uint32_t out) : Layer(out, true),
	biases(out), bgrad(out),
	weights(out, in), wgrad(out, in) {}

#endif /* __DENSE_CLASS_HPP__ */
