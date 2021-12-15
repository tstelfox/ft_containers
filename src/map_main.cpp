/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:04:58 by tmullan       #+#    #+#                 */
/*   Updated: 2021/12/15 16:49:02 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

void	test_basic() {
	
	ft::map<int, std::string> first_v;

	// std::pair<ft::map<int, std::string>::iterator, bool> deh = first_v.insert(std::pair<int, std::string>(99, "Mazzarri"));
	first_v.insert(std::pair<int, std::string>(10, "Fuoco"));
	first_v.insert(std::pair<int, std::string>(12, "Kali"));
	first_v.insert(std::pair<int, std::string>(17, "Uchis"));
	first_v.insert(std::pair<int, std::string>(6, "Colombia"));
	first_v.insert(std::pair<int, std::string>(16, "Gran Colombia"));
	first_v.insert(std::pair<int, std::string>(11, "Shakira Shakira"));
	// std::pair<ft::map<int, std::string>::iterator, bool> deh = first_v.insert(std::pair<int, std::string>(47, "Dio Vigliacco"));
	ft::map<int, std::string>::iterator it = first_v.begin();
	std::cout << it->object.second << std::endl;

	std::cout << "\nTree CONTENTS TIME" << std::endl;
	// std::cout << first_v.get_root()->object.first << " " << first_v.get_root()->object.second <<  std::endl;
	first_v.contents(first_v.get_root(), 0);
	// it++; // This requires the nodes and iterators to go up the tree

	// The following isn't working diobe:
	// node<std::pair<const int, std::string> > next = *it->left;
	// it = it->right;
	// std::cout << next.object.second << std::endl;
	
}

int		main() {

	test_basic();

	return 0;
}
