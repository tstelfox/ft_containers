/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/17 12:34:49 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <utility>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:

		typedef	Alloc		allocator_type;
		typedef	T			value_type;

		vector<T, Alloc>() : capacity(10) , size(0) {
			array = allocator.allocate(10); // Set it to allocate 10 randomly for now
		}
		vector<T, Alloc>(unsigned int alloc_size) : capacity(alloc_size) , size(0) {
			array = allocator.allocate(alloc_size);
		}
		~vector<T, Alloc>() {
			// allocator.deallocate(array, 10);
		}
		
		void	push_back(T arg) {
			array[size] = arg;
			size++;
		}

		T const	back() {
			return array[size - 1];
		}

	private:
		value_type		*array;
		allocator_type	allocator;
		size_t			capacity;
		size_t			size;
};

}
