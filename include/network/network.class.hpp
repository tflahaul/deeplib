/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/09 19:08:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/layer.class.hpp"
#include "../neural/input.class.hpp"
#include "../neural/dense.class.hpp"
#include <stdexcept>
#include <iostream> // delete
#include <cstdint>
#include <memory>
#include <vector>

using namespace std;

struct				Network {
	vector<shared_ptr<Layer>>	layers;

	void			fit(vector<float> &, vector<float> &);
	void			add(Layer const &);
	template<class T> void	build(void);
};

void			Network::add(Layer const & instance) {
	this->layers.push_back(make_shared<Layer>(instance));
}

template<class T> void	Network::build(void) {
	if (this->layers.size() < 2)
		throw logic_error("build method requires multiple layers");
	for (uint_fast32_t idx = 1; idx < this->layers.size(); ++idx)
		if (this->layers[idx].get()->trainable() == true) {}
}

void			Network::fit(vector<float> & X, [[maybe_unused]] vector<float> & y) {
	this->layers[0]->forward(X);
	for (unsigned int idx = 1; idx < this->layers.size(); ++idx)
		this->layers[idx]->forward(this->layers[idx - 1]->units);
}

#endif /* __NETWORK_CLASS_HPP__ */
