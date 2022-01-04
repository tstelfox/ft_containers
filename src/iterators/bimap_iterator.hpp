/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bimap_iterator.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:10:43 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/04 14:54:47 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>
#include "tree_node.hpp"

namespace ft {

template <typename T, typename Pointer, 
		typename Reference, class Category = std::bidirectional_iterator_tag>
class Bimapiterator {

	public:

		typedef	T												value_type;
		typedef	Pointer											pointer;
		typedef	Reference										reference;
		typedef	Category										iterator_category;
		typedef	std::ptrdiff_t									difference_type;
		typedef node<value_type>*								node_ptr;
		typedef	Bimapiterator<T, Pointer, Reference> 			iterator;
		typedef	Bimapiterator<T, const T*, const T&>			const_iterator;
		// typedef	node<value_type>*								node_pointer;

	public:
		Bimapiterator() : m_ptr(NULL) {}
		Bimapiterator(const node_ptr ptr) : m_ptr(ptr) {}
		Bimapiterator(const iterator& x) { *this = x; }
		virtual ~Bimapiterator() {}

		operator const_iterator() const { return (const_iterator(m_ptr)); }

		iterator&	operator = (const Bimapiterator &x) {
			if (this != &x)
				this->m_ptr = x.m_ptr;
			return *this;
		}

		reference	operator * () const {return *m_ptr;}
		node_ptr	operator -> () {return m_ptr;}

		//Prefix increment/decrement
		iterator&	operator ++ () {m_ptr = m_ptr->get_next_node(); return *this;}
		// Need to implement get_next_node or some shit
		iterator&	operator -- () {m_ptr = m_ptr->get_prev_node(); return *this;}
		
		//Postfix increment/decrement
		iterator	operator ++ (int) {Bimapiterator temp = *this; ++(*this); return temp;}
		iterator	operator -- (int) {Bimapiterator temp = *this; --(*this); return temp;}
		

		//Is it fine to have these overloads within the class?
		bool operator== (Bimapiterator const& b) const { return m_ptr == b.m_ptr; }
		bool operator!= (Bimapiterator const& b) const { return m_ptr != b.m_ptr; }

	private:
		node_ptr m_ptr;
};

// template <typename T, typename Pointer, 
// 		typename Reference>
// Bimapiterator<T, Pointer, Reference>	operator +(typename	Bimapiterator<T, Pointer, Reference>::difference_type off,
// 										const Bimapiterator<T, Pointer, Reference> &it)
// 	{
// 		return it + off;
// 	}

}