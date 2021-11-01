/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 13:50:54 by tmullan       #+#    #+#                 */
/*   Updated: 2021/11/01 17:12:43 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


template < class value_type >
class node {

	public:

		explicit node(value_type const &val) : object(val) , parent(0), left(0), right(0)  {}

		~node() {}
		
	private: // Maybe (?)
		value_type	object;
		node*		parent;
		node*		left;
		node*		right;
		
};
