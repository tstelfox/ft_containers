/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_iterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 15:27:43 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/13 13:30:05 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iterator>
# include "ra_iterator.hpp"
# include "iterator_traits.hpp"

namespace ft {

template < class Iterator >
class	rev_iterator {
	public:
		typedef typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename	ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename	ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename	ft::iterator_traits<Iterator>::reference			reference;
		typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef				Iterator					iterator_type;
		// typedef typename	iterator_type::difference_type	difference_type;
		// typedef typename 	iterator_type::reference		reference;
		// typedef typename 	iterator_type::pointer			pointer;

		//Constructors, = overload and base()
		rev_iterator() : current() {}
		
		explicit rev_iterator(iterator_type it) : current(it) {}

		template < class Iter >
		rev_iterator (rev_iterator<Iter> const &rev_it) : current(rev_it.base()) {}
		~rev_iterator () {}

		rev_iterator&	operator = (const rev_iterator &rhs) {
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
		rev_iterator&	operator ++ () {
			--current; 
			return *this;
		}
		rev_iterator		operator ++ (int) {
			rev_iterator temp(*this);
			++(*this);
			return temp;
		}
		rev_iterator&	operator -- () {
			++current;
			return *this;
		}
		rev_iterator		operator -- (int) {
			rev_iterator temp(*this);
			--(*this);
			return temp;
		}
		rev_iterator		operator + (difference_type	n) const {
			return rev_iterator(current - n);
		}
		rev_iterator& 	operator += (difference_type n) {
			current -= n;
			return *this;
		}
		rev_iterator		operator - (difference_type	n) const {
			return rev_iterator(current + n);
		}
		difference_type operator - (rev_iterator const &rhs) const {
			return rhs.base() - this->base();
		}
		rev_iterator& 	operator -= (difference_type n) {
			current += n;
			return *this;
		}
		reference	operator [] (difference_type n) const {
			return *(*this + n);
		}

		bool operator== (rev_iterator const &b) const { return this->base() == b.base(); }
		bool operator!= (rev_iterator const &b) const { return !(this->base() == b.base()); }
		bool operator < (rev_iterator const &b) const { return this->base > b.base(); }
		bool operator > (rev_iterator const &b) const { return this->base < b.base(); }
		bool operator >= (rev_iterator const &b) const { return this->base <= b.base(); }
		bool operator <= (rev_iterator const &b) const { return this->base >= b.base(); }

	protected:
		Iterator	current;

};

template <class Iterator>
rev_iterator<Iterator>	operator +(typename	rev_iterator<Iterator>::difference_type off,
										const rev_iterator<Iterator> &it)
{
	return rev_iterator<Iterator>(it.base() - off);
}

}