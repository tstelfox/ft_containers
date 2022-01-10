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

template < class T, class iter>
void	small_map(T small, iter it) {
	// small.insert(std::pair<int, std::string>(1, "Root"));
	it = small.begin();
	
	std::cout << it->first << " " << it->second << std::endl;
}


void	std_test() {

	std::map<int, std::string> small;
	std::map<int, std::string>::iterator	small_iter;
	small_map(small, small_iter);

	std::map<int, std::string> test;

	std::cout << "<<<------STANDARD TESTIN BOYSSSS------>>>" << std::endl;
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
	std::cout << "NOW BACKWARDS with rev" << std::endl;
	std::map<int, std::string>::reverse_iterator rev_it = test.rbegin();
	// rev
	// it++;
	while (rev_it != test.rend()) {
		std::cout << "Value at previous iteration: " << rev_it->first << " " << rev_it->second << std::endl;
		rev_it++;
	}
	// Eh ma diobe
	rev_it--;
	std::cout << "This is where the money at aooooooo: " << rev_it->first << " " << rev_it->second << std::endl;
}


void	test_basic() {

	// ft::map<int, std::string> small;
	// ft::map<int, std::string>::iterator	small_iter;
	// small_map(small, small_iter);
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

	// Main testing here
	std::cout << "\nTree CONTENTS TIME" << std::endl;
	// std::cout << test.get_root()->object.first << " " << test.get_root()->object.second <<  std::endl;
	// test.contents(test.get_root(), 50, false);
	// Fuck why is the tree not balanced?
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
	std::cout << "NOW BACKWARDS WITH REVERSE_ITERATOR" << std::endl;
	ft::map<int, std::string>::reverse_iterator rev_it = test.rbegin();
	// rev
	// it++;
	while (rev_it != test.rend()) {
		std::cout << "Value at previous iteration: " << rev_it->first << " " << rev_it->second << std::endl;
		rev_it++;
	}
	// Eh ma diobe
	rev_it--;
	std::cout << "This is where the money at aooooooo: " << rev_it->first << " " << rev_it->second << std::endl;
	// for (size_t i = 0; i < (test.size()); i++) {
	// }
	// std::cout << "Value at previous iteration: " << rev_it->first << " " << rev_it->second << std::endl;
	// *it++;
	// std::cout << "Attempting to *iterate: " << it->first << " " << it->second << std::endl;

	// ft::map<int, std::string>::const_iterator const_it = test.begin();
	
}

int		main() {

	// I could build in some variable so that I could compile it as standard or as ft
	test_basic();
	// std_test();
	return 0;
}
