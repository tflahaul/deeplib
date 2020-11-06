/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:18:30 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/06 13:45:23 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REGULAR_CLASS_HPP__
#define __REGULAR_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <ctime>

namespace build {

/*!
 * \brief Initialize weights with normal distribution of values
 */
struct			Regular : public Initializer {
	virtual void	init(std::vector<float> &);
	Regular(unsigned int const);
	Regular(void);
};

void			Regular::init(std::vector<float> & weights) {
	for (register uint_fast32_t idx = 0; idx < weights.size(); ++idx)
		weights[idx] = static_cast<float>(std::rand()) / RAND_MAX;
}

Regular::Regular(unsigned int const seed) {
	std::srand(seed);
}

Regular::Regular(void) {
	std::srand(time(NULL));
}

} /* namespace build */

#endif /* __REGULAR_CLASS_HPP__ */
