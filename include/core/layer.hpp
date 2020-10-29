/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:28:58 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/29 11:05:41 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include <cstdint>
#include <string>
#include <vector>

/*!
 * \brief Base layer class.
 */
class				Layer
{
protected:
	std::vector<float>	weights;
	std::vector<float>	output;
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
	return (this->output.size());
}

Layer::Layer(unsigned int size) {
	this->output.resize(size);
}

Layer::~Layer() {}

#endif /* __LAYER_HPP__ */
