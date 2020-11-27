/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/27 20:47:06 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_CLASS_HPP__
#define __INPUT_CLASS_HPP__

#include "../core/activation.class.hpp"
#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"

template<class Activation>
struct			Input : virtual public Layer {
	Matrix *	get_weights(void);
	Tensor *	get_biases(void);
	void		forward(Tensor const &);
	void		backward(Tensor const &);
	Input(unsigned int);
};

template<class T> Tensor * Input<T>::get_biases(void) {
	return (NULL);
}

template<class T> Matrix * Input<T>::get_weights(void) {
	return (NULL);
}

template<class T> void	Input<T>::forward(Tensor const & input) {
	this->units = input;
	T().call(this->units);
}

template<class T> void	Input<T>::backward([[maybe_unused]] Tensor const & input) {}

/*!
 * \param size	Number of units for the input layer
 */
template<class T>	Input<T>::Input(unsigned int size) : Layer(size) {}

#endif /* __INPUT_CLASS_HPP__ */
