/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_iterator.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 17:23:20 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/11 14:58:32 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft {

template <typename T, typename Pointer, 
		typename Reference, class Category = std::random_access_iterator_tag>
class v_iterator {

	public:

		typedef	T			value_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
		typedef	ptrdiff_t	difference_type;
		typedef	v_iterator<T, Pointer, Reference> 				iterator;
		typedef	v_iterator<T, const T*, const T&>				const_iterator;

	public:
		v_iterator() : m_ptr(NULL) {}
		v_iterator(const pointer ptr) : m_ptr(ptr) {}
		v_iterator(const iterator& x) { *this = x; }
		virtual ~v_iterator() {}

		operator const_iterator() const { return (const_iterator(m_ptr)); }

		iterator&	operator = (const v_iterator &x) {
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
		iterator	operator ++ (int) {v_iterator temp = *this; ++(*this); return temp;}
		iterator	operator -- (int) {v_iterator temp = *this; --(*this); return temp;}

		//Ok I see now the requirements for the full random-access package shite
		//But how to actually implement all this shite?

		iterator&	operator [] (int index) {return *(m_ptr + index);}

		iterator	operator + (difference_type off) const { iterator copy = *this; copy += off; return copy; }
		iterator&	operator += (difference_type off) { this->m_ptr += off; return *this; }

		iterator	operator - (difference_type off) const { iterator copy = *this; copy -= off; return copy; }
		iterator&	operator -= (difference_type off) {this->m_ptr -= off; return *this; }

		difference_type	operator - (iterator const &rhs) const { return (this->m_ptr - rhs.m_ptr); }
		


		bool operator== (const v_iterator& b) const { return m_ptr == b.m_ptr; };
		bool operator!= (const v_iterator& b) const { return m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
};

template <typename T, typename Pointer, 
		typename Reference>
v_iterator<T, Pointer, Reference>	operator +(typename	v_iterator<T, Pointer, Reference>::difference_type off,
										const v_iterator<T, Pointer, Reference> &it)
	{
		return it + off;
	}

}