/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bimap_iterator.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:10:43 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/17 17:53:29 by tmullan       ########   odam.nl         */
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
		bool operator== (Bimapiterator const& b) const { return m_ptr == b.m_ptr; }
		bool operator!= (Bimapiterator const& b) const { return m_ptr != b.m_ptr; }


	private:
		node_ptr m_ptr;
};


template < class Iterator >
class	Rev_bi {

	public:
		typedef				Iterator					iterator_type;
		typedef typename	iterator_type::difference_type	difference_type;
		typedef typename 	iterator_type::reference		reference;
		typedef typename 	iterator_type::pointer			pointer;

		//Constructors, = overload and base()
		Rev_bi() : current() {}
		
		explicit Rev_bi(iterator_type it) : current(it) {}

		template < class Iter >
		Rev_bi (Rev_bi<Iter> const &rev_it) : current(rev_it.base()) {}
		~Rev_bi () {}

		Rev_bi&	operator = (const Rev_bi &rhs) {
			if (this != &rhs)
				this->current = rhs.base();
			return *this;
		}
		Iterator	base() const {
			return current;
		}

		//Operators
		reference	operator * () const {
			Iterator temp = current;
			return *temp;
		}
		pointer		operator -> () const {
			return &operator*();
		}
		Rev_bi&	operator ++ () {
			--current; 
			return *this;
		}
		Rev_bi		operator ++ (int) {
			Rev_bi temp(*this);
			++(*this);
			return temp;
		}
		Rev_bi&	operator -- () {
			++current;
			return *this;
		}
		Rev_bi		operator -- (int) {
			Rev_bi temp(*this);
			--(*this);
			return temp;
		}

		bool operator== (Rev_bi const &b) const { return this->base() == b.base(); }
		bool operator!= (Rev_bi const &b) const { return !(this->base() == b.base()); }

	protected:
		Iterator	current;
};

}
