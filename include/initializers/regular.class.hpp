/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:18:30 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:23:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REGULAR_CLASS_HPP__
#define __REGULAR_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <vector>

namespace initializer {

/*!
 * \brief Initialize weights using a regular distribution of values
 */
class		Regular : public Initializer {
public:
	void	init(struct Matrix *, std::vector<float> *);
	Regular(unsigned int const);
	Regular(void);
};

} /* namespace initializer */

#endif /* __REGULAR_CLASS_HPP__ */
