/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_iterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 15:27:43 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/12 15:54:15 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iterator>
# include "ra_iterator.hpp"

namespace ft {

template < class Raiterator >
class	Rev_rai {
	public:
		typedef				Raiterator					iterator_type;
		typedef typename	Raiterator::difference_type	difference_type;
		typedef typename 	Raiterator::reference		reference;
		typedef typename 	Raiterator::pointer			pointer;

		Rev_rai() : r_ptr() , current() {}
		explicit Rev_rai(iterator_type it) : r_ptr(it) , current(it) {}
		template <class Raiterator>
			Rev_rai (const Rev_rai<Raiterator>& rev_it) {}
		Rev_rai&	operator = (const Rev_rai &rhs) {
			if (this != &rhs)
				this->current = rhs.base();
			return *this;
		}
		Raiterator	base() const {
			return current;
		}


	protected:
		Raiterator	current;

	private:
		pointer		r_ptr;
};

}