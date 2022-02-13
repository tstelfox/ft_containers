/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_main.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/21 16:10:27 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/13 20:43:00 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if STL
	#include <map>
	#include <iostream>
	#include <iomanip>
	#include <vector>
	#include <stack>
	#include <iterator>
	#include <time.h>
	#include <algorithm>
	#include <iomanip>
	#include <deque>
	#define FT 0
	namespace ft = std;
#else
	#define FT 1
	#include "stack.hpp"
	#include "vector.hpp"
	#include <time.h>
	#include <iomanip>
	#include <algorithm>
	#include <deque>
#endif

void	basic() {
	ft::vector<int>	fuck;
	int		numset[5] = {69, 99, 7, 111, 47};
	std::deque<std::string>	daboy;
	daboy.assign(3, "La trinitá");
	daboy.push_back("Dante");
	
	for (int i = 0; i < 5; i++)
		fuck.push_back(numset[i]);

	ft::stack<int, ft::vector<int> >	stacco(fuck);
	ft::stack<int, ft::vector<int> >	other;
	ft::stack<std::string, std::deque<std::string> > stackarr(daboy);

	std::cout << stacco.top() << std::endl;
	stacco.push(999);
	std::cout << stacco.top() << std::endl;
	std::cout << stacco.size() << std::endl;
	std::cout << std::boolalpha;
	std::cout << (stacco > other) << std::endl;

	std::cout << "Stack also works with a std::deque" << std::endl;
	std::cout << stackarr.top() << std::endl;
	std::cout << "Should contain 4 items: " << stackarr.size() << std::endl;
}

int		main() {


	basic();

	return 0;
}