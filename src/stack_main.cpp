/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_main.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/21 16:10:27 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/21 16:10:27 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

int		main() {

	ft::vector<int>	fuck;
	int		numset[5] = {69, 99, 7, 111, 47};
	
	for (int i = 0; i < 5; i++)
		fuck.push_back(numset[i]);

	ft::stack<int>	stacco(fuck);
	ft::stack<int>	other;

	std::cout << stacco.top() << std::endl;
	std::cout << std::boolalpha;
	std::cout << (stacco > other) << std::endl;

	return 0;
}