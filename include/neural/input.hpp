/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/29 11:45:34 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <cstdint>
#include <vector>

/*!
 * \brief Regular input layer.
 */
class				Input
{
private:
	std::vector<float>	_units;
public:
	Input(unsigned int);
	~Input();
};

Input::Input(unsigned int shape) {
	this->_units.resize(shape);
}

Input::~Input() {}

#endif /* __INPUT_HPP__ */
