/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bce.cc                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:24:48 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:26:19 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/loss/bce.class.hpp"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

namespace loss {

float			BCE::error(vector<float> const & out, vector<float> const & target) const {
	assert(out.size() == 1 && target.size() == 1);
	return (-((target[0] * logf(out[0])) + ((1.0 - target[0]) * logf(1.0 - out[0]))));
}

vector<float>		BCE::gradient(vector<float> const & out, vector<float> const & target) const {
	assert(out.size() == 1 && target.size() == 1);
	return (target);
}

} /* namespace loss */
