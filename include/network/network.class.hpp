/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/06 19:16:23 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/layer.class.hpp"
#include "../neural/input.class.hpp"
#include "../neural/dense.class.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdint>
#include <memory>
#include <vector>

struct				Network {
	std::vector<std::shared_ptr<Layer>>	layers;

	void			describe(void);
	void			fit(std::vector<float> &, std::vector<float> &);
	template<class T> void	build(void);
	template<class T> void	add(T);
};

void			Network::describe(void) {
	for (uint_fast32_t idx = 0; idx < this->layers.size(); ++idx) {
		std::cout << "Layer -> ";
		this->layers[idx].get()->describe(std::cout);
		std::cout << std::endl;
	}
}

template<class T> void	Network::add(T layer) {
	this->layers.push_back(std::make_shared<T>(layer));
}

template<class T> void	Network::build(void) {
	if (this->layers.size() < 2)
		throw std::logic_error("build method requires multiple layers");
	for (uint_fast32_t i = 1; i < this->layers.size(); ++i)
		if (this->layers[i].get()->trainable() == true)
			T().init(static_cast<Dense*>(this->layers[i].get())->weights);
}

void			Network::fit(std::vector<float> & X, [[maybe_unused]] std::vector<float> & y) {
	this->layers[0]->forward(X);
	for (unsigned int idx = 1; idx < this->layers.size(); ++idx)
		this->layers[idx]->forward(this->layers[idx - 1]->units);
}

#endif /* __NETWORK_CLASS_HPP__ */
