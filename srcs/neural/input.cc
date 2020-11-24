/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:34:49 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:35:58 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/neural/input.class.hpp"
#include "../../include/core/matrix.struct.hpp"
#include <vector>

using namespace std;

template<class T> vector<float> * Input<T>::get_biases(void) {
	return (NULL);
}

template<class T> Matrix * Input<T>::get_weights(void) {
	return (NULL);
}

template<class T> void	Input<T>::forward(vector<float> const & input) {
	this->units = input;
	T().call(this->units);
}

template<class T> void	Input<T>::backward([[maybe_unused]] vector<float> const & input) {}

/*!
 * \param size	Number of units for the input layer
 */
template<class T> Input<T>::Input(unsigned int size) : Layer(size) {}
