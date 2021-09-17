/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/17 10:15:09 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	private:
		T					*value_type;
		Alloc				allocator_type;
	public:
		vector<T, Alloc>() {
			value_type = allocator_type.allocate(10); // Set it to allocate 10 randomly for now
		}
		vector<T, Alloc>(unsigned int alloc_size) {
			value_type = allocator_type.allocate(alloc_size);
		}
		~vector<T, Alloc>() {
			allocator_type.deallocate(value_type, 10);
		}
};

}
