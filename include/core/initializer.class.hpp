/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:06:45 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/05 12:50:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INITIALIZER_CLASS_HPP__
#define __INITIALIZER_CLASS_HPP__

#include <vector>

namespace build {

class			Initializer {
public:
	virtual void	init(std::vector<float> &) = 0;
	Initializer(void);
	~Initializer();
};

Initializer::Initializer(void) {}
Initializer::~Initializer() {}

} /* namespace build */

#endif /* __INITIALIZER_CLASS_HPP__ */
