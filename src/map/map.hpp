/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/25 17:45:21 by tmullan       ########   odam.nl         */
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

		class	value_compare {
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool 		result_type;
				typedef value_type	first_argument_type;
				typedef	value_type	second_argument_type;
				bool operator () (value_type const &x, value_type const &y) const {
					return comp(x.first, y.first);
				}
		}
		// Somehow have to build this value_compare

		map() {}
		~map() {}
	private:
		allocator_type	m_allocator;
		key_compare		_comp;
		size_type		m_size;
		pointer			data; //Is it a pointer?
		

};
