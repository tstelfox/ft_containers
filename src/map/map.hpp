/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/25 12:25:43 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <memory>

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair<const Key, T> > >
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
