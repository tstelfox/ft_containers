/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 16:44:37 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/13 12:50:11 by tmullan       ########   odam.nl         */
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

	for (size_t i = 0; i < attempt.size(); i++)
		std::cout << attempt[i];

	std::vector<tester>::reverse_iterator rit_begin = attempt.rbegin();
	std::vector<tester>::reverse_iterator rit_end = attempt.rend();
	std::cout << "Substracting the beginning from the end " << rit_end - rit_begin << std::endl;

}

void	test_object() {
	
	std::cout << "<-------TESTING VECTOR WITH OBJECT------->" << std::endl;

	tester	testinstance;
	tester	second(69, 3.14, "Montolivo");
	tester	third(99, 49.473, "Simio");
	tester	fourth(46, 6.66, "Magico Bilan");
	ft::vector<tester>	attempt;
	
	attempt.push_back(testinstance);
	attempt.push_back(second);
	attempt.push_back(third);
	attempt.push_back(fourth);

	for (size_t i = 0; i < attempt.size(); i++)
		std::cout << attempt[i];

	ft::vector<tester>::reverse_iterator rit_begin = attempt.rbegin();
	ft::vector<tester>::reverse_iterator rit_end = attempt.rend();
	std::cout << "Substracting the beginning from the end " << rit_end - rit_begin << std::endl;
}

int		main(void) {

	// int		numset[5] = {69, 99, 7, 111, 47};
	// ft::vector<int>	fuck(2);

	test_std();

	test_object();

	
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
