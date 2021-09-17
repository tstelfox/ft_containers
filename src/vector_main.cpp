/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 16:44:37 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/17 16:19:05 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int		main(void) {

	ft::vector<int>	fuck(2);

	fuck.push_back(69);
	fuck.push_back(99);
	fuck.push_back(7);
	fuck.push_back(69);
	fuck.push_back(99);
	fuck.push_back(865);

	std::cout << "Checking item number 3: [" << fuck[2] << "]" << std::endl;

	std::cout << fuck.back() << std::endl;

}
