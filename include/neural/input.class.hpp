/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 23:13:42 by thflahau         ###   ########.fr       */
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
class			Input : public Layer {
public:
	void		forward(std::vector<float> &);
	void		backward(std::vector<float> &);
	virtual void	describe(std::ostream &) const;
	Input(unsigned int);
};

template<class T> void	Input<T>::forward(std::vector<float> & input) {
	T const		activation;
	this->units = input;
	activation.call(this->units);
}

template<class T> void	Input<T>::backward([[maybe_unused]] std::vector<float> & input) {}

template<class T> void	Input<T>::describe(std::ostream & stream) const {
	T const		activation;
	stream << "type=input, shape=(" << this->units.size() << ")";
	stream << ", normalization=" << activation.name();
}

/*!
 * \param size	Number of units for the input layer
 */
template<class T> Input<T>::Input(unsigned int size) : Layer(size) {}

#endif /* __INPUT_CLASS_HPP__ */
