/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:31:57 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/12 20:49:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_CLASS_HPP__
#define __LAYER_CLASS_HPP__

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

struct 				Layer {
	vector<float>		units;
	virtual struct Matrix *	get_weights(void) = 0;
	virtual vector<float> * get_biases(void) = 0;
	virtual void		forward(vector<float> &) = 0;
	virtual void		backward(vector<float> &) = 0;
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
