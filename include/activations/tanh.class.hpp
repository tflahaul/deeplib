/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tanh.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:54:46 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:12:09 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TANH_CLASS_HPP__
#define __TANH_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <vector>

namespace activation {

struct		tanh : public Activation {
	void	call(std::vector<float> &) const;
	void	derivative(std::vector<float> &) const;
	tanh(void);
};

} /* namespace activation */

#endif /* __TANH_CLASS_HPP__ */
