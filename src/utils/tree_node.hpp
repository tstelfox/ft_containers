/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 13:50:54 by tmullan       #+#    #+#                 */
/*   Updated: 2021/11/01 16:30:27 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


template < class value_type >
class node {

	public:
		node*		parent;
		node*		left;
		node*		right;

		value_type	object;


		node() {}

		~node() {}
		
	private: // Maybe (?)
		
};
