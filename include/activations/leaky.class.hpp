/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaky.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:49:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:00:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEAKY_CLASS_HPP__
#define __LEAKY_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <vector>

namespace activation {

struct		leaky : public Activation {
	void	call(std::vector<float> &) const;
	void	derivative(std::vector<float> &) const;
	leaky(void);
};

} /* namespace activation */

#endif /* __LEAKY_CLASS_HPP__ */
