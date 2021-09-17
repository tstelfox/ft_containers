/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/17 15:40:35 by tmullan       ########   odam.nl         */
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
			data = allocator.allocate(10); // Set it to allocate 10 as a default for now
		}
		vector<T, Alloc>(unsigned int alloc_size) : capacity(alloc_size) , size(0) {
			data = allocator.allocate(alloc_size);
		}
		~vector<T, Alloc>() {
			allocator.deallocate(data, capacity);
		}

		void		push_back(const T &arg) {
			if (size >= capacity)
				re_size();
			data[size] = arg;
			size++;
		}

		const T&	back() {
			return data[size - 1];
		}

		T&	operator [](size_t index) {
			if (index >= size)
				throw std::runtime_error("Out of bounds access attempt");
			return data[index];
		}

	private:
		value_type		*data;
		allocator_type	allocator;
		size_t			capacity;
		size_t			size;

		void	re_size() { // Only resizes up
			T	*temp = allocator.allocate(capacity * 2);
			for (size_t i = 0; i < size; i++)
				temp[i] = data[i];
			allocator.deallocate(data, capacity);
			capacity *= 2;
			data = temp;
		}
};

}
