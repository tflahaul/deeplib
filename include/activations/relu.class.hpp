/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relu.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:42:33 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:12:19 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RELU_CLASS_HPP__
#define __RELU_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <vector>

namespace activation {

struct		relu : public Activation {
	void	call(std::vector<float> &) const;
	void	derivative(std::vector<float> &) const;
	relu(void);
};

} /* namespace activation */

#endif /* __RELU_CLASS_HPP__ */
