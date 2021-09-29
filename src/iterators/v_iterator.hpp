/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_iterator.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 17:23:20 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/29 19:09:02 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft {

template <class value_type, class pointer, 
		class reference, class iterator_category = std::random_access_iterator_tag>
class v_iterator {

	public:

		typedef	v_iterator<value_type, pointer, reference> 				iterator;
		typedef	v_iterator<value_type, const value_type *, const value_type &>	const_iterator;

	public:
		v_iterator() : m_ptr(NULL) {}
		v_iterator(const pointer ptr) : m_ptr(ptr) {}
		v_iterator(const iterator& x) : m_ptr(const_cast<pointer>(x.m_ptr)) {}
		~v_iterator() {}

		reference	operator * () const {return *m_ptr;}
		pointer		operator -> () {return m_ptr;}

		//Prefix increment/decrement
		v_iterator&	operator ++ () {m_ptr++; return *this;}
		v_iterator&	operator -- () {m_ptr--; return *this;}
		
		//Postfix increment/decrement
		v_iterator	operator ++ (int) {v_iterator temp = *this; ++(*this); return temp;}
		v_iterator	operator -- (int) {v_iterator temp = *this; --(*this); return temp;}

		//Ok I see now the requirements for the full random-access package shite

		bool operator== (const v_iterator& b) const { return m_ptr == b.m_ptr; };
		bool operator!= (const v_iterator& b) const { return m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
};

}