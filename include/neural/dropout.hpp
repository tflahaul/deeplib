/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropout.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:11:19 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/22 12:59:31 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DROPOUT_HPP__
#define __DROPOUT_HPP__

#include "../core/layer.hpp"
#include <iostream>

class				Dropout : public Layer
{
private:
	double			rate;
public:
	void			forward(Layer const &);
	void			backward(Layer const &);
	friend std::ostream&	operator<<(std::ostream &, Dropout &);
	Dropout(unsigned int, double);
};

void		Dropout::forward([[maybe_unused]] Layer const &instance) {}
void		Dropout::backward([[maybe_unused]] Layer const &instance) {}

std::ostream&	operator<<(std::ostream &stream, Dropout &instance) {
	stream << "Layer: type=dropout, shape=" << instance.shape();
	stream << ", droprate=" << instance.rate;
	return (stream);
}

Dropout::Dropout(unsigned int shape, double rate) : Layer(shape) {
	this->rate = std::min(1., std::max(0., rate));
}

#endif /* __DROPOUT_HPP__ */
