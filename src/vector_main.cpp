/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 16:44:37 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/18 15:32:03 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

class	tester {
	
		int			counts;
		float		angle;
		std::string	name;
	public:
		tester() : counts(1) , angle(0.78) , name("Fares") {}
		tester(int par, float para, std::string param) : counts(par) , angle(para) , name(param) {}
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

void	test_std() {

	std::cout << "<-------TESTING STD::VECTOR------->" << std::endl;


	tester	testinstance;
	tester	second(69, 3.14, "Montolivo");
	tester	third(99, 49.473, "Simio");
	tester	fourth(46, 6.66, "Magico Bilan");
	std::vector<tester>	attempt;
	
	attempt.push_back(testinstance);
	attempt.push_back(second);
	attempt.push_back(third);
	attempt.push_back(fourth);

	std::cout << "** Iterator test **" << std::endl;

	std::vector<tester>::iterator it_begin = attempt.begin();
	std::vector<tester>::iterator it_end = attempt.end();
	std::cout << "Substracting the beginning from the end " << it_end - it_begin << std::endl;
	while (it_begin != it_end)
	{
		std::cout << *it_begin;
		it_begin++;
	}

}

void	test_object() {
	
	std::cout << "<-------TESTING VECTOR WITH OBJECT------->" << std::endl;

	tester	testinstance;
	tester	second(69, 3.14, "Montolivo");
	tester	third(99, 49.473, "Simio");
	tester	fourth(46, 6.66, "Magico Bilan");
	tester	swapper(27, 9.47, "Forza Napoli");
	ft::vector<tester>	attempt;
	
	attempt.push_back(testinstance);
	attempt.push_back(second);
	attempt.push_back(third);
	attempt.push_back(fourth);

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
	swapped.push_back(swapper);

	swapped.swap(attempt);
	for (size_t i = 0; i < swapped.size(); i++)
		std::cout << "swapped item " << i << " " << swapped[i];
	std::cout << "Attempt has " << attempt[0];

	std::cout << "<--------TESTING WITH STRINGS---------->" << std::endl;

	ft::vector<std::string>	string_vec;
	string_vec.push_back("Mother");
	string_vec.push_back("Fucking");
	string_vec.push_back("Hijueputa");
	string_vec.push_back("Porqué");
	string_vec.push_back("Has venido");
	string_vec.push_back("Al party con los hermanos?");

	for (ft::vector<std::string>::iterator it = string_vec.begin(); it != string_vec.end(); it++)
		std::cout << *it << std::endl;
	string_vec[4] = "la cagaste";
	ft::vector<std::string>::iterator it = string_vec.begin();
	it += 4;
	std::cout << *it << std::endl;

	std::cout << "Size is " << string_vec.size() << std::endl;
	string_vec.resize(3);
	std::cout << string_vec.back() << std::endl;
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
		std::cout << swapped[i] << std::endl;
}

int		main(void) {

	
	// Range constructor testing
	// std::vector<int> john;
	// for (size_t i = 0; i < 10; i++)
	// 	john.push_back(i);
	// std::vector<int>::iterator it = john.begin();
	// std::vector<int>::iterator endit = john.end();

	/* ft::vector<int> ranged(it, endit);
	for (ft::vector<int>::iterator it = ranged.begin(); it != ranged.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "Copy constructing" << std::endl;
	ft::vector<int> copied(ranged);
	std::cout << "Let's check out copied vector: " << std::endl;
	for (ft::vector<int>::iterator it = copied.begin(); it != copied.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "Shit the [] overload " << copied[9] << std::endl;

	std::cout << "Assignation overload" << std::endl;

	ft::vector<int> Pilo;
	for (size_t i = 0; i < 10; i++)
		Pilo.push_back(i * 2);
	ft::vector<int>	assigned = Pilo;
	std::cout << "Right so this should be " << assigned[assigned.size() - 1] << std::endl; */



	// test_std();
	test_object();
	// test_int();

	// ft::vector<int>	fuck(2);
	// int		numset[5] = {69, 99, 7, 111, 47};
	
	// for (int i = 0; i < 5; i++)
	// 	fuck.push_back(numset[i]);

	// std::cout << "Checking item number 3: [" << fuck[2] << "]" << std::endl;

	// std::cout << "The back: " << fuck.back() << std::endl;
	// std::cout << "It's size: " << fuck.size() << std::endl;
	// fuck.resize(3);
	// std::cout << "The back: " << fuck.back() << std::endl;
	// std::cout << "It's size: " << fuck.size() << std::endl;
	// fuck.resize(10, 666);

	// for (size_t i = 0; i < fuck.size(); i++)
	// 	std::cout << fuck[i] << std::endl;

	
	// // fuck.clear();
	// fuck.push_back(111);
	// for (size_t i = 0; i < fuck.size(); i++)
	// 	std::cout << fuck[i] << std::endl;


	// std::cout << "<------Iterator time------>" << std::endl << std::endl;

	// fuck.clear();
	// for (size_t i = 0; i < 10; i++)
	// 	fuck.push_back(i);
	// // ft::vector::iterator it = fuck.begin();
	// ft::vector<int>::iterator theend = fuck.end();
	// for (ft::vector<int>::iterator it = fuck.begin(); it != theend; ++it)
	// 	std::cout << *it << std::endl;

	// ft::vector<int>::iterator it = fuck.begin();
	// ft::vector<int>::iterator	testit;

	// testit = 6 + it;
	// std::cout << "Well here goes " << *testit << std::endl;
	// std::cout << "it hasn't changed right " << *it << std::endl;

	// std::cout << "Difference is now " << testit - it << std::endl;
	// ft::vector<int>::reverse_iterator revit = fuck.rbegin();
	// std::cout << "So here is the reverse iterator's beginning: " << *revit << std::endl;
	// revit++;
	// std::cout << "Have gone one up the reverse iterator: " << *revit << std::endl;
	// revit = fuck.rend();
	// std::cout << "Set the reverse iterator to its end: " << *revit << std::endl;
}
