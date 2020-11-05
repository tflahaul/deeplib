/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:31:57 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/04 23:19:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_CLASS_HPP__
#define __LAYER_CLASS_HPP__

#include "unit.struct.h"
#include <iostream>
#include <cstdint>
#include <vector>

enum				e_types {
	INPUT,
	DENSE,
	DROPOUT
};

class				Layer {
private:
	int			_type;
public:
	std::vector<t_unit>	units;

	int			type(void);
	void			set_type(int const);
	virtual void		forward(std::vector<t_unit> &);
	virtual void		backward(std::vector<t_unit> &);
	virtual void		describe(std::ostream &) const = 0;
	friend std::ostream&	operator<<(std::ostream &, Layer const &);

	Layer(uint32_t const, int const);
	virtual ~Layer();
};

int		Layer::type(void) {
	return (this->_type);
}

void		Layer::set_type(int const type) { this->_type = type; }

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
Layer::Layer(uint32_t const size, int const type) : _type(type), units(size) {}
Layer::~Layer() {}

#endif /* __LAYER_CLASS_HPP__ */
