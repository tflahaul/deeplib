/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dense.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:13:43 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:31:28 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DENSE_CLASS_HPP__
#define __DENSE_CLASS_HPP__

#include "../core/activation.class.hpp"
#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"
#include <cstdint>
#include <vector>

using namespace std;

/*!
 * \brief Regular fully-connected neural network layer
 */
template<typename Activation>
class			Dense : virtual public Layer {
private:
	vector<float>	biases;
	vector<float>	bgrads;
	struct Matrix	weights;
	struct Matrix	wgrads;
public:
	vector<float> *	get_biases(void);
	Matrix *	get_weights(void);
	void		forward(vector<float> const &);
	void		backward(vector<float> const &);
	Dense(uint32_t, uint32_t);
};

#endif /* __DENSE_CLASS_HPP__ */
