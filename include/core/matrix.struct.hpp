/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:17:05 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/07 21:30:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATRIX_CLASS_HPP__
#define __MATRIX_CLASS_HPP__

#include <iostream> //delete
#include <cstdint>
#include <vector>

using namespace std;

struct				Matrix
{
	unsigned int		xdim;
	unsigned int		ydim;
	vector<vector<float>>	values;

	Matrix(unsigned int const, unsigned int const);
};

Matrix::Matrix(unsigned int const x, unsigned int const y) : values(x, vector<float>(y)) {
	cout << "Matrix with shape (" << x << "," << y << ")" << endl;
}

#endif /* __MATRIX_CLASS_HPP__ */
