/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:32:25 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/04 19:36:47 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INITIALIZERS_HPP__
#define __INITIALIZERS_HPP__

#include <vector>

void			regular(std::vector<float> &);
void			uniform(std::vector<float> &);
void			constant(std::vector<float> &, float const);

#endif /* __INITIALIZERS_HPP__ */
