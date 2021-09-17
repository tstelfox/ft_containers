/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/17 15:30:26 by tmullan       ########   odam.nl         */
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

		typedef				Alloc							allocator_type;
		typedef				T								value_type;
		typedef typename	allocator_type::reference		reference;
		typedef typename	allocator_type::const_reference	const_reference;
		typedef	typename	allocator_type::pointer			pointer;
		typedef	typename	allocator_type::const_pointer	const_pointer;


		vector<T, Alloc>() : capacity(10) , size(0) {
			array = allocator.allocate(10); // Set it to allocate 10 randomly for now
		}
		vector<T, Alloc>(unsigned int alloc_size) : capacity(alloc_size) , size(0) {
			array = allocator.allocate(alloc_size);
		}
		~vector<T, Alloc>() {
			allocator.deallocate(array, capacity);
		}
		
		void	push_back(T arg) {
			if (size == capacity)
				re_size();
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

		void	re_size() {
			T	*temp = allocator.allocate(capacity * 2);
			for (size_t i = 0; i < size; i++)
				temp[i] = array[i];
			allocator.deallocate(array, capacity);
			capacity *= 2;
			array = temp;
		}
};

}
