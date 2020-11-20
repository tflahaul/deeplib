/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mean.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:20:18 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/09 19:20:44 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MEAN_CLASS_HPP__
#define __MEAN_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <vector>

namespace activation {

struct		mean : public Activation
{
	void	call(std::vector<float> &) const;
	mean(void);
};

void		mean::call([[maybe_unused]] std::vector<float> & units) const {
	float	min, max, sum;
}

mean::mean(void) : Activation("mean") {}

} /* namespace activation */

#endif /* __MEAN_CLASS_HPP__ */
