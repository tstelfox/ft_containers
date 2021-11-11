/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2021/11/11 16:07:10 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <map>
#include "bimap_iterator.hpp"

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
		typedef	Bimapiterator<value_type, pointer, reference>	iterator;
		typedef	size_t										size_type;
		typedef	ptrdiff_t									difference_type;
		typedef node<value_type>							mapnode;
		typedef	typename Alloc::template rebind<mapnode>::other					node_alloc;

		class	value_compare : std::binary_function<value_type, value_type, bool> {
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
				: m_allocator(alloc) , _comp(comp) , m_size(0), first() {
			// value_type temp = value_type(0, 0);
			// first.object = m_allocator.allocate(1);
			// node<value_type> fuck(temp);
			// first = fuck;
			// node<value_type>	temp(std::make_pair(key_type(), mapped_type()));
			// this->first = temp;
			// tree = 0;
			// last = 0;
			std::cout << "Here is a map with whatever type" << std::endl;
		}


		~map() {}

		/* <<**------------------- ITERATORS ------------------**>> */

		iterator	begin() {
			return iterator(first);
		}

		/* <<**------------------- CAPACITY ------------------**>> */

		/* <<**------------------- ELEMENT ACCESS ------------------**>> */

		// mapped_type&	operator[] (key_type const &k) {
		// 	//Requires insert I believe - But now I'm not so sure
		// 	//In any case I perhaps need to crack std::pair first
		// }

		/* <<**------------------- MODIFIERS ------------------**>> */

		std::pair<iterator, bool>	insert (const value_type& val) {
			first = m_allocator.allocate(1); // Allocation is gonna have to be managed
			m_size++;
			// value_type dave = std::make_pair(val.first, val.second);
			m_allocator.construct(first, val);
			iterator it = begin();

			return std::make_pair(it, true);
		}



	private:
		// allocator_type		m_allocator;
		node_alloc			m_allocator;
		key_compare			_comp;
		size_type			m_size;
		mapnode				*first;
		// mapnode				last;
		// mapnode				tree;
		
		// pointer			data; //This has to be replaced by the binary tree nodes

		// Have to make a binary tree node class then
		

};

}
