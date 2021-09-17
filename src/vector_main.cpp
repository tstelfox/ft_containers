/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 16:44:37 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/17 12:34:19 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int		main(void) {

	ft::vector<int>	fuck(7);

	fuck.push_back(69);
	fuck.push_back(99);

	std::cout << fuck.back() << std::endl;
}