/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/03 15:36:04 by thflahau         ###   ########.fr       */
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
	void			fit(std::vector<t_unit> &);

	Network(void);
	~Network();
};

void		Network::describe(void) {
	for (unsigned int idx = 0; idx < this->_layers.size(); ++idx) {
		this->_layers[idx]->describe(std::cout);
		std::cout << std::endl;
	}
}

void		Network::fit(std::vector<t_unit> & inputs) {
	this->_layers[0]->forward(inputs);
	for (unsigned int x = 0; x < this->_layers[0]->units.size(); ++x)
		printf("%.2f ", this->_layers[0]->units[x].value);
	std::cout << std::endl;
	for (unsigned int idx = 1; idx < this->_layers.size(); ++idx) {
		this->_layers[idx]->forward(this->_layers[idx - 1]->units);
		for (unsigned int x = 0; x < this->_layers[idx]->units.size(); ++x)
			printf("%.2f ", this->_layers[idx]->units[x].value);
		std::cout << std::endl;
	}
}

Network::Network(void) {}

Network::~Network() {
	for (unsigned int idx = 0; idx < this->_layers.size(); ++idx)
		delete this->_layers[idx];
}

#endif /* __NETWORK_CLASS_HPP__ */
