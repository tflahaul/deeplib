/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activations.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:16:06 by thflahau          #+#    #+#             */
/*   Updated: 2020/10/22 13:11:18 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ACTIVATIONS_HPP__
#define __ACTIVATIONS_HPP__

#include "../core/vector.hpp"

extern "C" {

void		softmax(struct vector const *);
void		sigmoid(struct vector const *);
void		minmax(struct vector const *);
void		linear(struct vector const *);
void		relu(struct vector const *);
void		tanh(struct vector const *);

} /* extern C */

#endif /* __ACTIVATIONS_HPP__ */
