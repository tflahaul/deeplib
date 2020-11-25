/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mse.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:26:56 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/25 14:14:33 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MSE_CLASS_HPP__
#define __MSE_CLASS_HPP__

#include "../core/loss.class.hpp"
#include <cassert>
#include <cstdint>
#include <vector>

using namespace std;

namespace loss {

struct			MSE : public loss {
	float		error(vector<float> const &, vector<float> const &) const;
	vector<float>	gradient(vector<float> const &, vector<float> const &) const;
};

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

#endif /* __MSE_CLASS_HPP__ */
