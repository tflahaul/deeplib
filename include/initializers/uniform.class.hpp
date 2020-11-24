/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:44:27 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/24 15:23:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UNIFORM_CLASS_HPP__
#define __UNIFORM_CLASS_HPP__

#include "../core/initializer.class.hpp"
#include "../core/matrix.struct.hpp"
#include <vector>
#include <random>

using namespace std;

namespace initializer {

/*!
 * \brief Initialize weights using an uniform distribution of values
 */
class		Uniform : public Initializer {
private:
	mt19937	_generator;
public:
	void	init(struct Matrix *, vector<float> *);
	Uniform(void);
	Uniform(unsigned int const);
};

} /* namespace initializer */

#endif /* __UNIFORM_CLASS_HPP__ */
