/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/22 15:01:47 by tmullan       ########   odam.nl         */
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


		vector<T, Alloc>() : v_capacity(10) , v_size(0) {
			data = allocator.allocate(10); // Set it to allocate 10 as a default for now
		}
		vector<T, Alloc>(unsigned int alloc_size) : v_capacity(alloc_size) , v_size(0) {
			data = allocator.allocate(alloc_size);
		}

		// RIGHT WILL RETURN TO THE COPY CONSTRUCTOR CAUSE IT FUCKIN WITHN ME
		
		// vector<T, Alloc>(const vector &other) {
		// 	*this = other;
		// }
		// vector&	operator = (const vector &rhs) {
		// 	this->data = new T[rhs.v_capacity];
		// 	this->allocator = rhs.allocator;
		// 	this->v_capacity = rhs.v_capacity;
		// 	this->v_size = rhs.v_size;
		// 	this->data = rhs.data;
		// 	return *this;
		// }
		
		~vector<T, Alloc>() {
			allocator.deallocate(data, v_capacity);
		}

		void		push_back(const T &arg) {
			if (v_size >= v_capacity)
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
		const	size_t&	max_size() {
			return allocator.max_size();
		}

		const	size_t& capacity() {
			return v_capacity;
		}

		T&	operator [](size_t index) {
			if (index >= v_size)
				throw std::runtime_error("Out of bounds access attempt");
			return data[index];
		}

	private:
		value_type		*data;
		allocator_type	allocator;
		size_t			v_capacity;
		size_t			v_size;

		void	re_size() { // Only resizes up
			T	*temp = allocator.allocate(v_capacity * 2);
			for (size_t i = 0; i < v_size; i++)
				temp[i] = data[i];
			allocator.deallocate(data, v_capacity);
			v_capacity *= 2;
			data = temp;
		}
};

}
