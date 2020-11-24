/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigmoid.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:52:55 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:08:49 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SIGMOID_CLASS_HPP__
#define __SIGMOID_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <vector>

namespace activation {

struct		sigmoid : public Activation {
	void	call(std::vector<float> &) const;
	void	derivative(std::vector<float> &) const;
	sigmoid(void);
};

} /* namespace activation */

#endif /* __SIGMOID_CLASS_HPP__ */
