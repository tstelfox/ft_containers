/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 13:50:54 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/03 18:43:23 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/

template < class value_type > // Have to add the comp here, maybe (?)
class node {

	public:

		// Create nodes as red/vermelho but have to figure out how to turn it black/preto if it's the root
		explicit node(value_type const &val = value_type()) :
			object(val) , parent(0), left(0), right(0), colour('r')  {} 

		node(const node& x) : object(x.object) , parent(x.parent) , left(x.left) , right(x.right) , colour(x.colour) {}

		~node() {}


		node&	operator = (const node &other) {	
			if (this != &other) {
				object = other.object;
				parent = other.parent;
				left = other.left;
				right = other.right;
				colour = other.colour;
			}
			return *this;
		}

		// https://courses.cs.vt.edu/~cs3114/Fall17/barnette/notes/Tree-Iterators.pdf
		node*	get_next_node() {

			node *it(this);

			// std::cout << "Hello??" << std::endl;
			if (it->right) {
				it = it->right;
				while (it->left) {
					it = it->left;
				}
			}
			else {
				node *temp = it;
				it = it->parent;
				while (temp != it->left) {
					temp = it;
					it = it->parent;
				}
			}
			std::cout << "Hello?? " << it->object.first << " " << it->object.second << std::endl;
			return (it);
		}

		// value_type	*object; // For allocator
		value_type	object;
		node*		parent;
		node*		left;
		node*		right;
		char		colour;
	private: // Maybe (?)
		
};
