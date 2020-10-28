/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/28 23:17:31 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_HPP__
#define __DENSE_HPP__

#include "../core.hpp"
#include "../activations/activation.hpp"
#include <iostream>
#include <string>

class				Dense : public Layer
{
private:
	Activation		_activation;
public:
	void			(*activate)(struct vector const *);
	void			forward(Layer const &);
	void			backward(Layer const &);
	friend std::ostream&	operator<<(std::ostream &, Dense &);
	Dense(unsigned int);
	Dense(unsigned int, std::string const &);
};

std::ostream&	operator<<(std::ostream &stream, Dense &instance) {
	stream << "Layer: type=dense, shape=" << instance.shape();
	stream << ", activation=" << instance._activation.get_name();
	return (stream);
}

void		Dense::forward([[maybe_unused]] Layer const &instance) {}
void		Dense::backward([[maybe_unused]] Layer const &instance) {}

Dense::Dense(unsigned int shape) : Layer(shape), _activation(Activation("linear")) {}
Dense::Dense(unsigned int shape, std::string const &name) : Layer(shape), _activation(name) {}

#endif /* __DENSE_HPP__ */
