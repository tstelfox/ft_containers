/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 12:21:27 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/13 20:43:07 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "vector.hpp"
#include "integral_enable.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {

	public:
		typedef	T			value_type;
		typedef	Container	container_type;
		typedef	size_t		size_type;

		explicit stack(const container_type &kontain = container_type()) : c(kontain) {}

		bool		empty() const { return c.empty(); }

		size_type	size() const { return c.size(); }

		value_type&	top() { return c.back(); }

		const value_type& top() const { return c.back(); }

		void		push(const value_type &val) { c.push_back(val); }

		void		pop() { c.pop_back(); }

		friend bool	operator== (const stack &lhs, const stack	&rhs) { return (lhs.c == rhs.c); }
		friend bool	operator< (const stack &lhs, const stack &rhs) { return (lhs.c < rhs.c); }

	protected:
		container_type	c;
};

// template <class T, class Container>
//   bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
// 	{ return x == y; }

// template <class T, class Container>
//   bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
// 	{ return x < y; }

template <class T, class Container>
  bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return !(x == y); }

template <class T, class Container>
  bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
	{ return !(x < y); }

template <class T, class Container>
  bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return (!(x < y) && !(x == y)); }

template <class T, class Container>
  bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return (!(x > y) && !(x == y)); }

// Relational operators to be added


}
