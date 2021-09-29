/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   random_access_iterator.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 17:23:20 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/29 12:32:31 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft {

template <class value_type, class difference_type, 
		class pointer, class reference, class iterator_category = std::random_access_iterator_tag>
class v_iterator {

	public:
		v_iterator(pointer ptr) : m_ptr(ptr) {}	

		reference	operator * () const {return *m_ptr;}
		pointer		operator -> () {return m_ptr;}

		//Prefix increment
		v_iterator&	operator ++ () {m_ptr++; return *this;}

		//Postfix increment
		v_iterator	operator ++ (int) {v_iterator temp = *this; ++(*this); return temp;}

		friend bool operator== (const v_iterator& a, const v_iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const v_iterator& a, const v_iterator& b) { return a.m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
};

}