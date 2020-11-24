/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bce.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:26:50 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:26:51 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BCE_CLASS_HPP__
#define __BCE_CLASS_HPP__

#include "../core/loss.class.hpp"
#include <vector>

using namespace std;

namespace loss {

/*!
 * \brief Binary cross entropy loss function
 */
struct			BCE : public loss {
	float		error(vector<float> const &, vector<float> const &) const;
	vector<float>	gradient(vector<float> const &, vector<float> const &) const;
};

} /* namespace loss */

#endif /* __BCE_CLASS_HPP__ */
