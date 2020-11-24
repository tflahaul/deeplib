/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropout.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:11:19 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:34:15 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DROPOUT_CLASS_HPP__
#define __DROPOUT_CLASS_HPP__

#include "../core/layer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <vector>

using namespace std;

/*!
 * \brief Regular dropout NN layer : applies dropout to the input
 */
class			Dropout : virtual public Layer {
private:
	float		_rate;
public:
	vector<float> *	get_biases(void);
	Matrix *	get_weights(void);
	void		forward(vector<float> const &);
	void		backward(vector<float> const &);
	Dropout(unsigned int, double);
};

#endif /* __DROPOUT_CLASS_HPP__ */
