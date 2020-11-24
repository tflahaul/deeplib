/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:17:13 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:35:53 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INPUT_CLASS_HPP__
#define __INPUT_CLASS_HPP__

#include "../core/activation.class.hpp"
#include "../core/layer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <vector>

using namespace std;

/*!
 * \brief Regular input layer
 */
template<class Activation>
struct			Input : virtual public Layer {
	Matrix *	get_weights(void);
	vector<float> *	get_biases(void);
	void		forward(vector<float> const &);
	void		backward(vector<float> const &);
	Input(unsigned int);
};

#endif /* __INPUT_CLASS_HPP__ */
