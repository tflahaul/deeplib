/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/27 15:41:42 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_HPP__
#define __DENSE_HPP__

#include "../core.hpp"
#include "../activations/activations.h"
#include <exception>
#include <iostream>

class				Dense : public Layer
{
public:
	void			(*activate)(struct vector const *);
	void			forward(Layer const &);
	void			backward(Layer const &);
	friend std::ostream&	operator<<(std::ostream &, Dense &);
	Dense(unsigned int);
	Dense(unsigned int, void (*)(struct vector const *));
};

std::ostream&	operator<<(std::ostream &stream, Dense &instance) {
	stream << "Layer: type=dense, shape=" << instance.shape();
	return (stream);
}

void		Dense::forward([[maybe_unused]] Layer const &instance) {}
void		Dense::backward([[maybe_unused]] Layer const &instance) {}

Dense::Dense(unsigned int shape) : Layer(shape) {}

Dense::Dense(unsigned int shape, void (*ptr)(struct vector const *)) : Layer(shape) {
	this->activate = (ptr != NULL) ? ptr : &linear_activate;
}

#endif /* __DENSE_HPP__ */
