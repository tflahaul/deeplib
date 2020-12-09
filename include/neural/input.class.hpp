/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:54:23 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_CLASS_HPP__
#define __INPUT_CLASS_HPP__

#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"

struct		Input : virtual public Layer {
	Matrix *get_weights(void);
	Tensor *get_biases(void);
	void	forward(Tensor const &);
	void	backward(Tensor const &);
	Input(unsigned int);
};

Tensor *	Input::get_biases(void) {
	return (NULL);
}

Matrix *	Input::get_weights(void) {
	return (NULL);
}

void		Input::forward(Tensor const & input) {
	this->units = input;
}

void		Input::backward([[maybe_unused]] Tensor const & input) {}

Input::Input(unsigned int size) : Layer(size) {}

#endif /* __INPUT_CLASS_HPP__ */
