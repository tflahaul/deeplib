/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/12 20:11:11 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_CLASS_HPP__
#define __INPUT_CLASS_HPP__

#include "../activations/activation.class.hpp"
#include "../core/layer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <string>
#include <vector>

using namespace std;

/*!
 * \brief Regular input layer
 */
template<class Activation>
struct			Input : virtual public Layer {
	Matrix *	get_weights(void);
	vector<float> *	get_biases(void);
	void		forward(vector<float> &);
	void		backward(vector<float> &);
	Input(unsigned int);
};

template<class T> vector<float> * Input<T>::get_biases(void) {
	return (NULL);
}

template<class T> Matrix * Input<T>::get_weights(void) {
	return (NULL);
}

template<class T> void	Input<T>::forward(vector<float> & input) {
	T const		activation;
	this->units = input;
	activation.call(this->units);
}

template<class T> void	Input<T>::backward([[maybe_unused]] vector<float> & input) {}

/*!
 * \param size	Number of units for the input layer
 */
template<class T> Input<T>::Input(unsigned int size) : Layer(size) {}

#endif /* __INPUT_CLASS_HPP__ */
