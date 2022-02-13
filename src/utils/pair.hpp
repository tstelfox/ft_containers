/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 15:47:26 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/13 20:07:59 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <utility>

namespace ft  {

template < class T1, class T2 >
struct pair
{
	typedef	T1	first_type;
	typedef	T2	second_type;

	pair() : first(), second() {}

	template<class U, class V>
	pair(const pair<U,V> &pr) : first(pr.first) , second(pr.second) {}
	template<class U, class V>
	pair(const std::pair<U,V> &pr) : first(pr.first) , second(pr.second) {}

	pair(const first_type &a, const second_type &b) : first(a) , second(b) {}

	pair&	operator = (const pair &pr) {
		if (this != &pr) {
			first = pr.first;
			second = pr.second;
		}
		return *this;
	}

	first_type	first;
	second_type	second;
};

template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

template <class T1, class T2>
	pair<T1,T2>	make_pair(T1 x, T2 y)
	{ return (pair<T1,T2>(x,y)); }

}
