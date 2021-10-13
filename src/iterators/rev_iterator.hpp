/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_iterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 15:27:43 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/13 12:16:17 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iterator>
# include "ra_iterator.hpp"

namespace ft {

template < class Iterator >
class	Rev_rai {
	public:
		typedef				Iterator					iterator_type;
		typedef typename	iterator_type::difference_type	difference_type;
		typedef typename 	iterator_type::reference		reference;
		typedef typename 	iterator_type::pointer			pointer;

		Rev_rai() : r_iterator() , current() {}
		explicit Rev_rai(iterator_type it) : r_iterator(it) , current(it) {}
		Rev_rai (const Rev_rai<Iterator>& rev_it) {
			*this = rev_it;
		}
		~Rev_rai () {}

		Rev_rai&	operator = (const Rev_rai &rhs) {
			if (this != &rhs)
				this->current = rhs.base();
			return *this;
		}
		Iterator	base() const {
			return current;
		}

		reference	operator * () const {
			Iterator temp = current;
			return *temp--;
		}
		pointer		operator -> () const {
			return &operator*();
		}

		Rev_rai&	operator ++ () {
			--current; 
			return *this;
		}
		Rev_rai	operator ++ (int) {
			Rev_rai temp(*this);
			++(*this);
			return temp;
		}
		Rev_rai&	operator -- () {
			--current;
			return *this;
		}
		Rev_rai	operator -- (int) {
			Rev_rai temp(*this);
			--(*this);
			return temp;
		}

		Rev_rai	operator + (difference_type	n) const {
			return Rev_rai(current - n);
		}

		Rev_rai& operator += (difference_type n) {
			current -= n;
			return *this;
		}

		Rev_rai	operator - (difference_type	n) const {
			return Rev_rai(current + n);
		}

		difference_type operator - (Rev_rai const &rhs) const {
			return rhs.base() - this->base();
		}

		Rev_rai& operator -= (difference_type n) {
			current += n;
			return *this;
		}

		reference	operator [] (difference_type n) const {
			return *(*this + n);
		}

		bool operator== (Rev_rai const &b) const { return this->base() == b.base(); }
		bool operator!= (Rev_rai const &b) const { return !(this->base() == b.base()); }
		bool operator < (Rev_rai const &b) const { return this->base > b.base(); }
		bool operator > (Rev_rai const &b) const { return this->base < b.base(); }
		bool operator >= (Rev_rai const &b) const { return this->base <= b.base(); }
		bool operator <= (Rev_rai const &b) const { return this->base >= b.base(); }

	private:
		Iterator		r_iterator;
	protected:
		Iterator	current;

};

template <class Iterator>
Rev_rai<Iterator>	operator +(typename	Rev_rai<Iterator>::difference_type off,
										const Rev_rai<Iterator> &it)
{
	return Rev_rai<Iterator>(it.base() - off);
}

}