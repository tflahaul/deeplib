# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Network.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 15:06:42 by thflahau          #+#    #+#              #
#    Updated: 2020/11/06 15:29:58 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests, gzip

class Network(object):
	def __init__(self, base : str = None):
		self.url = base

	def get(self, link : str, unzip=False) -> bytes:
		print(f'Fetching data from {self.url + link}...')
		response = requests.get(self.url + link)
		if unzip == True:
			return gzip.decompress(response.content)
		else:
			return response.content
