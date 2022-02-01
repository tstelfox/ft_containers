/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:27:29 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/01 19:31:19 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <memory>
// #include <map>
#include "bimap_iterator.hpp"
#include "colours.hpp"
#include "pair.hpp"
#include "cpp_eleven_shiz.hpp"



namespace ft {


template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< pair<const Key, T> > >
class map
{
	public:

		typedef	Key													key_type;
		typedef	T													mapped_type;
		typedef pair<const key_type, mapped_type>				value_type;
		typedef	Compare												key_compare;
		typedef	Alloc												allocator_type;
		typedef	value_type&											reference;
		typedef	const value_type&									const_reference;
		typedef value_type*											pointer;
		typedef const value_type*									const_pointer;
		typedef	Bimapiterator<value_type, pointer, reference>		iterator;
		typedef	Bimapiterator<value_type, const_pointer, const_reference>	const_iterator;
		typedef rev_iterator<iterator>								reverse_iterator;
		typedef	rev_iterator<const_iterator>						const_reverse_iterator;
		typedef	size_t												size_type;
		typedef	std::ptrdiff_t											difference_type;
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
				}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(),
				const allocator_type &alloc = allocator_type())
			: m_allocator(alloc) , _comp(comp) , m_size(0), root(), first_node(), last_node() {
				insert(first, last);
			}

		map(const map& x) {
			this->m_allocator = x.m_allocator;
			this->_comp = x._comp;
			this->m_size = 0;
			this->insert(x.begin(), x.end());
		}

		~map() {
			clear();

			// The following leads to a double free for some reason:
			// m_allocator.deallocate(_begin, 1);
			// m_allocator.deallocate(_end, 1);
		}

		map&	operator = (const map &x) {
			/* The container preserves its current allocator, 
			which is used to allocate additional storage if needed.
			BUT
			How am I meant to assign from maps of different types? */
			if (this != &x) {
				this->clear();
				this->_comp = x._comp;
				this->insert(x.begin(), x.end());
			}
			return *this;
		}

		/* <<**------------------- ITERATORS ------------------**>> */

		iterator	begin() {
			return iterator(_begin->parent);
		}

		const_iterator begin() const {
			return const_iterator(_begin->parent);
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
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		}

		/* <<**------------------- MODIFIERS ------------------**>> */

		


		std::pair<iterator, bool>	insert(const value_type& val) { // Should probably clean this up
			if (m_size >= 1)
			{
				mapnode *temp = NULL;
				temp = m_allocator.allocate(1);
				m_size++;
				// m_allocator.construct(temp(val));
				m_allocator.construct(temp, val);
				mapnode *point(root);
				while (point) {
					if (point->object.first == temp->object.first) {
						m_size--;
						m_allocator.deallocate(temp, 1);
						std::pair<iterator, bool> ret = std::make_pair(iterator(point), false);
						return ret;
					}
 					if (value_compare(_comp)(temp->object, point->object)) {
						if (point->left && !point->left->_delimit)
							point = point->left;
						else {
							temp->parent = point;
							point->left = temp;
							break;
						}
					}
					else {
						if (point->right && !point->right->_delimit) {
							point = point->right;
						}
						else {
							temp->parent = point;
							point->right = temp;
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
				init_first_last();
				m_size++;
				m_allocator.construct(root, val);
				root->colour = BLACK;
				first_node = root;
				last_node = root;
				root->right = _end;
				_end->parent = _begin->parent = root;
				first_and_last();
				return std::make_pair(iterator(root), true);
			}
		}

		iterator insert (iterator position, const value_type& val) {
			(void)position;
			// The following would slow it to fuck, I feel
			// if (find(val->first) == position)
			// 	return position;
			return insert(val).first;
		}

		template <class InputIterator>
 		void insert (InputIterator first, InputIterator last) {
			/* I actually presume that I will have to go sequentially cause
			it could easily also be taking elements from an array */
			for (; first != last; first++) {
				// std::cout << first->first << std::endl;
				insert(*first);
			}
		}

		

		void		erase(iterator position) {
			// std::cout << "Scusami tanto" << std::endl;
			// std::cout << "This is root first: " << root->object.first << std::endl;
			// std::cout << "And first_node first: " << first_node->object.first << std::endl;
			erase_node(position.get_node());
			// first_node = m_size == 1 ? root : first_node;
			// std::cout << "This is root after: " << root->object.first << std::endl;
			// std::cout << "And first_node after: " << first_node->object.first << std::endl;
			m_size--;
		}

		size_type	erase(const key_type &k) {
			// Just gonna presume that the ting to erase is actually in the map
			erase_node(find(k).get_node());
			// first_node = m_size == 1 ? root : first_node;
			m_size--;
			return 1;
		}

		void		erase(iterator first, iterator last) {
			// std::cout << "Non e mai vero" << std::endl;
			for (; first != last; first++)
				erase(first);
		}

		void	swap(map &x) {
			// This is almost certainly stupid inefficient but do I ultimately care?
			// Maybe rewrite it more efficiently later
			map temp = *this;
			*this = x;
			x = temp;
		}

		void	clear() {
			while (root)
				erase_node(root);
			m_size = 0;
		}

		/* <<**------------------- OBSERVERS ------------------**>> */

		key_compare		key_comp() const { return (_comp); }

		value_compare	value_comp() const { return (value_compare(_comp)); }

		/* <<**------------------- OPERATIONS ------------------**>> */

		iterator		find(const key_type &k) {
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


		iterator		lower_bound(const key_type &k) {
			iterator it = begin();

			for (; it != end(); it++) {
				if (_comp(k, it->first) || k == it->first)
					return it;
			}
			return end();
		}

		const_iterator	lower_bound(const key_type &k) const {
			const_iterator it = begin();

			for (; it != end(); it++) {
				if (_comp(k, it->first) || k == it->first)
					return it;
			}
			return end();
		}

		iterator		upper_bound(const key_type &k) {
			iterator it = begin();

			for (; it != end(); it++) {
				if (_comp(k, it->first))
					return it;
			}
			return end();
		}

		const_iterator		upper_bound(const key_type &k) const {
			const_iterator it = begin();

			for (; it != end(); it++) {
				if (_comp(k, it->first))
					return it;
			}
			return end();
		}

		std::pair<iterator,iterator>	equal_range(const key_type &k) {
			iterator	it = begin();

			for (; it != end(); it++) {
				if (!_comp(k, it->first) && !_comp(it->first, k)) {
					return std::make_pair<iterator,iterator>(lower_bound(k), upper_bound(k));
				}
				if (_comp(k, it->first))
					break ;
			}
			iterator ret = upper_bound(k);
			return std::make_pair<iterator,iterator>(ret, ret);
		}

		std::pair<const_iterator,const_iterator>	equal_range(const key_type &k) const {
			const_iterator	it = begin();

			for (; it != end(); it++) {
				if (!_comp(k, it->first) && !_comp(it->first, k)) {
					return std::make_pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
				}
				if (_comp(k, it->first))
					break ;
			}
			const_iterator ret = upper_bound(k);
			return std::make_pair<const_iterator,const_iterator>(ret, ret);
		}

		/* <<**------------------- ALLOCATOR ------------------**>> */

		allocator_type	get_allocator() const {
			return m_allocator;
		}

		/* <<**------------------- REDBLACK INSERTION AND DELETION FUNCTIONS ------------------**>> */


		void		right_rotate(mapnode *&newnode)
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

		void		left_rotate(mapnode *&newnode)
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
							left_rotate(p_node);
							newnode = p_node;
							p_node = newnode->parent;
						}
						/* case Gamma
							newnode is left child of its parent
							right-rotation required */
						right_rotate(gp_node);
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
							right_rotate(p_node);
							newnode = p_node;
							p_node = newnode->parent;
						}
						/* Case Beta
							newnode is right child of its parent
							left-rotation required */
						left_rotate(gp_node);
						std::swap(p_node->colour, gp_node->colour);
						newnode = p_node;
					}
				}
				
			}
			root->colour = BLACK;
		}


		mapnode *successor(mapnode *x) {
			mapnode *temp = x;
			while (temp->left != NULL && !temp->left->_delimit)
				temp = temp->left;
			return temp;
		}

		void	erasure_balance(mapnode *x) {
			mapnode *s;
			// std::cout << "In here fo sho" << std::endl;
			// std::cout << "Is it root? " << (x == root) << std::endl;
			if (x == 0) // Segfaults without this
				return ;
			while (x != root && x->colour == BLACK) {
				if (x == x->parent->left) {
					s = x->parent->right;
					if (s->colour == RED) {
						s->colour = BLACK;
						x->parent->colour = RED;
						left_rotate(x->parent);
						s = x->parent->right;
					}
					if (s->left->colour == BLACK && s->right->colour == BLACK) {
						s->colour = RED;
						x = x->parent;
					}
					else {
						if (s->right->colour == BLACK) {
							s->left->colour = BLACK;
							s->colour = RED;
							right_rotate(s);
							s = x->parent->right;
						}
						s->colour = x->parent->colour;
						x->parent->colour = BLACK;
						s->right->colour = BLACK;
						left_rotate(x->parent);
						x = root;
					}
				}
				else {
					s = x->parent->left;
					if (s->colour == RED) {
						s->colour = BLACK;
						x->parent->colour = RED;
						right_rotate(x->parent);
						s = x->parent->left;
					}
					if (s->right->colour == BLACK && s->right->colour == BLACK) {
						s->colour = RED;
						x = x->parent;
					} 
					else {
					if (s->left->colour == BLACK) {
						s->right->colour = BLACK;
						s->colour = RED;
						left_rotate(s);
						s = x->parent->left;
					}

					s->colour = x->parent->colour;
					x->parent->colour = BLACK;
					s->left->colour = BLACK;
					right_rotate(x->parent);
					x = root;
					}
				}
			}
			x->colour = BLACK;
		}

		void	rbTransplant(mapnode *u, mapnode *v) {
			if (u->parent == NULL)
				root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			if (v) { // Found this on Peer's and it makes sense
				// std::cout << "This is root: " << v->object.first << std::endl;
				v->parent = u->parent;
			}
		}

		void	erase_node(mapnode *node) {
			mapnode	*x, *y, *z;
			z = y = node;
			
			char	y_og_colour = y->colour;
			if (z->left == NULL) {
				x = z->right;
				rbTransplant(z, z->right);
			}
			else if (z->right == NULL) {
				x = z->left;
				rbTransplant(z, z->left);
			}
			else {
				y = successor(z->right);
				y_og_colour = y->colour;
				x = y->right;
				if (y->parent == z) {
					if (x) // Stole this from Reeeep and now see why it makes sense
						x->parent = y;
				}
				else {
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->colour = z->colour;
			}
			m_allocator.deallocate(z, 1);
			if (y_og_colour == BLACK) {
				erasure_balance(x);
			}
		}

		/* <<**------------------- DELIMITER UTILS ------------------**>> */



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
			// first_node = _end; // Attempting to fight the double free by commenting this out
			// first_node->parent = _end;
		}

		/* <<**------------------- PRINT LE TREE ------------------**>> */

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

		void printBT() const {
			printBT("", this->root, false);
			std::cerr << std::endl;
		}
		
		void printBT(const std::string& prefix, const mapnode* trav, bool isLeft) const {
			// std::cout << last_node->object.first << std::endl;
			// std::cout << first_node->object.first << std::endl;
			if (trav && trav != _end && trav != _begin) {
					std::cerr << prefix;
					std::cerr << (isLeft ? "├L─" : "└R-" );
					if (trav->colour == RED)
						std::cerr << ROSSO;
					else if (trav->colour == BLACK)
						std::cerr << _IWHITE << GREY;
					std::cerr << trav->object.first << END << std::endl ;
					// RYYYYYKEHHHRSHION
					printBT( prefix + (isLeft ? "│   " : "    "), trav->left, true);
					printBT( prefix + (isLeft ? "│   " : "    "), trav->right, false);
			}
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

template <class Key, class T, class Compare, class Alloc>
  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
	  x.swap(y);
  }

}
