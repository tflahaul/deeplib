/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:31:57 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:53:39 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_CLASS_HPP__
#define __LAYER_CLASS_HPP__

#include "matrix.struct.hpp"
#include <cstdint>

using namespace std;

struct 				Layer {
	Tensor			units;

	virtual Matrix *	get_weights(void) = 0;
	virtual Tensor *	get_biases(void) = 0;
	virtual void		forward(Tensor const &) = 0;
	virtual void		backward(Tensor const &) = 0;
	Layer(uint32_t const);
	Layer(uint32_t const, bool const);
	virtual ~Layer();
};

/*!
 * \param size	Number of units for the current layer
 */
Layer::Layer(uint32_t const size) : units(size) {}
Layer::~Layer() {}

#endif /* __LAYER_CLASS_HPP__ */
