/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:58:41 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:05:49 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINMAX_CLASS_HPP__
#define __MINMAX_CLASS_HPP__

#include "../core/activation.class.hpp"
#include <vector>

namespace activation {

struct		minmax : public Activation {
	void	call(std::vector<float> &) const;
	void	derivative(std::vector<float> &) const;
	minmax(void);
};

} /* namespace activation */

#endif /* __MINMAX_CLASS_HPP__ */
