/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/29 11:37:16 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_HPP__
#define __DENSE_HPP__

#include "../core.hpp"
#include "../activations/activation.hpp"
#include <iostream>
#include <string>

/*!
 * \brief Regular densely-connected neural network layer.
 */
class				Dense : public Layer
{
private:
	Activation		_activation;
public:
	void			(*activate)(struct vector const *);
	void			forward(Layer const &);
	void			backward(Layer const &);
	friend std::ostream&	operator<<(std::ostream &, Dense &);
	Dense(unsigned int const);
	Dense(unsigned int const, std::string const &);
};

void		Dense::forward([[maybe_unused]] Layer const &instance) {}
void		Dense::backward([[maybe_unused]] Layer const &instance) {}

std::ostream&	operator<<(std::ostream &stream, Dense &instance) {
	stream << "Layer: type=dense, shape=" << instance.shape();
	stream << ", activation=" << instance._activation.get_name();
	return (stream);
}

/*!
 * \param shape	Output size of the layer.
 */
Dense::Dense(unsigned int const shape) : Layer(shape), _activation(Activation("linear")) {}

/*!
 * \param shape	Output size of the layer.
 * \param name	Activation function to use.
 */
Dense::Dense(unsigned int const shape, std::string const &name) : Layer(shape), _activation(name) {}

#endif /* __DENSE_HPP__ */
