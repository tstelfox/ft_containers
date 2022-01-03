/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 13:50:54 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/03 17:14:20 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// https://www.geeksforgeeks.org/red-black-tree-set-2-insert/
// https://proprogramming.org/red-black-treerb-tree-implementation-in-c/
// https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/

template < class value_type > // Have to add the comp here, maybe (?)
class node {

	public:

		// Create nodes as red/vermelho but have to figure out how to turn it black/preto if it's the root
		explicit node(value_type const &val = value_type()) :
			object(val) , parent(0), left(0), right(0), colour('r')  {} 

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

		// void	insert_node(node *new_node) {
		// 	if (key_compare(this->object.first, new_node.first)) {
		// 		std::cout << "It's larger" << std::endl;

		// 	}
		// }

		// node*	get_next_node() {

		// 	// Has to find the next largest node (parent if it has no children.)
		// }

		// value_type	*object; // For allocator
		value_type	object;
		node*		parent;
		node*		left;
		node*		right;
		char		colour;
	private: // Maybe (?)
		
};
