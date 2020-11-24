/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:39:44 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include "../core/optimizer.class.hpp"
#include "../core/layer.class.hpp"
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

#endif /* __NETWORK_CLASS_HPP__ */
