/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mse.cc                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:27:19 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 19:07:31 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/loss/mse.class.hpp"
#include <cstdint>
#include <cassert>
#include <vector>

namespace loss {

float			MSE::error(vector<float> const & out, vector<float> const & target) const {
	float		loss = 0.0;
	assert(out.size() == target.size());
	for (uint_fast32_t idx = 0; idx < out.size(); ++idx)
		loss += (out[idx] - target[idx]) * (out[idx] - target[idx]);
	return (loss);
}

vector<float>		MSE::gradient(vector<float> const & out, vector<float> const & target) const {
	vector<float>	derivatives(out.size());
	for (uint_fast32_t idx = 0; idx < out.size(); ++idx)
		derivatives[idx] = 2.0 * (out[idx] - target[idx]);
	return (derivatives);
}

} /* namespace loss */
