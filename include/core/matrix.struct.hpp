/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.struct.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:17:05 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/27 20:38:02 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATRIX_CLASS_HPP__
#define __MATRIX_CLASS_HPP__

#include <cstdint>
#include <vector>

using Tensor = std::vector<float>;
using namespace std;

struct			Matrix {
	unsigned int	xdim;
	unsigned int	ydim;
	vector<Tensor>	values;
	Matrix(unsigned int const, unsigned int const);
};

Matrix::Matrix(unsigned int const x, unsigned int const y) : values(x, Tensor(y)) {
	this->xdim = x;
	this->ydim = y;
}

#endif /* __MATRIX_CLASS_HPP__ */
