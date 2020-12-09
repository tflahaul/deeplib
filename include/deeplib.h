/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deeplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:44:11 by thflahau          #+#    #+#             */
/*   Updated: 2020/12/04 17:56:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DEEPLIB_H__
#define __DEEPLIB_H__

#include "activations/softmax.class.hpp"
#include "activations/sigmoid.class.hpp"
#include "activations/linear.class.hpp"
#include "activations/minmax.class.hpp"
#include "activations/leaky.class.hpp"
#include "activations/relu.class.hpp"
#include "activations/tanh.class.hpp"

#include "core/activation_function.class.hpp"
#include "core/initializer.class.hpp"
#include "core/optimizer.class.hpp"
#include "core/matrix.struct.hpp"
#include "core/layer.class.hpp"

#include "initializers/constant.class.hpp"
#include "initializers/regular.class.hpp"
#include "initializers/uniform.class.hpp"

#include "loss/mse.class.hpp"
#include "loss/bce.class.hpp"

#include "network/network.class.hpp"

#include "neural/activation.class.hpp"
#include "neural/dropout.class.hpp"
#include "neural/dense.class.hpp"
#include "neural/input.class.hpp"

#endif /* __DEEPLIB_H__ */
