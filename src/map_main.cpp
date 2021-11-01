/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:04:58 by tmullan       #+#    #+#                 */
/*   Updated: 2021/11/01 17:10:48 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

void	test_basic() {
	
	ft::map<int, std::string> first_v;

	std::pair<ft::map<int, std::string>::iterator, bool> deh = first_v.insert(std::pair<int, std::string>(99, "Mazzarri"));
	ft::map<int, std::string>::iterator it = deh.first;
	std::cout << it->second << std::endl;
	
}

int		main() {

	test_basic();

	return 0;
}
