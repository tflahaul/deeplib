/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:31:57 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/09 19:11:27 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LAYER_CLASS_HPP__
#define __LAYER_CLASS_HPP__

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

class			Layer {
private:
	bool		_trainable = false;
public:
	vector<float>	units;

	bool		trainable(void) const;
	virtual void	forward(vector<float> &);
	virtual void	backward(vector<float> &);
	Layer(uint32_t const);
	Layer(uint32_t const, bool const);
	virtual ~Layer();
};

bool		Layer::trainable(void) const {
	return (this->_trainable);
}

void		Layer::forward([[maybe_unused]] std::vector<float> & out) {}
void		Layer::backward([[maybe_unused]] std::vector<float> & out) {}

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
