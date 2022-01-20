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

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {

	public:
		typedef	T			value_type;
		typedef	Container	container_type;
		typedef	size_t		size_type;

		explicit stack(const container_type &cntr = container_type()) this->cntr(cntr) {}

		bool		empty() const { return cntr.empty(); }

		size_type	size() const { return cntr.size(); }

		value_type&	top() { return cntr.back(); }

		const value_type& top() const { return cntr.back(); }

		void		push(const value_type &val) { cntr.push_back(val); }

		void		pop() { cntr.pop_back(); }

	private:
		container_type	cntr;
};


}
