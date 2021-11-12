/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:04:58 by tmullan       #+#    #+#                 */
/*   Updated: 2021/11/12 11:01:29 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

void	test_basic() {
	
	ft::map<int, std::string> first_v;

	// std::pair<ft::map<int, std::string>::iterator, bool> deh = first_v.insert(std::pair<int, std::string>(99, "Mazzarri"));
	first_v.insert(std::pair<int, std::string>(99, "Mazzarri"));
	// std::pair<ft::map<int, std::string>::iterator, bool> deh = first_v.insert(std::pair<int, std::string>(47, "Dio Vigliacco"));
	ft::map<int, std::string>::iterator it = first_v.begin();

	std::cout << it->object.second << std::endl;
	// it++; // This requires the nodes and iterators to go up the tree

	//The following isn't working diobe:
	// node<std::pair<const int, std::string> > next = *it->left;
	// it = it->right;
	// std::cout << next.object.second << std::endl;
	
}

int		main() {

	test_basic();

	return 0;
}
