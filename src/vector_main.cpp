/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 16:44:37 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/08 17:09:20 by tmullan       ########   odam.nl         */
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
	#include <time.h>
	#include <iomanip>
	#include "vector.hpp"
#endif


class	tester {
	
		int			counts;
		float		angle;
		std::string	name;
	public:
		tester() : counts(1) , angle(0.78) , name("Fares") {}
		tester(int par, float para, std::string param) : counts(par) , angle(para) , name(param) {}
		tester(const tester &x) {
			*this = x;
		}
		tester&	operator= (const tester &x) {
			if (this != &x) {
				this->counts = x.getcounts();
				this->angle = x.getangle();
				this->name = x.getname();
			}
			return *this;
		}
		~tester() {}

		int getcounts() const {
			return (counts);
		}
		float getangle() const {
			return (angle);
		}
		std::string	getname() const {
			return(name);
		}
};

std::ostream& operator << (std::ostream &o, tester const &instance) {
	o << "Here are the contents: " << instance.getcounts() << " " << instance.getangle() << " " << instance.getname() << std::endl;
		return (o);
}

void	test_object() {
	
	std::cout << "<-------TESTING VECTOR WITH OBJECT------->" << std::endl;

	tester	testinstance;
	tester  *second = new tester(69, 3.14, "Montolivo");
	tester	*third = new tester(99, 49.473, "Simio");
	tester	*fourth = new tester(46, 6.66, "Magico Bilan");
	tester	*swapper = new tester(27, 9.47, "Forza Napoli");
	tester	*sixth = new tester(0, 1010, "Adriatico");
	ft::vector<tester>	attempt;
	
	attempt.push_back(testinstance);
	attempt.push_back(*second);
	attempt.push_back(*third);
	attempt.push_back(*fourth);

	std::cout << "** Iterator test **" << std::endl;

	ft::vector<tester>::iterator it_begin = attempt.begin();
	ft::vector<tester>::iterator it_end = attempt.end();
	std::cout << "Substracting the beginning from the end " << it_end - it_begin << std::endl;
	while (it_begin != it_end)
	{
		std::cout << *it_begin;
		it_begin++;
	}

	std::cout << "** Swap test **" << std::endl;

	ft::vector<tester> swapped;
	swapped.push_back(*swapper);

	swapped.swap(attempt);
	for (size_t i = 0; i < swapped.size(); i++)
		std::cout << "swapped item " << i << " " << swapped[i];
	std::cout << "Attempt has " << attempt[0];

	std::cout << "***** Assignation *****" << std::endl;
	ft::vector<tester>::iterator iter = swapped.begin();
	attempt.assign(iter, iter + 2);
	for (size_t i = 0; i < attempt.size(); i++)
		std::cout << "Attempt has been assigned the items from swapped: " << swapped[i];


	std::cout << "***** Insertion *****" << std::endl;
	iter += 2;
	swapped.insert(iter, *sixth);
	std::cout << "*Single*" << std::endl;
	for (size_t i = 0; i < swapped.size(); i++)
		std::cout << "Item no " << i << " of vector: " << swapped[i];
	// std::cout << "*Ranged*" << std::endl;
	// swapped.insert(iter, 5, swapper);
	for (size_t i = 0; i < swapped.size(); i++)
		std::cout << "Item no " << i << " of vector: " << swapped[i];
	std::cout << "*With Iterators*" << std::endl;
	for (size_t i = 0; i < attempt.size(); i++)
		std::cout << "Item no " << i << " of attempt vector BEFORE: " << attempt[i];
	ft::vector<tester>::iterator first = swapped.begin() + 1;
	ft::vector<tester>::iterator last = first + 4;
	attempt.insert(attempt.begin() + attempt.size(), first, last);
	for (size_t i = 0; i < attempt.size(); i++)
		std::cout << "Item no " << i << " of attempt vector AFTER: " << attempt[i];

	std::cout << "***** Erasing *****" << std::endl;
	std::cout << "*Single*" << std::endl;
	attempt.erase(attempt.begin() + 2);
	for (size_t i = 0; i < attempt.size(); i++)
		std::cout << "Item no " << i << " of attempt vector: " << attempt[i];
	std::cout << "*Ranged of first three elements*" << std::endl;
	attempt.erase(attempt.begin(), attempt.begin() + 3);
	for (size_t i = 0; i < attempt.size(); i++)
		std::cout << "Item no " << i << " of attempt vector: " << attempt[i];

	std::cout << "<--------TESTING WITH STRINGS---------->" << std::endl;

	ft::vector<std::string>	string_vec;
	ft::vector<std::string> other_vec;
	string_vec.push_back("Mother");
	string_vec.push_back("Fucking");
	string_vec.push_back("Hijueputa");
	string_vec.push_back("Porqué");
	string_vec.push_back("Has venido");
	string_vec.push_back("Al party con los hermanos?");

	other_vec.push_back("darkaufhayyyybung is kind of annoying");
	other_vec.push_back("Whiney, I'd say");

	for (ft::vector<std::string>::reverse_iterator rev_it = string_vec.rbegin(); rev_it != string_vec.rend(); rev_it++)
		std::cout << "In reverse order: " << *rev_it << std::endl;
	for (ft::vector<std::string>::iterator it = string_vec.begin(); it != string_vec.end(); it++)
		std::cout << "Elements of string_vec: " << *it << std::endl;
	string_vec[4] = "la cagaste";
	ft::vector<std::string>::iterator it = string_vec.begin();
	it += 4;
	std::cout << "After overwriting it, at begin() + 4 we find: " << *it << std::endl;
	*it++;
	std::cout << "Quick test of *it++: " << *it << std::endl;

	std::cout << "Size is " << string_vec.size() << std::endl;
	string_vec.resize(3);
	std::cout << "After resizing to 3 at the end of string_vec we find: " << string_vec.back() << std::endl;

	std::cout << "****Relational Operators****" << std::endl;
	if (string_vec < other_vec)
		std::cout << "string_vec is smaller" << std::endl;
	else if (other_vec < string_vec)
		std::cout << "other_vec is smaller" << std::endl;
	
	std::cout << "*Ranged*" << std::endl;
	string_vec.insert(string_vec.begin() + 3, 5, "NO ME IMPOLTA");

	for (it = string_vec.begin(); it != string_vec.end(); it++)
		std::cout << "Vector after ranged insert: " << *it << std::endl;
	
	std::cout << "Clearing both of them" << std::endl;
	other_vec.clear();
	string_vec.clear();
	if (string_vec == other_vec)
		std::cout << "Now they're equal" << std::endl;

}

void	test_int() {

	ft::vector<int>	fuck;
	int		numset[5] = {69, 99, 7, 111, 47};
	
	for (int i = 0; i < 5; i++)
		fuck.push_back(numset[i]);

	std::cout << "** Swap test **" << std::endl;

	ft::vector<int> swapped;
	swapped.push_back(99999);

	swapped.swap(fuck);
	for (size_t i = 0; i < swapped.size(); i++)
		std::cout << "Swapped item [" << i << "] " << swapped[i] << std::endl;
	
	for (size_t i = 0; i < fuck.size(); i++)
		std::cout << "Fuck item [" << i << "] " << fuck[i] << std::endl;
	
	std::cout << "****Relational Operators****" << std::endl;
	if (fuck < swapped)
		std::cout << "Fuck is smaller" << std::endl;
	else if (swapped < fuck)
		std::cout << "swapped is smaller" << std::endl;
	
	std::cout << "Clearing both of them" << std::endl;
	swapped.clear();
	fuck.clear();
	if (fuck == swapped)
		std::cout << "Now they're equal" << std::endl;
}

int		main(void) {

	test_object();
	test_int();

	return 0;

}
