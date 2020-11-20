/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/12 20:08:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_CLASS_HPP__
#define __DENSE_CLASS_HPP__

#include "../core/activation.class.hpp"
#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"
#include <cstdint>
#include <vector>

using namespace std;

/*!
 * \brief Regular fully-connected neural network layer
 */
template<typename Activation>
class			Dense : virtual public Layer {
private:
	vector<float>	biases;
	vector<float>	bgrads;
	struct Matrix	weights;
	struct Matrix	wgrads;
public:
	vector<float> *	get_biases(void);
	Matrix *	get_weights(void);
	void		forward(vector<float> const &);
	void		backward(vector<float> const &);
	Dense(uint32_t, uint32_t);
};

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

/*!
 * \param in	Number of units of the previous layer
 * \param out	Number of units for the current layer
 */
template<class T> Dense<T>::Dense(uint32_t in, uint32_t out) : Layer(out),
	biases(out), bgrads(out), weights(out, in), wgrads(out, in) {}

#endif /* __DENSE_CLASS_HPP__ */
