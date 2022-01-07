/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:04:58 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/06 17:34:13 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

void	std_test() {

	std::map<int, std::string> test;

	std::cout << "<<<------STANDARD TESTIN BOYSSSS------>>>" << std::endl;
	// std::pair<ft::map<int, std::string>::iterator, bool> deh = test.insert(std::pair<int, std::string>(99, "Mazzarri"));
	test.insert(std::pair<int, std::string>(10, "Fuoco"));
	test.insert(std::pair<int, std::string>(12, "Kali"));
	test.insert(std::pair<int, std::string>(17, "Uchis"));
	test.insert(std::pair<int, std::string>(6, "Colombia"));
	test.insert(std::pair<int, std::string>(15, "Gran Colombia"));
	test.insert(std::pair<int, std::string>(4, "Shakira Shakira"));
	test.insert(std::pair<int, std::string>(5, "Aiuto Shakira"));
	test.insert(std::pair<int, std::string>(2, "Dio cane"));
	test.insert(std::pair<int, std::string>(99, "dio bastardo"));
	test.insert(std::pair<int, std::string>(47, "dio porco"));
	test.insert(std::pair<int, std::string>(16, "dio stronzo"));

	// test.printBT();

	std::cout << "\nTESTIN ITERATORS" << std::endl;
	std::map<int, std::string>::iterator it = test.begin();
	// std::cout << "Value at beginning: " << it->first << " " << it->second << std::endl;
	while (it != test.end()) {
		// std::cout << "Testin testin" << std::endl;
		std::cout << "Value at next iteration: " << it->first << " " << it->second << std::endl;
		it++;
	}
	std::cout << "NOW BACKWARDS" << std::endl;
	// std::cout << "Value at beginning: " << it->first << " " << it->second << std::endl;
	for (size_t i = 0; i < (test.size()); i++) {
		it--;
		std::cout << "Value at previous iteration: " << it->first << " " << it->second << std::endl;
	}
}

void	test_basic() {


	std::cout << "<<<------THESE ARE MY BOYZZZZZZZZ------>>>" << std::endl;
	ft::map<int, std::string> test;

	test.insert(std::pair<int, std::string>(10, "Fuoco"));
	test.insert(std::pair<int, std::string>(12, "Kali"));
	test.insert(std::pair<int, std::string>(17, "Uchis"));
	test.insert(std::pair<int, std::string>(6, "Colombia"));
	test.insert(std::pair<int, std::string>(15, "Gran Colombia"));
	test.insert(std::pair<int, std::string>(4, "Shakira Shakira"));
	test.insert(std::pair<int, std::string>(5, "Aiuto Shakira"));
	test.insert(std::pair<int, std::string>(2, "Dio cane"));
	test.insert(std::pair<int, std::string>(99, "dio bastardo"));
	test.insert(std::pair<int, std::string>(47, "dio porco"));
	test.insert(std::pair<int, std::string>(16, "dio stronzo"));


	// std::pair<ft::map<int, std::string>::iterator, bool> deh = test.insert(std::pair<int, std::string>(47, "Dio Vigliacco"));

	std::cout << "\nTree CONTENTS TIME" << std::endl;
	// std::cout << test.get_root()->object.first << " " << test.get_root()->object.second <<  std::endl;
	// test.contents(test.get_root(), 50, false);
	test.printBT();

	std::cout << "\nTESTIN ITERATORS" << std::endl;
	ft::map<int, std::string>::iterator it = test.begin();
	// std::cout << "Value at beginning: " << it->first << " " << it->second << std::endl;
	while (it != test.end()) {
		// std::cout << "Testin testin" << std::endl;
		std::cout << "Value at next iteration: " << it->first << " " << it->second << std::endl;
		it++;
	}
	it--;
	std::cout << "This should be the last item: " << it->first << " " << it->second << std::endl;
	std::cout << "NOW BACKWARDS" << std::endl;
	it++;
	for (size_t i = 0; i < (test.size()); i++) {
		it--;
		std::cout << "Value at previous iteration: " << it->first << " " << it->second << std::endl;
	}

	// *it++;
	// std::cout << "Attempting to *iterate: " << it->first << " " << it->second << std::endl;

	// ft::map<int, std::string>::const_iterator const_it = test.begin();


	// std::pair<int, std::string> yonks(94784, "Don't do it maaaan");
	// *const_it = yonks;
	// *it = yonks;

	// test.inorder(test.get_root());
	// it++; // This requires the nodes and iterators to go up the tree

	// The following isn't working diobe:
	// node<std::pair<const int, std::string> > next = *it->left;
	// it = it->right;
	// std::cout << next.object.second << std::endl;
	
}

int		main() {

	test_basic();
	// std_test();
	return 0;
}
