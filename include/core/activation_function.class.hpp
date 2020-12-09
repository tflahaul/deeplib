/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation_function.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:25:03 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:45:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATION_FUNCTION_CLASS_HPP__
#define __ACTIVATION_FUNCTION_CLASS_HPP__

#include "matrix.struct.hpp"

struct			ActivationFunction {
	virtual void	call(Tensor &) const = 0;
	virtual void	derivative(Tensor &) const = 0;
};

#endif /* __ACTIVATION_FUNCTION_CLASS_HPP__ */
