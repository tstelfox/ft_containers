/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:04:58 by tmullan       #+#    #+#                 */
/*   Updated: 2021/12/22 18:34:54 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

void	test_basic() {
	
	ft::map<int, std::string> test;

	// std::pair<ft::map<int, std::string>::iterator, bool> deh = test.insert(std::pair<int, std::string>(99, "Mazzarri"));
	test.insert(std::pair<int, std::string>(10, "Fuoco"));
	test.insert(std::pair<int, std::string>(12, "Kali"));
	test.insert(std::pair<int, std::string>(17, "Uchis"));
	test.insert(std::pair<int, std::string>(6, "Colombia"));
	test.insert(std::pair<int, std::string>(15, "Gran Colombia"));
	test.insert(std::pair<int, std::string>(4, "Shakira Shakira"));
	test.insert(std::pair<int, std::string>(5, "Aiuto Shakira"));
	test.insert(std::pair<int, std::string>(2, "dio cane"));
	test.insert(std::pair<int, std::string>(99, "dio bastardo"));
	test.insert(std::pair<int, std::string>(47, "dio porco"));
	test.insert(std::pair<int, std::string>(16, "dio stronzo"));


	// std::pair<ft::map<int, std::string>::iterator, bool> deh = test.insert(std::pair<int, std::string>(47, "Dio Vigliacco"));
	ft::map<int, std::string>::iterator it = test.begin();
	std::cout << "Value at beginning: " << it->object.second << std::endl;

	std::cout << "\nTree CONTENTS TIME" << std::endl;
	// std::cout << test.get_root()->object.first << " " << test.get_root()->object.second <<  std::endl;
	test.contents(test.get_root(), 50, false);
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
