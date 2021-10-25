/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/25 16:32:44 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <memory>
#include <map>

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair<const Key, T> > >
class map
{
	public:

		typedef	Key										key_type;
		typedef	T										mapped_type;
		typedef std::pair<const key_type, mapped_type>	value_type;
		typedef	Compare									key_compare;
		typedef	Alloc									allocator_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		// Iterator stuff
		typedef	size_t									size_type;
		typedef	ptrdiff_t								difference_type;

		// Somehow have to build this value_compare

		map() {}
		~map() {}
	private:
		allocator_type	m_allocator;
		key_compare		_comp;
		
		

};
