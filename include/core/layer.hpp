/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:28:58 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/27 15:47:56 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include "vector.hpp"
#include <stdint.h>
#include <string>

class				Layer
{
protected:
	struct vector		weights;
	struct vector		output;
public:
	uint64_t		shape(void);
	virtual void		forward(Layer const &);
	virtual void		backward(Layer const &);
	Layer(unsigned int);
	~Layer();
};

void		Layer::forward([[maybe_unused]] Layer const &instance) {}
void		Layer::backward([[maybe_unused]] Layer const &instance) {}

uint64_t	Layer::shape(void) {
	return (this->output.shape);
}

Layer::Layer(unsigned int size) {
	this->output.shape = static_cast<uint64_t>(size);
	this->output.ptr = new float[size];
}

Layer::~Layer() {
	delete this->output.ptr;
}

#endif /* __LAYER_HPP__ */
