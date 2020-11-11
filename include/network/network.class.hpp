/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/11 15:52:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/layer.class.hpp"
#include "../neural/input.class.hpp"
#include "../neural/dense.class.hpp"
#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>
#include <map>

using namespace std;

class				Network {
private:
	vector<Layer *>		_layers;
public:
	void			add(Layer *);
	template<class I> void	build(void);
	void			fit(vector<float> &, vector<float> &);
	~Network();
};

void			Network::add(Layer * ptr) {
	this->_layers.push_back(ptr);
}

template<class I> void	Network::build(void) {
	if (this->_layers.size() < 2)
		throw logic_error("build method requires multiple _layers");
	for (uint_fast32_t idx = 1; idx < this->_layers.size(); ++idx)
		if (this->_layers[idx]->trainable() == true) {}
}

void			Network::fit(vector<float> & X, [[maybe_unused]] vector<float> & y) {
	this->_layers[0]->forward(X);
	for (uint_fast32_t idx = 1; idx < this->_layers.size(); ++idx)
		this->_layers[idx]->forward(this->_layers[idx - 1]->units);
}

Network::~Network() {
	for (uint_fast32_t idx = 0; idx < this->_layers.size(); ++idx)
		delete this->_layers[idx];
}

#endif /* __NETWORK_CLASS_HPP__ */
