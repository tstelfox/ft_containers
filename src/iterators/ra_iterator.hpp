/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra_iterator.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 17:23:20 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/11 15:51:27 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft {

template <typename T, typename Pointer, 
		typename Reference, class Category = std::random_access_iterator_tag>
class Raiterator {

	public:

		typedef	T			value_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
		typedef	ptrdiff_t	difference_type;
		typedef	Raiterator<T, Pointer, Reference> 				iterator;
		typedef	Raiterator<T, const T*, const T&>				const_iterator;

	public:
		Raiterator() : m_ptr(NULL) {}
		Raiterator(const pointer ptr) : m_ptr(ptr) {}
		Raiterator(const iterator& x) { *this = x; }
		virtual ~Raiterator() {}

		operator const_iterator() const { return (const_iterator(m_ptr)); }

		iterator&	operator = (const Raiterator &x) {
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
		iterator	operator ++ (int) {Raiterator temp = *this; ++(*this); return temp;}
		iterator	operator -- (int) {Raiterator temp = *this; --(*this); return temp;}

		iterator&	operator [] (int index) {return *(m_ptr + index);}

		iterator	operator + (difference_type off) const { iterator copy = *this; copy += off; return copy; }
		iterator&	operator += (difference_type off) { this->m_ptr += off; return *this; }

		iterator	operator - (difference_type off) const { iterator copy = *this; copy -= off; return copy; }
		iterator&	operator -= (difference_type off) {this->m_ptr -= off; return *this; }

		difference_type	operator - (iterator const &rhs) const { return (this->m_ptr - rhs.m_ptr); }
		

		bool operator== (Raiterator const& b) const { return m_ptr == b.m_ptr; }
		bool operator!= (Raiterator const& b) const { return m_ptr != b.m_ptr; }
		bool operator< (Raiterator const& b) const { return m_ptr < b.m_ptr; }
		bool operator> (Raiterator const& b) const { return m_ptr > b.m_ptr; }
		bool operator<= (Raiterator const& b) const { return m_ptr <= b.m_ptr; }
		bool operator>= (Raiterator const& b) const { return m_ptr >= b.m_ptr; }

	private:
		pointer m_ptr;
};

template <typename T, typename Pointer, 
		typename Reference>
Raiterator<T, Pointer, Reference>	operator +(typename	Raiterator<T, Pointer, Reference>::difference_type off,
										const Raiterator<T, Pointer, Reference> &it)
	{
		return it + off;
	}

}