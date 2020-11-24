/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mse.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:26:56 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:29:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MSE_CLASS_HPP__
#define __MSE_CLASS_HPP__

#include "../core/loss.class.hpp"
#include <vector>

using namespace std;

namespace loss {

struct			MSE : public loss {
	float		error(vector<float> const &, vector<float> const &) const;
	vector<float>	gradient(vector<float> const &, vector<float> const &) const;
};

} /* namespace loss */

#endif /* __MSE_CLASS_HPP__ */
