/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/11 18:57:18 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <memory>
#include <map>
#include "bimap_iterator.hpp"
#include "colours.hpp"



#define	BLACK	'b'
#define	RED		'r'

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
		typedef	Bimapiterator<value_type, const_pointer, const_reference>	const_iterator;
		typedef Rev_bi<iterator>									reverse_iterator;
		typedef	Rev_bi<const_iterator>								const_reverse_iterator;
		typedef	size_t												size_type;
		typedef	ptrdiff_t											difference_type;
		typedef node<value_type>									mapnode;
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
				: m_allocator(alloc) , _comp(comp) , m_size(0), root(), first_node(), last_node() {
					init_first_last();
				}

		// map(const map& x) {} // Dunno how the copy constructor is gonna look and may need iterators or may be able to just use insert()?

		~map() {}

		// map&	operator = (const map &x) {
		// 	// Will probably need to use this->erase() and stuff to reassign;
		// }

		/* <<**------------------- ITERATORS ------------------**>> */

		iterator	begin() {
			return iterator(first_node);
		}

		iterator begin() const {
			return const_iterator(first_node);
		}

		reverse_iterator	rbegin() {
			return reverse_iterator(_end->parent);
		}

		const_reverse_iterator	rbegin() const {
			return const_reverse_iterator(_end->parent);
		}

		iterator	end() {
			return iterator(_end);
		}

		const_iterator	end() const {
			return const_iterator(_end);
		}

		reverse_iterator	rend() {
			return reverse_iterator(_begin);
		}

		const_reverse_iterator	rend() const {
			return const_reverse_iterator(_end->parent);
		}

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

		mapped_type&	operator[] (key_type const &k) {
			return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
		}

		/* <<**------------------- MODIFIERS ------------------**>> */

		// If we attempt to pass something with same key to insert, it will not insert it.
		// std::pair<iterator, bool>	insert (const value_type& val) {

		// Something is wrong because it's forgetting half the tree lol

		void		right_rotate(mapnode *&root, mapnode *&newnode)
		{
			mapnode *left_child = newnode->left;

			newnode->left = left_child->right;
			if (newnode->left != NULL)
				newnode->left->parent = newnode;
			
			left_child->parent = newnode->parent;

			if (newnode->parent == NULL)
				root = left_child;
			else if (newnode == newnode->parent->left)
				newnode->parent->left = left_child;
			else
				newnode->parent->right = left_child;
			left_child->right = newnode;
			newnode->parent = left_child;
		}

		void		left_rotate(mapnode *&root, mapnode *&newnode)
		{
			mapnode *right_child = newnode->right;

			newnode->right = right_child->left;

			if (newnode->right != NULL)
				newnode->right->parent = newnode;
			
			right_child->parent = newnode->parent;

			if (newnode->parent == NULL)
				root = right_child;
			else if (newnode == newnode->parent->left)
				newnode->parent->left = right_child;
			else
				newnode->parent->right = right_child;

			right_child->left = newnode;
			newnode->parent = right_child;
		}

		void		fix_violations(mapnode *&root, mapnode *&newnode) 
		{
			mapnode *p_node = NULL;
			mapnode	*gp_node = NULL;

			while ((newnode != root) && (newnode->colour != BLACK) &&
					(newnode->parent->colour == RED))
			{
				p_node = newnode->parent;
				gp_node = newnode->parent->parent;
				/* Case A
					Parent of newnode is left-child of grandparent of newnode */
				if (p_node == gp_node->left)
				{
					mapnode *uncle_node = gp_node->right;
					/* Case alpha
						Uncle of node is also RED
						Only recolouring required */
					if (uncle_node != NULL && uncle_node->colour == RED && !uncle_node->_delimit)
					{
						gp_node->colour = RED;
						p_node->colour = BLACK;
						uncle_node->colour = BLACK;
						newnode = gp_node;
					}
					else
					{
						/* Case Beta
							newnode is right child of its parent
							left-rotation required */
						if (newnode == p_node->right)
						{
							left_rotate(root, p_node);
							newnode = p_node;
							p_node = newnode->parent;
						}
						/* case Gamma
							newnode is left child of its parent
							right-rotation required */
						right_rotate(root, gp_node);
						std::swap(p_node->colour, gp_node->colour);
						newnode = p_node;
					}
				}
				/* Case B
					Parent of newnode is right child of grandparent */
				else
				{
					mapnode *uncle_node = gp_node->left;
					/* Case alpha
						Uncle of node is also RED
						Only recolouring required */
					if (uncle_node != NULL && uncle_node->colour == RED && !uncle_node->_delimit)
					{
						gp_node->colour = RED;
						p_node->colour = BLACK;
						uncle_node->colour = BLACK;
						newnode = gp_node;
					}
					else
					{
						/* case Gamma
							newnode is left child of its parent
							right-rotation required */
						if (newnode == p_node->left)
						{
							right_rotate(root, p_node);
							newnode = p_node;
							p_node = newnode->parent;
						}
						/* Case Beta
							newnode is right child of its parent
							left-rotation required */
						left_rotate(root, gp_node);
						std::swap(p_node->colour, gp_node->colour);
						newnode = p_node;
					}
				}
				
			}
			root->colour = BLACK;
		}


		std::pair<iterator, bool>	insert(const value_type& val) { // Could divide this up and make one part properly recursive
			if (m_size >= 1)
			{
				mapnode *temp = NULL;
				temp = m_allocator.allocate(1);
				mapnode *saved = root;
				m_size++;
				m_allocator.construct(temp, val);
				while (root) {
					// std::cout << "PRESUME here?" << std::endl;
					if (root->object.first == temp->object.first) {
						m_allocator.deallocate(temp, 1);
						std::pair<iterator, bool> ret = std::make_pair(iterator(root), false);
						root = saved;
						return ret;
					}
 					if (value_compare(_comp)(temp->object, root->object)) {
					// if (_comp(temp->object, root->object)) {
						if (root->left && !root->left->_delimit)
							root = root->left;
						else {
							temp->parent = root;
							root->left = temp;
							root = saved;
							break;
						}
					}
					else {
						if (root->right && !root->right->_delimit) {
							root = root->right;
						}
						else {
							temp->parent = root;
							root->right = temp;
							root = saved;
							break;
						}
					}
				}
				fix_violations(root, temp);
				first_and_last();
				return std::make_pair(iterator(temp), true);
			}
			else {
				root = m_allocator.allocate(1);
				m_size++;
				m_allocator.construct(root, val);
				root->colour = BLACK;
				first_node = root;
				last_node = root;
				root->right = _end;
				return std::make_pair(iterator(root), true);
				// Boh, need to check first_node and last_node in this situation
			}// This needs fixed to point to the correct thing
			// return std::make_pair(iterator(temp), true);
		}

		/* <<**------------------- OBSERVERS ------------------**>> */

		key_compare		key_comp() const { return (_comp); }

		value_compare	value_comp() const { return (value_compare(_comp)); }

		/* <<**------------------- OPERATIONS ------------------**>> */

		iterator	find(const key_type &k) {
			mapnode *temp = root;

			while (temp && temp != _end && temp != _begin) {
				if (_comp(k, temp->object.first))
					temp = temp->left;
				else if (_comp(temp->object.first, k))
					temp = temp->right;
				else return iterator(temp);
			}
			return end();
		}

		const_iterator	find(const key_type &k) const {
			mapnode *temp = root;

			while (temp && temp != _end && temp != _begin) {
				if (_comp(k, temp->object.first))
					temp = temp->left;
				else if (_comp(temp->object.first, k))
					temp = temp->right;
				else return const_iterator(temp);
			}
			return end();
		}

		size_type		count(const key_type &k) const {
			if (find(k) != end())
				return 1;
			else
				return 0;
		}
		// Gonna almost certainly need iterators for this

		/* <<**------------------- ALLOCATOR ------------------**>> */

		allocator_type	get_allocator() const {
			return m_allocator;
		}

		/* <<**------------------- TEEEEEEESTING ------------------**>> */

		// void	print_next_nodes(mapnode *node, int i) {
		// 	mapnode *temp_node = node;
		// 	if (temp_node->left && temp_node->right)
		// 		contents(temp_node, i, true);
		// 	else if (temp_node->left)
		// 		contents(temp_node->left, i - 10, false);
		// 	else if (temp_node->right)
		// 		contents(temp_node->right, i + 10, false);
		// }

		// void	contents(mapnode *root, int i, bool both) { // Now it prints out the tree as a diagram kinda
		// 	mapnode *temp = root;

		// 	if (both) {
		// 		std::cout << std::endl << std::setw(i - 10) << temp->left->object.first << std::setw(20) << temp->right->object.first << std::endl;
		// 		print_next_nodes(temp->left, i - 10);
		// 		print_next_nodes(temp->right, i + 10);
		// 	}
		// 	else
		// 	{
		// 		std::cout << std::endl << std::setw(i) << temp->object.first << std::endl;
		// 		if (temp->left && temp->right)
		// 			print_next_nodes(temp, i);
		// 		else if (temp->left) {
		// 			// std::cout << temp->parent->object.second << " please work" << std::endl;
		// 			contents(temp->left, i - 10, false);
		// 		}
		// 		else if (temp->right)
		// 			contents(temp->right, i + 10, false);
		// 	}
		// }

		void		first_and_last() {
			mapnode *temp = root;

			while (temp->left && !temp->left->_delimit)
				temp = temp->left;
			first_node = temp;
			first_node->left = _begin;
			_begin->parent = first_node;
			temp = root;
			while (temp->right && !temp->right->_delimit)
				temp = temp->right;
			last_node = temp;
			_end->parent = last_node;
			last_node->right = _end;
		}

		void	init_first_last() {
			_end = m_allocator.allocate(1);
			m_allocator.construct(_end, true);
			_begin = m_allocator.allocate(1);
			m_allocator.construct(_begin, true);
			// first_node = m_allocator.allocate(1);
			first_node = _end;
			// first_node->parent = _end;

			// // std::cout << _end->_delimit << std::endl;
			// first_node = m_allocator.allocate(1);
			// _end->parent = first_node;
			// first_node->parent = _end;
		}

		void printBT() const {
			printBT("", this->root, false);
			std::cerr << std::endl;
		}
		
		void printBT(const std::string& prefix, const mapnode* trav, bool isLeft) const {
			// std::cout << last_node->object.first << std::endl;
			// std::cout << first_node->object.first << std::endl;
			// Hmmmm
			// if (trav && trav != first_node && trav != last_node) {
			if (trav && trav != _end && trav != _begin) {
					std::cerr << prefix;
					std::cerr << (isLeft ? "├L─" : "└R-" );
					// print the value of the node
					if (trav->colour == RED)
						std::cerr << ROSSO;
					else if (trav->colour == BLACK)
						std::cerr << _IWHITE << GREY;
					std::cerr << trav->object.first << END << std::endl ;
					// enter the next tree level - left and right branch
					printBT( prefix + (isLeft ? "│   " : "    "), trav->left, true);
					printBT( prefix + (isLeft ? "│   " : "    "), trav->right, false);
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
		mapnode				*last_node;
		mapnode				*_end;
		mapnode				*_begin;
		
		

};

}
