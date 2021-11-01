/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2021/11/01 16:08:45 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <map>
#include "bi_iterator.hpp"
#include "tree_node.hpp"

namespace ft {


template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair<const Key, T> > >
class map
{
	public:

		typedef	Key											key_type;
		typedef	T											mapped_type;
		typedef std::pair<const key_type, mapped_type>		value_type;
		typedef	Compare										key_compare;
		typedef	Alloc										allocator_type;
		typedef	value_type&									reference;
		typedef	const value_type&							const_reference;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
		typedef	Biditerator<value_type, pointer, reference>	iterator;
		typedef	size_t										size_type;
		typedef	ptrdiff_t									difference_type;

		class	value_compare : binary_function<value_type, value_type, bool> {
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
		};

		explicit map(key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type())
				: m_allocator(alloc) , _comp(comp) , m_size(0) {
			data = NULL;
			std::cout << "Here is a map with whatever type" << std::endl;
		}


		~map() {}

		/* <<**------------------- ITERATORS ------------------**>> */

		iterator	begin() {
			return iterator(data);
		}

		/* <<**------------------- CAPACITY ------------------**>> */

		/* <<**------------------- ELEMENT ACCESS ------------------**>> */

		// mapped_type&	operator[] (key_type const &k) {
		// 	//Requires insert I believe - But now I'm not so sure
		// 	//In any case I perhaps need to crack std::pair first
		// }

		/* <<**------------------- MODIFIERS ------------------**>> */

		std::pair<iterator, bool>	insert (const value_type& val) {
			data = m_allocator.allocate(m_size + 1); // Allocation is gonna have to be managed
			m_size++;
			value_type dave = std::make_pair(val.first, val.second);
			m_allocator.construct(&(*data), dave);
			iterator it = begin();

			return std::make_pair(it, true);
		}



	private:
		allocator_type		m_allocator;
		key_compare			_comp;
		size_type			m_size;
		node<value_type>		tree;
		// pointer			data; //This has to be replaced by the binary tree nodes

		// Have to make a binary tree node class then
		

};

}
