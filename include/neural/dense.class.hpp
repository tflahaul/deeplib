/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 23:10:19 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_CLASS_HPP__
#define __DENSE_CLASS_HPP__

#include "../activations/activation.class.hpp"
#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

/*!
 * \brief Regular fully-connected neural network layer
 */
template<class Activation>
class				Dense : public Layer {
private:
	std::vector<float>	_bias;
public:
	struct Matrix		weights;
	void			forward(std::vector<float> &);
	void			backward(std::vector<float> &);
	virtual void		describe(std::ostream &) const;
	Dense(uint32_t, uint32_t);
};

template<class T> void	Dense<T>::forward(std::vector<float> & input) {
	T const		activation;
	for (register uint_fast32_t x = 0; x < this->weights.xdim; ++x) {
		this->units[x] = this->_bias[x];
		for (register uint_fast32_t y = 0; y < this->weights.ydim; ++y)
			this->units[x] += input[y] * this->weights.values[x][y];
	}
	activation.call(this->units);
}

template<class T> void	Dense<T>::backward([[maybe_unused]] std::vector<float> & input) {}

template<class T> void	Dense<T>::describe(std::ostream & stream) const {
	T const		activation;
	stream << "type=dense, shape=(" << this->weights.xdim << "," << this->weights.ydim;
	stream << "), activation=" << activation.name();
}

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 */
template<class T> Dense<T>::Dense(uint32_t in, uint32_t out) : Layer(out, true), weights(out, in) {}

#endif /* __DENSE_CLASS_HPP__ */
