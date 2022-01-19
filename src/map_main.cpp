/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:04:58 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/19 12:29:54 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <vector>

template < class T, class iter>
void	small_map(T small, iter it) {
	small.insert(std::pair<int, std::string>(1, "Root"));
	it = small.begin();
	
	std::cout << it->first << " " << it->second << std::endl;
}


void	std_test() {

	// std::map<int, std::string> small;
	// std::map<int, std::string>::iterator	small_iter;
	// small_map(small, small_iter);

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


	std::cout << "\nLower_bound and sheet" << std::endl;
	std::cout << "Lower bound of 6: " << test.lower_bound(6)->first << std::endl;
	std::cout << "Upper bound of 6: " << test.upper_bound(6)->first << std::endl;

	std::cout << "Equal range with a match: " << test.equal_range(15).first->first << " " <<
		test.equal_range(15).second->first << std::endl;
	std::cout << "Equal range without a match: " << test.equal_range(87).first->first << " " <<
		test.equal_range(87).second->first << std::endl;

	std::cout << "\nSQUARE BRACKETSSS" << std::endl;
	std::cout << "Item number " << 4 << " is: " << test[3] << std::endl;
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
	rev_it--;
	std::cout << "This is where the money at aooooooo: " << rev_it->first << " " << rev_it->second << std::endl;
	test.insert(std::pair<int, std::string>(4, "This shouldn't exist"));
	// test.printBT();


	ft::map<int, std::string>::iterator found = test.find(99);
	std::cout << "Found: " << found->second << std::endl;
	ft::map<int, std::string>::iterator not_found = test.find(0);
	std::cout << "Found: " << not_found->second << std::endl;

	std::cout << "Should be there " << test.count(99) << std::endl;
	std::cout << "Should not be there " << test.count(66) << std::endl;

	// std::cout << "\nSQUARE BRACKETSSS" << std::endl;

	std::cout << "\nLower_bound and sheet" << std::endl;

	std::cout << "Lower bound of 6: " << test.lower_bound(6)->first << std::endl;
	std::cout << "Upper bound of 6: " << test.upper_bound(6)->first << std::endl;

	std::cout << "Equal range with a match: " << test.equal_range(15).first->first << " " <<
		test.equal_range(15).second->first << std::endl;
	std::cout << "Equal range without a match: " << test.equal_range(87).first->first << " " <<
		test.equal_range(87).second->first << std::endl;


	std::cout << "\nRANGED INSERT LEZGO" << std::endl;
	{
		ft::map<std::string, int>	range_rover;
		std::vector<std::pair<std::string, int> > thething;
		thething.push_back(std::make_pair("Carlo", 1));
		thething.push_back(std::make_pair("Eugenio", 7));
		thething.push_back(std::make_pair("Dé", 3));
		thething.push_back(std::make_pair("Turlough", 99));
		thething.push_back(std::make_pair("Cigio", 98));
		thething.push_back(std::make_pair("Juanito", 69));
		thething.push_back(std::make_pair("Pilerda", 66));
		thething.push_back(std::make_pair("Lindsay", 700));
		thething.push_back(std::make_pair("Perosh", 77));
		thething.push_back(std::make_pair("DEfo", 88));

		range_rover.insert(thething.begin(), thething.end());
		range_rover.printBT();

		std::cout << "\nERASING" << std::endl;

		range_rover.erase("DEfo");
		range_rover.erase("Dé");
		range_rover.erase("Juanito");
		range_rover.printBT();

		std::cout << "\nGonna clear the map, add a single element and erase it" << std::endl;
		range_rover.clear();
		std::cout << range_rover.empty() << std::endl;
		range_rover.insert(thething.begin() + 2, thething.begin() + 3);
		range_rover.printBT();
		// std::cout << range_rover.begin()->first << std::endl;
		range_rover.erase(range_rover.begin());
		std::cout << range_rover.empty() << std::endl;
	}
	system ("leaks container");


	/* std::cout << "\nTRYING THE VARIOUS CONSTRUCTORS" << std::endl;
	ft::map<std::string, int> copy_constructed(range_rover);
	copy_constructed.printBT();
	ft::map<std::string, int> range_constructed(range_rover.begin(), range_rover.end());
	range_constructed.printBT(); */
	// std::cout << range_rover.size() << std::endl;
	// for (ft::map<std::string, int>::iterator it = range_rover.begin(); it != range_rover.end(); it++) {
	// 	std::cout << it->first << std::endl;
	// }

	// std::cout << "Item number 4 is: " << test[9] << std::endl;

	// Bianchi positivo iolai
	// it = test.begin();
	// while (it != test.end()) {
	// 	std::cout << "Value at next iteration: " << it->first << " " << it->second << std::endl;
	// 	it++;
	// }
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
