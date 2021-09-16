/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/16 12:24:19 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	private:
		T		value_type;
		Alloc<T>	allocator_type;
		allocator_type::reference	reference;
	public:
		vector<T>();
		~vector<T>();
};

}
