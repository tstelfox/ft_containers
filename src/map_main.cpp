/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:04:58 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/08 17:09:43 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#if STL
	#include <map>
	#include <iostream>
	#include <iomanip>
	#include <vector>
	#include <time.h>
	#define FT 0
	namespace ft = std;
#else
	#define FT 1
	#include "map.hpp"
	#include <vector>
	#include <time.h>
	#include <iomanip>
#endif

template < class T>
void	small_map(T &small) {
	small.insert(ft::pair<int, std::string>(1, "Root"));
	typename T::const_iterator it = small.begin();
	
	std::cout << it->first << " " << it->second << std::endl;
}

void	test_basic() {

	std::cout << std::boolalpha;

	ft::map<int, std::string> small;
	small_map(small);
	// std::cout << "<<<------THESE ARE MY BOYZZZZZZZZ------>>>" << std::endl;
	ft::map<int, std::string> test;

	test.insert(ft::pair<int, std::string>(10, "Fuoco"));
	test.insert(ft::pair<int, std::string>(12, "Kali"));
	test.insert(ft::pair<int, std::string>(17, "Uchis"));
	test.insert(ft::pair<int, std::string>(6, "Colombia"));
	test.insert(ft::pair<int, std::string>(15, "Gran Colombia"));
	test.insert(ft::pair<int, std::string>(4, "Shakira Shakira"));
	test.insert(ft::pair<int, std::string>(5, "Aiuto Shakira"));
	test.insert(ft::pair<int, std::string>(2, "Dio cane"));
	test.insert(ft::pair<int, std::string>(99, "dio bastardo"));
	test.insert(ft::pair<int, std::string>(47, "dio porco"));
	test.insert(ft::pair<int, std::string>(16, "dio stronzo"));


	// ft::pair<ft::map<int, std::string>::iterator, bool> deh = test.insert(ft::pair<int, std::string>(47, "Dio Vigliacco"));

	std::cout << "\nSQUARE BRACKETS" << std::endl;
	// test.printBT();
	std::cout << "What is the value here with a non-used key? " << test[68] << std::endl;
	std::cout << "And another unused key " << test[999] << std::endl;
	std::cout << "And another unused key " << test[9399] << std::endl;
	std::cout << "And another unused key " << test[232] << std::endl;
	std::cout << "And another unused key " << test[48] << std::endl;
	std::cout << "And another unused key " << test[343] << std::endl;
	std::cout << "And another unused key " << test[4435358] << std::endl;
	std::cout << "What about with a used key? " << test[17] << std::endl;
	// test.printBT();
	std::cout << test.size() << std::endl;
	// return ;
	// Main testing here
	// std::cout << "\nTree CONTENTS TIME" << std::endl;
	// std::cout << test.get_root()->object.first << " " << test.get_root()->object.second <<  std::endl;
	// test.contents(test.get_root(), 50, false);
	// if (FT == 1) {
	// 	std::cout << FT << std::endl;
	// 	test.printBT();
	// }

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
	// rev_it--;
	// std::cout << "This is where the money at aooooooo: " << rev_it->first << " " << rev_it->second << std::endl;
	test.insert(ft::pair<int, std::string>(4, "This shouldn't exist"));
	// test.printBT();


	ft::map<int, std::string>::iterator found = test.find(99);
	std::cout << "Found: " << found->second << std::endl;
	// ft::map<int, std::string>::iterator not_found = test.find(0);
	// std::cout << "Found: " << not_found->second << std::endl;

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
	// {
	ft::map<std::string, int>	range_rover;
	std::vector<ft::pair<std::string, int> > thething;
	thething.push_back(ft::make_pair("Carlo", 1));
	thething.push_back(ft::make_pair("Eugenio", 7));
	thething.push_back(ft::make_pair("Dé", 3));
	thething.push_back(ft::make_pair("Turlough", 99));
	thething.push_back(ft::make_pair("Cigio", 98));
	thething.push_back(ft::make_pair("Juanito", 69));
	thething.push_back(ft::make_pair("Pilerda", 66));
	thething.push_back(ft::make_pair("Lindsay", 700));
	thething.push_back(ft::make_pair("Perosh", 77));
	thething.push_back(ft::make_pair("DEfo", 88));

	range_rover.insert(thething.begin(), thething.end());
	// if (FT)
	// 	range_rover.printBT();

	std::cout << "\nERASING" << std::endl;

	std::cout << "Size before erasing two items: " << range_rover.size() << std::endl;

	range_rover.erase("DEfo");
	range_rover.erase("Dé");

	std::cout << "Size after erasing two items: " << range_rover.size() << std::endl;

	// if (FT)
	// 	range_rover.printBT();
	{	
		std::cout << "\nGonna clear the map, add a single element and erase it" << std::endl;
		range_rover.clear();
		
		std::cout << "Map is empty after clear()? " << range_rover.empty() << std::endl;
		range_rover.insert(thething.begin() + 2, thething.begin() + 3);
		std::cout << "Item inserted after clearing: " << range_rover.begin()->first << std::endl;
		range_rover.erase(range_rover.begin());
		std::cout << "Map is empty after erasing single item? " << range_rover.empty() << std::endl;
	}
	// std::cout << "\nGonna be testin swap() now with test and another map" << std::endl;

	// ft::map<int, std::string>	swappety;
	// swappety.insert(ft::pair<int, std::string>(44, "M'importa"));
	// swappety.insert(ft::pair<int, std::string>(22, "Una"));
	// swappety.insert(ft::pair<int, std::string>(33, "Bella"));
	// swappety.insert(ft::pair<int, std::string>(77, "Sega"));
	// swappety.insert(ft::pair<int, std::string>(45, "A"));
	// swappety.insert(ft::pair<int, std::string>(23, "Du mani"));

	// swappety.swap(test);

	// swappety.printBT();
	// test.printBT();

	// std::cout << "\nReverse_iterator with the iterator_traits.\nWhat if I try to make it do something stoopid?" << std::endl;


	// ft::map<std::string, int>::reverse_iterator	randello = range_rover.rbegin();
	// randello++;
	// std::cout << randello->first << std::endl;
	// ft::map<std::string, int>	single_fucker;
	// single_fucker.insert(make_pair("DIOCANE MAIALE", 69));
	// // std::cout << single_fucker.size() << std::endl;
	// single_fucker.erase(single_fucker.begin());
	// std::cout << "Why this no empty??? YYYY: " << single_fucker.begin()->first << std::endl; 

	// system ("leaks container");


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
	
	test_basic();
	// std_test();
	return 0;
}
