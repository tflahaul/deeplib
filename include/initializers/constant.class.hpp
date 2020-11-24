/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:38:38 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:22:33 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONSTANT_CLASS_HPP__
#define __CONSTANT_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <vector>

namespace initializer {

class		Constant : public Initializer {
private:
	float	_constant = 0.0;
public:
	void	init(struct Matrix *, std::vector<float> *);
	Constant(float const);
};

} /* namespace initializer */

#endif /* __CONSTANT_CLASS_HPP__ */
