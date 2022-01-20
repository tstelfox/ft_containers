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

	private:
		// We'll see about the contents
};


}
