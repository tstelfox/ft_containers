/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/23 15:23:14 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

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
		typedef				size_t							size_type;

		explicit vector(const allocator_type &alloc = allocator_type()) : allocator(alloc) , v_capacity(10) , v_size(0) {
			data = allocator.allocate(10); // Set it to allocate 10 as a default for now
		}
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
					: allocator(alloc) , v_capacity(n) , v_size(n) {
			data = allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				data[i] = val;
		}
		// Other constructors must still be made

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

		/* <<**------------------- CAPACITY ------------------**>> */

		size_type	size() const {
			return v_size;
		}

		size_type	max_size() const {
			return allocator.max_size();
		}

		// void	resize(size_type n, value_type val = value_type()) {
		// 	while (n < v_size) {
		// 		// Yea actually really need some modifiers for this stuff
		// 	}
		// 	if (n > v_size) {
		// 		// Add n - v_size elements at the end initialised to val
		// 	}
		// 	// n can be larger than v_capacity which means reallocating
		// }

		size_type	capacity() const {
			return v_capacity;
		}


		bool		empty() const {
			if (v_size == 0)
				return true;
			return false;
		}
		
		//reserve

		/* <<**------------------- ELEMENT ACCESS ------------------**>> */

		reference	operator [](size_type n) {
			return data[n];
		}
		const_reference	operator [](size_type n) const {
			return data[n];
		}

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

		/* <<**------------------- MODIFIERS ------------------**>> */

		// assign

		void		push_back(const value_type& val) {
			if (v_size >= v_capacity)
				re_size();
			data[v_size] = val;
			v_size++;
		}

		void		pop_back() {
			allocator.destroy(&data[v_size]);
			v_size--;
		}

		allocator_type	get_allocator() const {
			return allocator;
		}

	private:
		pointer				data;
		allocator_type		allocator;
		size_type			v_capacity;
		size_type			v_size;

		void	re_size() { // Only resizes up
			int new_capacity = v_capacity * 2;
			if (new_capacity == 0)
				new_capacity = 10;
			pointer temp = allocator.allocate(new_capacity);
			for (size_t i = 0; i < v_size; i++)
				temp[i] = data[i];
			allocator.deallocate(data, v_capacity); // This might be zero, see what happens
			v_capacity = new_capacity;
			data = temp;
		}
};

}
