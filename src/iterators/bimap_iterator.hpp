/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bimap_iterator.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:10:43 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/13 19:57:32 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <iterator>
#include "tree_node.hpp"
#include "rev_iterator.hpp"

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

		reference	operator * () const {return m_ptr->object;}
		pointer		operator -> () {return &(m_ptr->object);}

		node_ptr	get_node() {return m_ptr;}

		//Prefix increment/decrement
		iterator&	operator ++ () {m_ptr = m_ptr->get_next_node(); return *this;}
		// Need to implement get_next_node or some shit
		iterator&	operator -- () {m_ptr = m_ptr->get_prev_node(); return *this;}
		
		//Postfix increment/decrement
		iterator	operator ++ (int) {Bimapiterator temp = *this; ++(*this); return temp;}
		iterator	operator -- (int) {Bimapiterator temp = *this; --(*this); return temp;}

		//Is it fine to have these overloads within the class?
		template<typename T2, typename P, typename R, class C>
		friend inline bool operator== (const iterator& lhs, const Bimapiterator<T2, P, R, C>& rhs) { return lhs.m_ptr == rhs.m_ptr; }
		template<typename T2, typename P, typename R, class C>
		friend inline bool operator!= (const iterator& lhs, const Bimapiterator<T2, P, R, C>& rhs) { return lhs.m_ptr != rhs.m_ptr; }


	// private:
		node_ptr m_ptr;
};

}
