/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_iterator.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 17:23:20 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/29 17:39:12 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft {

template <class value_type, class pointer, 
		class reference, class iterator_category = std::random_access_iterator_tag>
class v_iterator {

	public:

		typedef	v_iterator<const value_type, const pointer, const reference>	const_iterator;

	public:
		v_iterator(pointer ptr) : m_ptr(ptr) {}	

		reference	operator * () const {return *m_ptr;}
		pointer		operator -> () {return m_ptr;}

		//Prefix increment/decrement
		v_iterator&	operator ++ () {m_ptr++; return *this;}
		v_iterator&	operator -- () {m_ptr--; return *this;}
		
		//Postfix increment/decrement
		v_iterator	operator ++ (int) {v_iterator temp = *this; ++(*this); return temp;}
		v_iterator	operator -- (int) {v_iterator temp = *this; --(*this); return temp;}

		bool operator== (const v_iterator& b) const { return m_ptr == b.m_ptr; };
		bool operator!= (const v_iterator& b) const { return m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
};

}