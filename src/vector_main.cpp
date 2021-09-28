/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 16:44:37 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/28 16:54:37 by tmullan       ########   odam.nl         */
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

	int		numset[5] = {69, 99, 7, 111, 47};
	std::vector<int> jesus(2);

	for (int i = 0; i < 5; i++)
		jesus.push_back(numset[i]);
	std::cout << "The back: " << jesus.back() << std::endl;
	std::cout << "It's size: " << jesus.size() << std::endl;
	jesus.pop_back();
	std::cout << "The back: " << jesus.back() << std::endl;
	std::cout << "It's size: " << jesus.size() << std::endl;
}

int		main(void) {

	int		numset[5] = {69, 99, 7, 111, 47};
	ft::vector<int>	fuck(2);
	ft::vector<tester>	attempt;
	// ft::vector<int> to_swap(10, 7);

	// test_std();

	tester	testinstance;
	tester	second(69, 3.14, "Montolivo");
	for (int i = 0; i < 5; i++)
		fuck.push_back(numset[i]);

	attempt.push_back(testinstance);

	std::cout << "Checking item number 3: [" << fuck[2] << "]" << std::endl;

	std::cout << "The back: " << fuck.back() << std::endl;
	std::cout << "It's size: " << fuck.size() << std::endl;
	fuck.resize(3);
	std::cout << "The back: " << fuck.back() << std::endl;
	std::cout << "It's size: " << fuck.size() << std::endl;
	fuck.resize(10, 666);

	for (size_t i = 0; i < fuck.size(); i++)
		std::cout << fuck[i] << std::endl;
	std::cout << attempt.back();
	
	attempt.push_back(second);
	std::cout << attempt.back();

	// std::cout << attempt.size() << std::endl;
	
	fuck.clear();
	fuck.push_back(111);
	for (size_t i = 0; i < fuck.size(); i++)
		std::cout << fuck[i] << std::endl;

	std::cout << "<------ITERATOR TIME------>" << std::endl << std::endl;

	ft::vector<int>::iterator	it;

	it = fuck.begin();
	std::cout << *it << std::endl;
	/* ft::vector<int> copyfuck(fuck);
	std::cout << "Checking copyitem number 3: [" << copyfuck[2] << "]" << std::endl;
	fuck[2] = 99999;
	std::cout << "Checking fuck item number 3: [" << fuck[2] << "]" << std::endl;
	std::cout << "Checking copyitem number 3: [" << copyfuck[2] << "]" << std::endl; */
}
