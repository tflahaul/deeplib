/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:06:45 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:58:19 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INITIALIZER_CLASS_HPP__
#define __INITIALIZER_CLASS_HPP__

#include "matrix.struct.hpp"
#include <vector>

namespace initializer {

struct			Initializer {
	virtual void	init(Matrix *, Tensor *) = 0;
};

} /* namespace initializer */

#endif /* __INITIALIZER_CLASS_HPP__ */
