/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   softmax.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:56:12 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:09:51 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SOFTMAX_CLASS_HPP__
#define __SOFTMAX_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <vector>

namespace activation {

struct		softmax : public Activation {
	void	call(std::vector<float> &) const;
	void	derivative(std::vector<float> &) const;
	softmax(void);
};

} /* namespace activation */

#endif /* __SOFTMAX_CLASS_HPP__ */
