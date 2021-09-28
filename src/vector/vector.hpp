/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/28 16:04:52 by tmullan       ########   odam.nl         */
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
	
		// Range constructor with Iterators

		// Copy constructor
		
		~vector<T, Alloc>() {
			allocator.deallocate(data, v_capacity);
		}

		// vector&	operator = (const vector& x) {}

		/* <<**------------------- ITERATORS ------------------**>> */

		// Errything

		/* <<**------------------- CAPACITY ------------------**>> */

		size_type	size() const {
			return v_size;
		}

		size_type	max_size() const {
			return allocator.max_size();
		}

		void	resize(size_type n, value_type val = value_type()) {
			while (n < v_size) {
				pop_back();
			}
			if (n > v_size) {
				if (n > v_capacity)
					reserve(n + v_capacity); // Pretty sure there must be a better way to do this but whatevs
				for (size_type i = v_size; i < n; i++) {
					data[i] = val;
					++v_size;
				}
			}
		}

		size_type	capacity() const {
			return v_capacity;
		}

		bool		empty() const {
			if (v_size == 0)
				return true;
			return false;
		}
		
		void	reserve(size_type n) {
			if (n > max_size())
				throw std::length_error("Too much memory to allocate");
			if (n > v_capacity) {
				pointer temp = allocator.allocate(n);
				for (size_type i = 0; i < v_size; i++)
					temp[i] = data[i];
				allocator.deallocate(data, v_capacity);
				data = temp;
				v_capacity = n;
			}
		}

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

		// assign with iterator

		void	assign(size_type n, const value_type &val) { // Might need revisiting
			for (size_type i = 0; i < n; i++) {
				if (i >= v_capacity)
					reserve(n + v_capacity);
				allocator.destroy(&data[i]);
				data[i] = allocator.construct(val);
			}
			v_size = n;
		}

		void	push_back(const value_type& val) {
			if (v_size >= v_capacity)
				reserve(v_capacity * 2);
			data[v_size] = val;
			++v_size;
		}

		void	pop_back() {
			allocator.destroy(&data[v_size]);
			--v_size;
		}

		// insert requires iterators

		// erase does too

		// void	swap(vector& x) { // Swap here needs the assignation operator overload I feel
		// 	vector	temp(size());
		// 	temp = *this;
		// 	*this = x;
		// 	x = temp;
		// }

		void	clear() {
			for (size_type i = v_size; i > 0; i--)
				allocator.destroy(&data[i - 1]);
			v_size = 0;
		}

		/* <<**------------------- ALLOCATOR ------------------**>> */

		allocator_type	get_allocator() const {
			return allocator;
		}

	private:
		pointer				data;
		allocator_type		allocator;
		size_type			v_capacity;
		size_type			v_size;

};

template <class T, class Alloc>
bool	operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	// This shit was more complicated than I thought. Should have read cplusplus.com more attentively
}

template <class T, class Alloc>
bool	operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	if (lhs == rhs)
		return false;
	return true;
}

template <class T, class Alloc>
bool	operator < (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	// How the hell do we determine size
}

}