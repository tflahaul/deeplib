/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/05 13:09:40 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include "../core.hpp"
#include "../neural.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

class				Network {
private:
	build::Initializer	*_initializer;
public:
	std::vector<Layer *>	layers;

	void			describe(void);
	void			build(void);
	void			fit(std::vector<t_unit> &, std::vector<float> &);

	Network(void);
	Network(build::Initializer *);
	~Network();
};

void		Network::describe(void) {
	for (unsigned int idx = 0; idx < this->layers.size(); ++idx) {
		this->layers[idx]->describe(std::cout);
		std::cout << std::endl;
	}
}

void		Network::build(void) {
	if (this->layers.size() < 2 || !static_cast<Input*>(this->layers[0]))
		throw std::logic_error("build method needs multiple layers");
	for (unsigned int idx = 1; idx < this->layers.size(); ++idx)
		if (this->layers[idx]->type() == DENSE)
			this->_initializer->init(static_cast<Dense*>(this->layers[idx])->weights);
}

void		Network::fit(std::vector<t_unit> & inputs, [[maybe_unused]] std::vector<float> & targets) {
	this->layers[0]->forward(inputs);
	for (unsigned int idx = 1; idx < this->layers.size(); ++idx)
		this->layers[idx]->forward(this->layers[idx - 1]->units);
}

Network::Network(build::Initializer * init) : _initializer(init) {}
Network::Network(void) : _initializer(new build::Regular()) {}
Network::~Network() {}

#endif /* __NETWORK_CLASS_HPP__ */
