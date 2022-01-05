/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 13:50:54 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/04 18:33:33 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/

template < class value_type > // Have to add the comp here, maybe (?)
class node {

	public:

		// Create nodes as red/vermelho
		explicit node(value_type const &val = value_type()) :
			object(val) , parent(0), left(0), right(0), colour('r') , _final(false) {} 

		node(bool empty) : object() , parent(0), left(0), right(0), colour('r') , _final(empty) {}

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

			// There is an issue somewhere between here and the rotations
			// if (it->right->_final)
			// 	return it->right;
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
			return (it);
		}

		node*	get_prev_node() {
			node *it(this);

			if (it->left) {
				it = it->left;
				while (it->right)
					it = it->right;
			}
			else {
				node *temp = it;
				it = it->parent;
				while (temp != it->right) {
					temp = it;
					it = it->parent;
				}
			}
			return (it);		
		}

		// value_type	*object; // For allocator
		value_type	object;
		node*		parent;
		node*		left;
		node*		right;
		char		colour;
		bool		_final;
	private: // Maybe (?)
		
};
