/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/21 16:12:13 by tmullan       ########   odam.nl         */
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


		vector<T, Alloc>() : capacity(10) , v_size(0) {
			data = allocator.allocate(10); // Set it to allocate 10 as a default for now
		}
		vector<T, Alloc>(unsigned int alloc_size) : capacity(alloc_size) , v_size(0) {
			data = allocator.allocate(alloc_size);
		}
		~vector<T, Alloc>() {
			allocator.deallocate(data, capacity);
		}

		void		push_back(const T &arg) {
			if (v_size >= capacity)
				re_size();
			data[v_size] = arg;
			v_size++;
		}

		const T&	back() {
			return data[v_size - 1];
		}

		const	size_t&	size() {
			return v_size;
		}

		T&	operator [](size_t index) {
			if (index >= v_size)
				throw std::runtime_error("Out of bounds access attempt");
			return data[index];
		}

	private:
		value_type		*data;
		allocator_type	allocator;
		size_t			capacity;
		size_t			v_size;

		void	re_size() { // Only resizes up
			T	*temp = allocator.allocate(capacity * 2);
			for (size_t i = 0; i < v_size; i++)
				temp[i] = data[i];
			allocator.deallocate(data, capacity);
			capacity *= 2;
			data = temp;
		}
};

}
