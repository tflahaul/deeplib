/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:40:34 by thflahau          #+#    #+#             */
/*   Updated: 2020/11/01 18:22:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NETWORK_CLASS_HPP__
#define __NETWORK_CLASS_HPP__

#include <vector>

class			Network
{
private:
	/* data */
public:
	void		fit(std::vector<float> const &, std::vector<float> const &);

	Network(void);
	~Network();
};

/*!
 * \param X	Training data
 * \param y	Target data
 */
void		Network::fit(std::vector<float> const & X, std::vector<float> const & y) {}

Network::Network(void) {}
Network::~Network() {}

#endif /* __NETWORK_CLASS_HPP__ */
