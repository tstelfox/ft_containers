/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bi_iterator.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:10:43 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/28 12:12:25 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft {

template <typename T, typename Pointer, 
		typename Reference, class Category = std::bidirectional_iterator_tag>
class Biditerator {

	public:

		typedef	T												value_type;
		typedef	Pointer											pointer;
		typedef	Reference										reference;
		typedef	Category										iterator_category;
		typedef	std::ptrdiff_t									difference_type;
		typedef	Biditerator<T, Pointer, Reference> 				iterator;
		typedef	Biditerator<T, const T*, const T&>				const_iterator;

	public:
		Biditerator() : m_ptr(NULL) {}
		Biditerator(const pointer ptr) : m_ptr(ptr) {}
		Biditerator(const iterator& x) { *this = x; }
		virtual ~Biditerator() {}

		operator const_iterator() const { return (const_iterator(m_ptr)); }

		iterator&	operator = (const Biditerator &x) {
			if (this != &x)
				this->m_ptr = x.m_ptr;
			return *this;
		}

		reference	operator * () const {return *m_ptr;}
		pointer		operator -> () {return m_ptr;}

		//Prefix increment/decrement
		iterator&	operator ++ () {m_ptr++; return *this;}
		iterator&	operator -- () {m_ptr--; return *this;}
		
		//Postfix increment/decrement
		iterator	operator ++ (int) {Biditerator temp = *this; ++(*this); return temp;}
		iterator	operator -- (int) {Biditerator temp = *this; --(*this); return temp;}
		

		//Is it fine to have these overloads within the class?
		bool operator== (Biditerator const& b) const { return m_ptr == b.m_ptr; }
		bool operator!= (Biditerator const& b) const { return m_ptr != b.m_ptr; }

	private:
		pointer m_ptr;
};

template <typename T, typename Pointer, 
		typename Reference>
Biditerator<T, Pointer, Reference>	operator +(typename	Biditerator<T, Pointer, Reference>::difference_type off,
										const Biditerator<T, Pointer, Reference> &it)
	{
		return it + off;
	}

}