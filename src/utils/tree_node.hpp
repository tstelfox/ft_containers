/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 13:50:54 by tmullan       #+#    #+#                 */
/*   Updated: 2021/11/11 16:13:19 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


template < class value_type >
class node {

	public:

		// explicit node() : object(NULL) , parent(0), left(0), right(0)  {}
		explicit node(value_type const &val = value_type()) : object(val) , parent(0), left(0), right(0)  {}

		~node() {}


		node&	operator = (const node &other) {
			
			if (this != &other) {
				object = other.object;
				parent = other.parent;
				left = other.left;
				right = other.right;
			}
			return *this;
		}
		
		// value_type	*object; // For allocator
		value_type	object;
		node*		parent;
		node*		left;
		node*		right;
	private: // Maybe (?)
		
};
