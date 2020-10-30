/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:31:57 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/30 22:23:27 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include "unit.h"
#include <cstdint>
#include <vector>
#include <tuple>

class				Layer
{
protected:
	std::vector<float>	weights;
public:
	std::vector<t_unit>	units;

	std::tuple<uint, uint>	shape(void);
	virtual void		forward(std::vector<t_unit> &);
	virtual void		backward(std::vector<t_unit> &);

	Layer(unsigned int, unsigned int);
	~Layer();
};

void		Layer::forward([[maybe_unused]] std::vector<t_unit> & output) {}
void		Layer::backward([[maybe_unused]] std::vector<t_unit> & output) {}

std::tuple<uint, uint>		Layer::shape(void) {
	return (std::make_tuple(this->weights.size() / this->units.size(), this->units.size()));
}

/*!
 * \param prev	Number of units of the previous layer
 * \param size	Number of units for the current layer
 */
Layer::Layer(unsigned int prev, unsigned int size) : weights(prev * size), units(size) {
	for (register unsigned int idx = 0; idx < prev * size; ++idx)
		this->weights[idx] = static_cast<float>(std::rand()) / RAND_MAX;
	for (register unsigned int idx = 0; idx < size; ++idx)
		this->units[idx].bias = static_cast<float>(std::rand()) / RAND_MAX;
}

Layer::~Layer() {}

#endif /* __LAYER_HPP__ */
