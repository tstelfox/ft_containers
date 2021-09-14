/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/14 17:28:04 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class map
{
private:
	/* data */
public:
	map(/* args */);
	~map();
};

map::map(/* args */)
{
	std::cout << "The map is here" << std::endl;
}

map::~map()
{
}
