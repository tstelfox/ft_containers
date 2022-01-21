/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 12:21:27 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/20 12:21:27 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "vector.hpp"
// #include <stack>

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {

	public:
		typedef	T			value_type;
		typedef	Container	container_type;
		typedef	size_t		size_type;

		explicit stack(const container_type &kontain = container_type()) : cntr(kontain) {}

		bool		empty() const { return cntr.empty(); }

		size_type	size() const { return cntr.size(); }

		value_type&	top() { return cntr.back(); }

		const value_type& top() const { return cntr.back(); }

		void		push(const value_type &val) { cntr.push_back(val); }

		void		pop() { cntr.pop_back(); }

		friend bool	operator== (const stack &lhs, const stack	&rhs) { return (lhs.cntr == rhs.cntr); }
		friend bool	operator< (const stack &lhs, const stack &rhs) { return (lhs.cntr < rhs.cntr); }

	private:
		container_type	cntr;
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
