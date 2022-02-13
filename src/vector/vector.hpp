/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/13 19:53:35 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <memory>
# include <utility>
# include <vector>
# include <iterator>
# include <algorithm>
# include "ra_iterator.hpp"
# include "rev_iterator.hpp"
# include "equal_lexographical_compare.hpp"
// # include "cpp_eleven_shiz.hpp"

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
		typedef				std::ptrdiff_t					difference_type;
		typedef				size_t							size_type;
		typedef				Raiterator<T, T*, T&>						iterator;
		typedef				Raiterator<T, T const*, T const&>			const_iterator;
		typedef				rev_iterator<iterator>							reverse_iterator;
		typedef				rev_iterator<const_iterator>						const_reverse_iterator;

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
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = NULL) : allocator(alloc) {
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
			// std::cout << "In here too?" << std::endl;
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
		void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = NULL) {
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

		void	assign(size_type n, const value_type &val) {
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

		iterator	insert(iterator position, value_type const &val) {
			v_size++;
			if (v_size > v_capacity)
				reserve(v_size * 2);
			iterator next_pos = this->end() - 1;
			while (next_pos != position) {
				allocator.construct(&(*next_pos), *(next_pos - 1));
				next_pos--;
			}
			allocator.construct(&(*position), val);
			return position;
		}

		void		insert(iterator position, size_type n, value_type const &val) {
			v_size += n;
			if (v_size > v_capacity)
				reserve(v_size * 2);
			iterator next_pos = this->end() - 1;
			iterator final_pos = position + n;
			while (next_pos + 1 != final_pos) {
				allocator.construct(&(*next_pos), *(next_pos - n));
				next_pos--;
			}
			while (position != final_pos) {
				allocator.construct(&(*position), val);
				position++;
			}
		}

		template < class InputIterator >
		void		insert(iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = NULL) {
			difference_type	n = last - first;
			v_size += n;
			if (v_size > v_capacity)
				reserve(v_size * 2);
			iterator next_pos = this->end() - 1;
			iterator final_pos = position + n;
			while (next_pos + 1 != final_pos) {
				allocator.construct(&(*next_pos), *(next_pos - n));
				next_pos--;
			}
			while (position != final_pos) {
				allocator.construct(&(*position), *(first));
				position++;
				first++;
			}
		}

		iterator	erase(iterator position) {
			allocator.destroy(&(*position));
			iterator end_pos = this->end() - 1;
			iterator og_pos = position;
			while (position != end_pos) {
				allocator.construct(&(*position), *(position + 1));
				position++;
			}
			v_size--;
			return og_pos;
		}

		iterator	erase(iterator first, iterator last) {
			difference_type diff = last - first;
			iterator og_pos = first;
			for (difference_type i = 0; i < diff; i++) {
				allocator.destroy(&(*first));
				first++;
			}
			first = og_pos;
			iterator end_pos = this->end() - 1;
			while (og_pos != end_pos) {
				allocator.construct(&(*og_pos), *(og_pos + diff));
				og_pos++;
			}
			v_size -= diff;
			return first;
		}

		void	swap(vector& x) {
			std::swap(data, x.data);
			std::swap(allocator, x.allocator);
			std::swap(v_capacity, x.v_capacity);
			std::swap(v_size, x.v_size);
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

template <class T, class Alloc>
bool	operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool	operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool	operator < (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	
	return (ft::lexographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool	operator > (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	operator <= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool	operator >= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return !(lhs < rhs);
}

template < class T, class Alloc >
void	swap (vector<T, Alloc> &x, vector<T, Alloc> &y) {
	x.swap(y);
}

}