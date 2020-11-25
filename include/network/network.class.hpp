/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/25 14:16:37 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include "../network/network.class.hpp"
#include "../core/optimizer.class.hpp"
#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"
#include <cassert>
#include <cstdint>
#include <vector>

using namespace std;

class				Network {
private:
	vector<Layer *>		_layers;
	struct Optimizer *	_optimizer = NULL;
public:
	void			add(Layer *);
	template<class I> void	build(void);
	void			prepare(struct Optimizer *);
	vector<float> &		feed(vector<float> const &);
	void			fit(vector<float> const &, vector<float> const &);
	~Network();
};

/*!
 * \brief Push a new layer to the network
 * \param layer pointer to the layer
 */
void			Network::add(Layer * layer) {
	this->_layers.push_back(layer);
}

/*!
 * \brief Initialize all the weights and biases of layers.
 * 	  You need to specify a type of initializer
 */
template<class I> void	Network::build(void) {
	assert(this->_layers.size() >= 2);
	for (uint_fast32_t idx = 1; idx < this->_layers.size(); ++idx)
		I().init(this->_layers[idx]->get_weights(), this->_layers[idx]->get_biases());
}

/*!
 * \brief Prepares training by setting an optimizer
 */
void			Network::prepare(struct Optimizer *opti) {
	this->_optimizer = opti;
}

/*!
 * \brief Does a single feed-forward through the network and returns its output.
 * 	  Don't use this for testing if your network contains dropout layers (yet)
 * \param X data to feed in
 */
vector<float> &		Network::feed(vector<float> const & X) {
	this->_layers[0]->forward(X);
	for (uint_fast32_t idx = 1; idx < this->_layers.size(); ++idx)
		this->_layers[idx]->forward(this->_layers[idx - 1]->units);
	return (this->_layers[this->_layers.size() - 1]->units);
}

/*!
 * \brief Train the network
 * \param X data to feed in
 * \param y targets
 */
void			Network::fit(vector<float> const & X, [[maybe_unused]] vector<float> const & y) {
	this->_layers[0]->forward(X);
	for (uint_fast32_t idx = 1; idx < this->_layers.size(); ++idx)
		this->_layers[idx]->forward(this->_layers[idx - 1]->units);
}

Network::~Network() {
	if (this->_optimizer != NULL)
		delete this->_optimizer;
	for (unsigned int idx = 0; idx < this->_layers.size(); ++idx)
		delete this->_layers[idx];
}

#endif /* __NETWORK_CLASS_HPP__ */
