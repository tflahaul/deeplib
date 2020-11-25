/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bce.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:26:50 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/25 14:14:00 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BCE_CLASS_HPP__
#define __BCE_CLASS_HPP__

#include "../core/loss.class.hpp"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

namespace loss {

/*!
 * \brief Binary cross entropy loss function
 */
struct			BCE : public loss {
	float		error(vector<float> const &, vector<float> const &) const;
	vector<float>	gradient(vector<float> const &, vector<float> const &) const;
};

float			BCE::error(vector<float> const & out, vector<float> const & target) const {
	assert(out.size() == 1 && target.size() == 1);
	return (-((target[0] * logf(out[0])) - ((1.0 - target[0]) * logf(1.0 - out[0]))));
}

vector<float>		BCE::gradient(vector<float> const & out, vector<float> const & target) const {
	assert(out.size() == 1 && target.size() == 1);
	vector<float>	derivatives(out.size());
	for (uint_fast32_t idx = 0; idx < out.size(); ++idx)
		derivatives[idx] = (out[idx] - target[idx]) / (out[idx] * (1.0 - out[idx]));
	return (derivatives);
}

} /* namespace loss */

#endif /* __BCE_CLASS_HPP__ */
