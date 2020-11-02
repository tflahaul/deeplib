/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/02 22:29:12 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include "../core.hpp"
#include <iostream>
#include <vector>

class				Network
{
public:
	std::vector<Layer *>	_layers;

	void			describe(void) {
		for (unsigned int idx = 0; idx < this->_layers.size(); ++idx) {
			this->_layers[idx]->describe(std::cout);
			std::cout << std::endl;
		}
	}

	Network(void) {}
	~Network() {}
};

#endif /* __NETWORK_CLASS_HPP__ */
