/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/23 10:56:59 by tmullan       ########   odam.nl         */
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
		typedef				value_type&						reference;
		typedef const		value_type&						const_reference;
		typedef				value_type*						pointer;
		typedef	const		value_type*						const_pointer;
		typedef				sign_type						size_t;

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

		// Gotta make const versions of these too

		reference	at(size_type n) {
			if (n >= v_size) {
				throw std::out_of_range("I'm out of range");
			}
			return (data[n]);
		}
		const_reference	at(size_type n) const {
			if (n >= v_size) {
				throw std::out_of_range("I'm out of range");
			}
			return (data[n]);
		}

		reference	front() {
			return data[0];
		}

		const_reference	front() const {
			return data[0];
		}
		
		reference back() {
			return data[v_size - 1];
		}

		const_reference back() const {
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

		reference	operator [](size_type n) {
			return data[n];
		}

		const_reference	operator [](size_type n) const {
			return data[n];
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
