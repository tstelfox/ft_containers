/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/17 11:01:46 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:

		typedef	Alloc		allocator_type;
		typedef	T			value_type;

		vector<T, Alloc>() {
			array = allocator.allocate(10); // Set it to allocate 10 randomly for now
		}
		vector<T, Alloc>(unsigned int alloc_size) {
			array = allocator.allocate(alloc_size);
		}
		~vector<T, Alloc>() {
			allocator.deallocate(array, 10);
		}

	private:
		value_type		*array;
		allocator_type	allocator;
};

}
