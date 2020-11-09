/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/09 19:02:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_CLASS_HPP__
#define __INPUT_CLASS_HPP__

#include "../activations/activation.class.hpp"
#include "../core/layer.class.hpp"
#include <iostream>
#include <string>
#include <vector>

/*!
 * \brief Regular input layer
 */
template<class Activation>
struct			Input : virtual public Layer {
	void		forward(std::vector<float> &);
	void		backward(std::vector<float> &);
	Input(unsigned int);
};

template<class T> void	Input<T>::forward(std::vector<float> & input) {
	T const		activation;
	this->units = input;
	activation.call(this->units);
}

template<class T> void	Input<T>::backward([[maybe_unused]] std::vector<float> & input) {}

/*!
 * \param size	Number of units for the input layer
 */
template<class T> Input<T>::Input(unsigned int size) : Layer(size) {}

#endif /* __INPUT_CLASS_HPP__ */
