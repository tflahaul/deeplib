/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:31:57 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/06 19:21:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_CLASS_HPP__
#define __LAYER_CLASS_HPP__

#include <iostream>
#include <cstdint>
#include <vector>

class				Layer {
private:
	bool			_trainable = false;
public:
	std::vector<float>	units;

	bool			trainable(void) const;
	virtual void		forward(std::vector<float> &);
	virtual void		backward(std::vector<float> &);
	virtual void		describe(std::ostream &) const = 0;
	friend std::ostream&	operator<<(std::ostream &, Layer const &);

	Layer(uint32_t const);
	Layer(uint32_t const, bool const);
	virtual ~Layer();
};

bool		Layer::trainable(void) const {
	return (this->_trainable);
}

std::ostream&	operator<<(std::ostream & stream, Layer const & instance) {
	instance.describe(stream);
	return (stream);
}

void		Layer::forward([[maybe_unused]] std::vector<float> & output) {}
void		Layer::backward([[maybe_unused]] std::vector<float> & output) {}

/*!
 * \param size	Number of units for the current layer
 */
Layer::Layer(uint32_t const size) : units(size) {}

/*!
 * \param size	Number of units for the current layer
 * \param train	Is the layer trainable? Trainable layers have weights
 */
Layer::Layer(uint32_t const size, bool const train) : _trainable(train), units(size) {}
Layer::~Layer() {}

#endif /* __LAYER_CLASS_HPP__ */
