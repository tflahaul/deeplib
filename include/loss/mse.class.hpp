/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mse.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:26:56 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/27 20:40:26 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MSE_CLASS_HPP__
#define __MSE_CLASS_HPP__

#include "../core/matrix.struct.hpp"
#include "../core/loss.class.hpp"
#include <cassert>
#include <cstdint>

namespace loss {

struct		MSE : public loss {
	float	error(Tensor const &, Tensor const &) const;
	Tensor	gradient(Tensor const &, Tensor const &) const;
};

float		MSE::error(Tensor const & out, Tensor const & target) const {
	float	loss = 0.0;
	assert(out.size() == target.size());
	for (uint_fast32_t idx = 0; idx < out.size(); ++idx)
		loss += (out[idx] - target[idx]) * (out[idx] - target[idx]);
	return (loss / out.size());
}

Tensor		MSE::gradient(Tensor const & out, Tensor const & target) const {
	Tensor	derivatives(out.size());
	for (uint_fast32_t idx = 0; idx < out.size(); ++idx)
		derivatives[idx] = 2.0 * (out[idx] - target[idx]);
	return (derivatives);
}

} /* namespace loss */

#endif /* __MSE_CLASS_HPP__ */
