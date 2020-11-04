/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/04 19:19:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include "../core.hpp"
#include <iostream>
#include <cstdio>
#include <vector>

class				Network
{
public:
	std::vector<Layer *>	_layers;

	void			describe(void);
	void			fit(std::vector<t_unit> &, std::vector<float> &);

	Network(void);
	~Network();
};

void		Network::describe(void) {
	for (unsigned int idx = 0; idx < this->_layers.size(); ++idx) {
		this->_layers[idx]->describe(std::cout);
		std::cout << std::endl;
	}
}

void		Network::fit(std::vector<t_unit> & inputs, [[maybe_unused]] std::vector<float> & targets) {
	this->_layers[0]->forward(inputs);
	for (unsigned int idx = 1; idx < this->_layers.size(); ++idx)
		this->_layers[idx]->forward(this->_layers[idx - 1]->units);
}

Network::Network(void) {}

Network::~Network() {
	for (unsigned int idx = 0; idx < this->_layers.size(); ++idx)
		delete this->_layers[idx];
}

#endif /* __NETWORK_CLASS_HPP__ */
