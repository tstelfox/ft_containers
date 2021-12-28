/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2021/12/28 18:13:48 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <memory>
#include <map>
#include "bimap_iterator.hpp"

namespace ft {


template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair<const Key, T> > >
class map
{
	public:

		typedef	Key													key_type;
		typedef	T													mapped_type;
		typedef std::pair<const key_type, mapped_type>				value_type;
		typedef	Compare												key_compare;
		typedef	Alloc												allocator_type;
		typedef	value_type&											reference;
		typedef	const value_type&									const_reference;
		typedef value_type*											pointer;
		typedef const value_type*									const_pointer;
		typedef	Bimapiterator<value_type, pointer, reference>		iterator;
		typedef	size_t												size_type;
		typedef	ptrdiff_t											difference_type;
		typedef node<value_type>						mapnode;
		typedef	typename Alloc::template rebind<mapnode>::other		node_alloc;

		class	value_compare : std::binary_function<value_type, value_type, bool> {
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool 		result_type;
				typedef value_type	first_argument_type;
				typedef	value_type	second_argument_type;
				bool operator () (value_type const &x, value_type const &y) const {
					return comp(x.first, y.first);
				}
		};

		explicit map(key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type())
				: m_allocator(alloc) , _comp(comp) , m_size(0), root(), first_node() {}

		// map(const map& x) {} // Dunno how the copy constructor is gonna look and may need iterators or may be able to just use insert()?

		~map() {}

		/* <<**------------------- ITERATORS ------------------**>> */

		iterator	begin() {
			mapnode *temp = root;
			while (temp->left) // There must be a cleaner way of doing this - like a smallest() function
				temp = temp->left;
			first_node = temp;
			return iterator(first_node); // Should begin at left-most leaf
		}

		// iterator	end() { // Bruh how do I even find the item PAST the end of the BST?

		// }

		/* <<**------------------- CAPACITY ------------------**>> */

		bool		empty() const {
			if (m_size == 0)
				return true;
			return false;
		}

		size_type	size() const {
			return m_size;
		}

		size_type	max_size() const {
			return m_allocator.max_size();
		}

		/* <<**------------------- ELEMENT ACCESS ------------------**>> */

		// mapped_type&	operator[] (key_type const &k) {
		// 	//Requires insert I believe - But now I'm not so sure
		// 	//In any case I perhaps need to crack std::pair first
		// }

		/* <<**------------------- MODIFIERS ------------------**>> */

		// If we attempt to pass something with same key to insert, it will not insert it.
		// std::pair<iterator, bool>	insert (const value_type& val) {

		// It inserts normally and then runs the fix_violations function
		// void		fix_violations(mapnode *&root, mapnode *&newnode) {
		// 	mapnode parent_node = NULL;
		// 	mapnode	grand_parent_node = NULL;

		// 	while ((newnode != root) && ())
		// }

		void		insert (const value_type& val) { // Could divide this up and make one part properly recursive
			if (m_size >= 1)
			{
				mapnode *temp = NULL;
				temp = m_allocator.allocate(1);
				mapnode *saved = root;
				m_size++;
				m_allocator.construct(temp, val);
				// std::cout << "\nTree branch after insertion currently" << std::endl;
				// std::cout << "Root node: " << temp->object.first << std::endl;
				// if (temp->parent)
				// 	std::cout << "And the parent is: " << temp->parent->object.first << std::endl;
				while (root) {
					if (!value_compare(_comp)(root->object, temp->object)) {
						if (root->left)
							root = root->left;
						else {
							temp->parent = root;
							root->left = temp;
							// std::cout << "And the parent is: " << temp->parent->object.first << std::endl;
							root = saved;
							break;
						}
					}
					else {
						if (root->right) {
							root = root->right;
						}
						else {
							temp->parent = root;
							root->right = temp;
							// std::cout << "And the parent is: " << temp->parent->object.first << std::endl;
							root = saved;
							break;
						}
					}
				}
			}
			else {
				root = m_allocator.allocate(1); // Allocation is gonna have to be managed
				m_size++;
				m_allocator.construct(root, val);
				root->colour = 'p';
			}
			// fix_violations(root, temp);
			// iterator it = begin(); // This needs fixed to point to the correct thing
			// return std::make_pair(it, true);
		}

		/* <<**------------------- TEEEEEEESTING ------------------**>> */

		void	print_next_nodes(mapnode *node, int i) {

			mapnode *temp_node = node;
			if (temp_node->left && temp_node->right)
				contents(temp_node, i, true);
			else if (temp_node->left)
				contents(temp_node->left, i - 10, false);
			else if (temp_node->right)
				contents(temp_node->right, i + 10, false);
		}

		void	contents(mapnode *root, int i, bool both) { // Now it prints out the tree as a diagram kinda
			mapnode *temp = root;

			if (both) {
				std::cout << std::endl << std::setw(i - 10) << temp->left->object.first << std::setw(20) << temp->right->object.first << std::endl;
				print_next_nodes(temp->left, i - 10);
				print_next_nodes(temp->right, i + 10);
			}
			else
			{
				std::cout << std::endl << std::setw(i) << temp->object.first << std::endl;
				if (temp->left && temp->right)
					print_next_nodes(temp, i);
				else if (temp->left) {
					// std::cout << temp->parent->object.second << " please work" << std::endl;
					contents(temp->left, i - 10, false);
				}
				else if (temp->right)
					contents(temp->right, i + 10, false);
			}
		}

		mapnode*	get_root() {
			return root;
		}

	private:
		node_alloc			m_allocator;
		key_compare			_comp;
		size_type			m_size;
		mapnode				*root;
		mapnode				*first_node;
		// mapnode				*last_node;
		
		

};

}
