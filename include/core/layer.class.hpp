/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:31:57 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/02 22:35:52 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_CLASS_HPP__
#define __LAYER_CLASS_HPP__

#include "unit.struct.h"
#include <iostream>
#include <cstdint>
#include <vector>

class				Layer
{
public:
	std::vector<t_unit>	units;

	virtual void		forward(std::vector<t_unit> &);
	virtual void		backward(std::vector<t_unit> &);
	virtual void		describe(std::ostream &) const;
	friend std::ostream&	operator<<(std::ostream &, Layer const &);

	Layer(uint32_t const);
	~Layer();
};

std::ostream&	operator<<(std::ostream & stream, Layer const & instance) {
	instance.describe(stream);
	return (stream);
}

void		Layer::forward([[maybe_unused]] std::vector<t_unit> & output) {}
void		Layer::backward([[maybe_unused]] std::vector<t_unit> & output) {}
void		Layer::describe([[maybe_unused]] std::ostream & stream) const {}

/*!
 * \param size	Number of units for the current layer
 */
Layer::Layer(uint32_t const size) : units(size) {}
Layer::~Layer() {}

#endif /* __LAYER_CLASS_HPP__ */
