/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/18 16:51:32 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <memory>
# include <utility>
# include <vector>
# include <iterator>
# include "ra_iterator.hpp"
# include "rev_iterator.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:

		typedef				Alloc							allocator_type;
		typedef				T								value_type;
		typedef				value_type&						reference;
		typedef				value_type const&				const_reference;
		typedef				value_type*						pointer;
		typedef				value_type const*				const_pointer;
		typedef				ptrdiff_t						difference_type;
		typedef				size_t							size_type;
		typedef				Raiterator<T, T*, T&>						iterator;
		typedef				Raiterator<T, T const*, T const&>			const_iterator;
		typedef				Rev_rai<iterator>							reverse_iterator;
		typedef				Rev_rai<const_iterator>						const_reverse_iterator;

		explicit vector(const allocator_type &alloc = allocator_type()) : allocator(alloc) , v_capacity(10) , v_size(0) {
			data = allocator.allocate(10); // Set it to allocate 10 as a default for now
		}
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
					: allocator(alloc) , v_capacity(n) , v_size(n) {
			data = allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				data[i] = val;
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : allocator(alloc) {
			difference_type r_size = last - first;
			data = allocator.allocate(r_size * 2);
			v_capacity = r_size * 2;
			v_size = r_size;
			int i = 0;
			while (first != last)
			{
				allocator.construct(&data[i], *first);
				first++;
				i++;
			}
		}

		vector (const vector &other) : allocator(other.allocator), v_capacity(other.v_capacity), v_size(other.v_size) {
			// Keeps a copy of other's allocator
			data = allocator.allocate(v_capacity);
			for (size_t i = 0; i < v_size; i++)
				allocator.construct(&data[i], other[i]);
		}

		~vector<T, Alloc>() {
			clear();
			allocator.deallocate(data, v_capacity);
		}

		vector&	operator = (const vector &other) {
			clear();
			v_size = other.v_size;
			if (v_size > v_capacity) {
				allocator.deallocate(data, v_capacity);
				v_capacity = v_size * 2;
				data = allocator.allocate(v_capacity);
			}
			for (size_t i = 0; i < v_size; i++)
				allocator.construct(&data[i], other[i]);
			return *this;
		}

		/* <<**------------------- ITERATORS ------------------**>> */

		iterator	begin() {
			return iterator(data);
		}
		const_iterator	begin() const {
			return const_iterator(data);
		}
		iterator	end() {
			return iterator(data + v_size);
		}
		const_iterator	end() const {
			return const_iterator(data + v_size);
		}
		
		reverse_iterator	rbegin() {
			return reverse_iterator(data + v_size - 1);
		}
		const_reverse_iterator	rbegin() const {
			return const_reverse_iterator(data + v_size - 1);
		}
		reverse_iterator	rend() {
			return reverse_iterator(data - 1);
		}
		const_reverse_iterator	rend() const {
			return const_reverse_iterator(data - 1);
		}

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
					reserve(n + v_capacity); // This may be reserving quite a lot sometimes but hmm
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

		template < class InputIterator >
		void	assign(InputIterator first, InputIterator last) {
			clear();
			v_size = last - first;
			if (v_size >= v_capacity) {
				reserve(v_size + v_capacity);
			}
			int i = 0;
			while (first != last) {
				allocator.construct(&data[i], *first);
				first++;
				i++;
			}
		}

		void	assign(size_type n, const value_type &val) { // Might need revisiting
			for (size_type i = 0; i < n; i++) {
				if (i >= v_capacity)
					reserve(n + v_capacity);
				allocator.destroy(&data[i]);
				allocator.construct(&data[i], val);
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
		// And there are three fucking types for faks seik
		iterator	insert(iterator position, value_type const &val) {
			// Dioporco questa é una rottura di cojoni
			v_size++;
			if (v_size > v_capacity)
				reserve(v_size * 2);
			iterator	og_pos = position;
			iterator next_pos = position + 1;
			while (next_pos != this->end()) {
				next_pos = position;
				position++;
				next_pos++;
			}
			pointer og_pointer = &(*og_pos);
			allocator.construct(og_pointer, val);
			return og_pos;
		}

		// erase does too
		// iterator	erase (iterator position) {
		// 	// For fucks sake this has to relocate everything in the array jesus christ my god che palle
		// }

		void	swap(vector& x) { // Swap here needs the assignation operator overload I feel
			vector	temp(x);
			x = *this;
			*this = temp;
		}

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

/* <<**------------------- Relational Operators ------------------**>> */

	// Honestly should write the iterators first

// template <class T, class Alloc> // Not sure this'll work
// bool	operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
// 	if (lhs.size() == rhs.size()) {
// 		size_type i = 0;
// 		size_type common_size = lhs.size();
// 		while (lhs[i] == rhs[i] && i < common_size)
// 			i++;
// 		if (i == common_size)
// 			return true;
// 	}
// 	return false;
// }

// template <class T, class Alloc>
// bool	operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
// 	return (!(lhs == rhs));
// }

// template <class T, class Alloc>
// bool	operator < (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
// 	size_type i = 0;
// }

}
