/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loss.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:37:14 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/27 20:37:27 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LOSS_CLASS_HPP__
#define __LOSS_CLASS_HPP__

#include "matrix.struct.hpp"

namespace loss {

struct			loss {
	virtual float	error(Tensor const &, Tensor const &) const = 0;
	virtual Tensor	gradient(Tensor const &, Tensor const &) const = 0;
};

} /* namespace loss */

#endif /* __LOSS_CLASS_HPP__ */
