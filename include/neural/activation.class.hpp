/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:17:58 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 18:32:02 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_CLASS_HPP__
#define __ACTIVATION_CLASS_HPP__

#include "../core/activation_function.class.hpp"
#include "../core/matrix.struct.hpp"
#include "../core/layer.class.hpp"

template<class T>
struct			Activation : virtual public Layer {
	void		forward(Tensor const &);
	void		backward(Tensor const &);
	Tensor *	get_biases(void);
	Matrix *	get_weights(void);
};

template<class T> void	Activation<T>::forward([[maybe_unused]] Tensor const & in) {}

template<class T> void	Activation<T>::backward([[maybe_unused]] Tensor const & in) {}

template<class T> Tensor * Activation<T>::get_biases(void) { return (NULL); }
template<class T> Matrix * Activation<T>::get_weights(void) { return (NULL); }

#endif /* __ACTIVATION_CLASS_HPP__ */
