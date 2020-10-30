/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/30 17:03:18 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <vector>

/*!
 * \brief Regular input layer
 */
class				Input
{
private:
	std::vector<float>	_units;
public:
	Input(unsigned int);
	~Input();
};

/*!
 * \param size	Number of units for the input layer
 */
Input::Input(unsigned int size) : _units(size) {}
Input::~Input() {}

#endif /* __INPUT_HPP__ */
