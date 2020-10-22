/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/22 12:59:23 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_HPP__
#define __DENSE_HPP__

#include "../core/core.hpp"
#include <iostream>
#include <string>

class				Dense : public Layer
{
public:
	void			forward(Layer const &);
	void			backward(Layer const &);
	friend std::ostream&	operator<<(std::ostream &, Dense &);
	Dense(unsigned int);
};

std::ostream&	operator<<(std::ostream &stream, Dense &instance) {
	stream << "Layer: type=dense, shape=" << instance.shape();
	return (stream);
}

void		Dense::forward([[maybe_unused]] Layer const &instance) {}
void		Dense::backward([[maybe_unused]] Layer const &instance) {}

Dense::Dense(unsigned int shape) : Layer(shape) {}

#endif /* __DENSE_HPP__ */
