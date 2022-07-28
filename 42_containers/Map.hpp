#ifndef MAP_HPP
#define MAP_HPP

#include "BinarySearchTree.hpp"
#include "BinarySearchTree_iter.hpp"
#include <iostream>
#include <memory>
#include <iterator>
#include "Utility.hpp"
namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class Map
	{
	public:
		//member types
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		// Nested function class to compare elements
		typedef Alloc allocator_type;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::MapIterator<Key, T> iterator;
		typedef ft::ConstMapIterator<Key, T> const_iterator;
		typedef ft::MapReverseIterator<Key, T> reverse_iterator;
		typedef ft::ConstMapReverseIterator<Key, T> const_reverse_iterator;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;

	private:
		allocator_type _alloc;
		Compare _comp;
		Node<Key, T> *root;
		Node<Key, T> *_start;
		Node<Key, T> *_end;
		size_type length;

	public:
		class value_compare
		{ // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;

		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};
		explicit Map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type())
		{
			this->_comp = comp;
			this->_alloc = alloc;
			this->_start = new Node<Key, T>();
			this->_start->left = NULLPTR;
			this->_start->right = NULLPTR;
			this->_end = new Node<Key, T>();
			this->_end->left = this->_start;
			this->_start->parent = this->_end;
			this->_end->right = NULL;
			this->_end->parent = NULL;
			this->root = this->_end;
			this->length = 0;
		}
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			this->_comp = comp;
			this->_alloc = alloc;
			this->_start = new Node<Key, T>();
			this->_start->left = NULLPTR;
			this->_start->right = NULLPTR;
			this->_end = new Node<Key, T>();
			this->_end->left = this->_start;
			this->_start->parent = this->_end;
			this->_end->right = NULL;
			this->_end->parent = NULL;
			this->root = this->_end;
			this->length = 0;
			this->insert(first, last);
		}
		~Map(void)
		{
			this->clear();
			delete (this->_end);
			delete (this->_start);
			return;
		}

		Map(const Map &map)
		{
			//clear()에서 begin,end를 조건으로 주지만, begin의 경우 start가 아니라 제일 첫 노드를 반환
			//end의 경우 erase()함수에서 end와 다를때까지 반복하기 때문에, end를 삭제대상에 포함하지 않는다.
			//그래서 여기서 새로 생성해줘도 지워지지않는다.
			this->_start = new Node<Key, T>();
			this->_start->left = NULL;
			this->_start->right = NULL;
			this->_end = new Node<Key, T>();
			this->_end->left = this->_start;
			this->_start->parent = this->_end;
			this->_end->right = NULL;
			this->_end->parent = NULL;
			this->root = this->_end;
			this->length = 0;
			*this = map;
		}

		Map &operator=(const Map &map)
		{
			this->clear();
			this->_comp = map._comp;
			this->_alloc = map._alloc;
			this->insert(map.begin(), map.end());
			return (*this);
		}
		/* ********************************************************************** */
		/*                         AVL TREE                                       */
		/* ********************************************************************** */

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			Node<Key, T> *node;
			Node<Key, T> *newNode;

			newNode = new Node<Key, T>();
			newNode->parent = NULLPTR;
			newNode->left = NULLPTR;
			newNode->right = NULLPTR;
			newNode->pair = value;
			newNode->left_height = 0;
			newNode->right_height = 0;
			if (this->root != this->_end)
			{
				node = this->root;
				while (!newNode->parent)
				{
					if (newNode->pair.first == node->pair.first)
					{
						delete (newNode);
						return (ft::pair<iterator, bool>(iterator(node), false));
					}
					if (this->_comp(newNode->pair.first, node->pair.first))
					{
						if (node->left && node->left != this->_start)
							node = node->left;
						else
						{
							if (node->left == this->_start)
								this->_start->parent = newNode;
							node->left = newNode;
							newNode->parent = node;
							if (this->_start->parent == newNode)
								newNode->left = this->_start;
						}
					}
					else
					{
						if (node->right && node->right != this->_end)
							node = node->right;
						else
						{
							if (node->right == this->_end)
								this->_end->parent = newNode;
							node->right = newNode;
							newNode->parent = node;
							if (this->_end->parent == newNode)
								newNode->right = this->_end;
						}
					}
				}
			}
			else
			{
				this->root = newNode;
				this->root->right = this->_end;
				this->root->left = this->_start;
				this->_end->parent = this->root;
				this->_end->left = NULL;
				this->_end->right = NULL;
				this->_start->parent = this->root;
			}
			this->balance(newNode, 0);
			this->length++;
			return (ft::pair<iterator, bool>(iterator(newNode), true));
		}

		void calculate_height(Node<Key, T> *node)
		{
			Node<Key, T> *root;

			root = node ? node->parent : NULLPTR;
			while (root)
			{
				if (root->left == node)
					root->left_height = std::max<int>(node->left_height, node->right_height) + 1;
				else if (root->right == node)
					root->right_height = std::max<int>(node->left_height, node->right_height) + 1;
				node = root;
				root = node->parent;
			}
		}

		void balance(Node<Key, T> *node, int type)
		{
			Node<Key, T> *start;
			Node<Key, T> *grand_child;
			Node<Key, T> *root;
			int balance_num;

			start = node;
			calculate_height(node);
			grand_child = node;
			root = (node && node->parent) ? node->parent : node;
			while (root)
			{
				balance_num = static_cast<int>(root->left_height - root->right_height);
				if (std::abs(balance_num) > 1)
				{
					rebalance(balance_num, grand_child, type);
					balance(node, type);
				}
				grand_child = node;
				node = root;
				root = node->parent;
			}
			calculate_height(start);
			balance_num = static_cast<int>(this->root->left_height - this->root->right_height);
			if (std::abs(balance_num) > 1)
				balance(start, type);
		}
		void rebalance(int balance_num, Node<Key, T> *node, int type)
		{
			if (type == 0) // insert
			{
				if (balance_num > 1)
				{
					if (node == node->parent->left)
						right_rotate(node, node->parent);
					else if (node == node->parent->right)
						left_right_rotate(node, node->parent, node->parent->parent);
				}
				else if (balance_num < 1)
				{
					if (node == node->parent->right)
						left_rotate(node, node->parent);
					else if (node == node->parent->left)
						right_left_rotate(node, node->parent, node->parent->parent);
				}
			}
			else if (type == 1) // DELETION
			{
				int balance_num2;

				if (balance_num > 1)
				{
					balance_num2 = static_cast<int>(node->left->left_height - node->left->right_height);
					if (balance_num2 >= 0)
						right_rotate(node->left, node);
					else
						left_right_rotate(node->left, node, node->parent);
				}
				else if (balance_num < -1)
				{
					balance_num2 = static_cast<int>(node->right->left_height - node->right->right_height);
					if (balance_num2 <= 0)
						left_rotate(node->right, node);
					else
						right_left_rotate(node->right, node, node->parent);
				}
			}
		}

		/*
		**          p           p
		**          |           |
		**          y           x
		**         / \    =>   / \
		**        x   c       a   y
		**       / \             / \
		**      a   b           b   c
		*/

		void right_rotate(Node<Key, T> *node, Node<Key, T> *parent)
		{
			if (!parent->parent) //parent가 root였을 때
				this->root = node;
			else if (parent->parent->left == parent)
				parent->parent->left = node;
			else if (parent->parent->right == parent)
				parent->parent->right = node;
			node->parent = parent->parent;
			parent->parent = node;
			if (node->right)
				node->right->parent = parent;
			parent->left = node->right;
			node->right = parent;
			if (!parent->left) //기존 node->right가 있는 경우 parent->left로 새로 편입되었으므로 높이를 다시 잰다.
			{
				parent->left_height = 0;
				calculate_height(parent);
			}
			else
				calculate_height(parent->left);
		}
		/*
		**      p                p
		**      |                |
		**      x                y
		**     / \      =>      / \
		**    a   y            x   c
		**       / \          / \
		**      b   c        a   b
		*/
		void left_rotate(Node<Key, T> *node, Node<Key, T> *parent)
		{
			if (!parent->parent) //parent가 root였을 때
				this->root = node;
			else if (parent->parent->left == parent)
				parent->parent->left = node;
			else if (parent->parent->right == parent)
				parent->parent->right = node;
			node->parent = parent->parent;
			parent->parent = node;
			if (node->left)
				node->left->parent = parent;
			parent->right = node->left;
			node->left = parent;
			if (!parent->right) //기존 node->right가 있는 경우 parent->left로 새로 편입되었으므로 높이를 다시 잰다.
			{
				parent->right_height = 0;
				calculate_height(parent);
			}
			else
				calculate_height(parent->right);
		}

		void left_right_rotate(Node<Key, T> *x, Node<Key, T> *y, Node<Key, T> *z)
		{
			left_rotate(x, y);
			right_rotate(x, z);
		}
		void right_left_rotate(Node<Key, T> *x, Node<Key, T> *y, Node<Key, T> *z)
		{
			right_rotate(x, y);
			left_rotate(x, z);
		}

		void remove_node(Node<Key, T> *node)
		{
			Node<Key, T> *child;
			Node<Key, T> *to_balance;

			if ((!node->left || node->left == this->_start) && (!node->right || node->right == this->_end))
			{
				// 0 CHILD
				if (node->parent && node->parent->left == node)
				{
					if (node->left == this->_start)
						node->parent->left = this->_start;
					else
						node->parent->left = NULL;
				}
				else if (node->parent && node->parent->right == node)
				{
					if (node->right == this->_end)
						node->parent->right = this->_end;
					else
						node->parent->right = NULL;
				}
				else
				{
					this->root = this->_end;
					this->root->left = this->_start;
					this->_start->parent = this->root;
				}
				to_balance = node->parent;
				delete (node);
			}
			else if (node->left && node->left != this->_start && node->right && node->right != this->_end)
			{
				// 2 CHILD
				Node<Key, T> *tmp;

				to_balance = NULL;

				child = node->left;
				while (child->right && child->right != this->_end)
					child = child->right;
				// 연결할 tmp 생성
				tmp = new Node<Key, T>();
				tmp->parent = node->parent;
				tmp->left = node->left;
				tmp->right = node->right;
				tmp->left_height = node->left_height;
				tmp->right_height = node->right_height;
				// node 지우
				node->parent = child->parent;
				node->left = child->left;
				node->right = child->right;
				node->left_height = child->left_height;
				node->right_height = child->right_height;

				if (node->left)
					node->left->parent = node;
				if (node->right)
					node->right->parent = node;
				if (node->parent == node)
				{
					node->parent = child;
					node->parent->left = node;
				}
				else if (node->parent->left == child)
					node->parent->left = node;
				else if (node->parent->right == child)
					node->parent->right = node;
				//tmp 의 값을 복사
				child->parent = tmp->parent;
				if (!child->parent)
					this->root = child;
				else if (child->parent->left == node)
					child->parent->left = child;
				else if (child->parent->right == node)
					child->parent->right = child;
				child->left = tmp->left;
				child->right = tmp->right;
				child->left_height = tmp->left_height;
				child->right_height = tmp->right_height;
				if (child->left == child)
					child->left = node;
				else if (child->right == child)
					child->right = node;
				if (child->left)
					child->left->parent = child;
				if (child->right)
					child->right->parent = child;
				delete (tmp);
				remove_node(node);
				// 위치만 변경해주고 재귀를 통해 0 node를 삭제 시키는 것
			}
			else
			{
				// 1 CHILD
				child = (node->left && node->left != this->_start) ? node->left : node->right;
				child->parent = node->parent;
				if (!child->parent)
					this->root = child;
				else if (child->parent->left == node)
					child->parent->left = child;
				else if (child->parent->right == node)
					child->parent->right = child;
				to_balance = (child->parent) ? child->parent : child;
				calculate_height(child);
				if (node->left == this->_start)
					child->left = this->_start;
				delete (node);
			}
			if (to_balance)
				balance(to_balance, 1);
		}
		bool isEmpty() const
		{
			return root == NULL;
		}

		/* ********************************************************************** */
		/*                         Map                                            */
		/* ********************************************************************** */

		iterator begin()
		{
			Node<Key, T> *node;

			node = this->root;
			while (node->left && node->left != this->_start)
				node = node->left;

			return (iterator(node));
			//return (iterator(_start + 1));
			//->어차피 start 다음 위치가 첫 위치일텐데 왜 안될까?
		}
		const_iterator begin() const
		{
			Node<Key, T> *node;

			node = this->root;
			while (node->left && node->left != this->_start)
				node = node->left;
			return (const_iterator(node));
		}
		iterator end()
		{
			return (iterator(_end));
		}
		const_iterator end() const
		{
			return (const_iterator(_end));
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(--_end));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_iterator(--_end));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(_start));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_start));
		}
		bool empty() const
		{
			return (!this->length);
		}
		size_type size() const
		{
			return (this->length);
		}

		iterator insert(iterator position, const value_type &val)
		{
			Node<Key, T> *node;
			Node<Key, T> *newNode;
			iterator it;

			it = find(val.first);
			if (it != this->end())
				return (it);
			newNode = new Node<Key, T>();
			newNode->parent = NULLPTR;
			newNode->left = NULLPTR;
			newNode->right = NULLPTR;
			newNode->pair = val;
			newNode->left_height = 0;
			newNode->right_height = 0;
			if (this->root != this->_end)
			{
				node = position.getPtr();
				while (!newNode->parent)
				{
					if (node == this->_end || node == this->_start)
						node = this->root;
					if (this->_comp(newNode->pair.first, node->pair.first))
					{
						if (node->left && node->left != this->_start)
							node = node->left;
						else
						{
							if (node->left == this->_start)
								this->_start->parent = newNode;
							node->left = newNode;
							newNode->parent = node;
							if (this->_start->parent == newNode)
								newNode->left = this->_start;
						}
					}
					else
					{
						if (node->right && node->right != this->_end)
							node = node->right;
						else
						{
							if (node->right == this->_end)
								this->_end->parent = newNode;
							node->right = newNode;
							newNode->parent = node;
							if (this->_end->parent == newNode)
								newNode->right = this->_end;
						}
					}
				}
			}
			else
			{
				this->root = newNode;
				this->root->right = this->_end;
				this->root->left = this->_start;
				this->_end->parent = this->root;
				this->_end->left = NULL;
				this->_end->right = NULL;
				this->_start->parent = this->root;
			}
			this->balance(newNode, 0);
			this->length++;
			return (iterator(newNode));
		}
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		iterator find(const key_type &k)
		{
			Node<Key, T> *node;

			node = this->root;
			while (node && node != this->_start && node != this->_end)
			{
				if (k == node->pair.first)
					return (iterator(node));
				if (this->_comp(k, node->pair.first))
					node = node->left;
				else
					node = node->right;
			}
			return (this->end());
		}
		const_iterator find(const key_type &k) const
		{
			Node<Key, T> *node;

			node = this->root;
			while (node && node != this->_start && node != this->_end)
			{
				if (k == node->pair.first)
					return (const_iterator(node));
				if (this->_comp(k, node->pair.first))
					node = node->left;
				else
					node = node->right;
			}
			return (this->end());
		}

		void erase(iterator position)
		{
			remove_node(position.getPtr());
			this->length--;
		}
		size_type erase(const key_type &k)
		{
			Node<Key, T> *node;

			node = this->root;
			while (node && node != this->_start && node != this->_end)
			{
				if (k == node->pair.first)
				{
					erase(iterator(node));
					return (1);
				}
				if (this->_comp(k, node->pair.first))
					node = node->left;
				else
					node = node->right;
			}
			return (0);
		}
		void erase(iterator first, iterator last)
		{
			iterator next;

			while (first != last)
			{
				next = first;
				next++;
				erase(first);
				first = next;
			}
		}
		void clear()
		{
			erase(this->begin(), this->end());
		}
		size_type count(const key_type &k) const
		{
			return (find(k) != this->end());
		}
		void swap(Map &x)
		{
			Node<Key, T> *tmp;
			size_type length;

			tmp = this->root;
			this->root = x.root;
			x.root = tmp;
			tmp = this->_end;
			this->_end = x._end;
			x._end = tmp;
			tmp = this->_start;
			this->_start = x._start;
			x._start = tmp;
			length = this->length;
			this->length = x.length;
			x.length = length;
		}
		// 컨테이너의 원소 중 기준 원소보다 큰 값 중 가장 왼쪽에 있는 원소의 iter
		// mymap['a'] = 20;
		// mymap['b'] = 40;
		// mymap['c'] = 60;
		// mymap['d'] = 80;
		// mymap['e'] = 100;

		// itlow = mymap.lower_bound('b'); //b
		// itup = mymap.upper_bound('d'); //e
		// 같은 값이 나오면 iter + 1 값을 반환해준다.
		iterator upper_bound(const key_type &k)
		{
			iterator it = this->begin();
			iterator it2 = this->end();

			while (it != it2)
			{
				if ((*it).first == k)
					return (++it);
				if (this->_comp((*it).first, k) < 0)
					return (it);
				it++;
			}
			return this->end();
		}
		const_iterator upper_bound(const key_type &k) const
		{
			const_iterator it = this->begin();
			const_iterator it2 = this->end();

			while (it != it2)
			{
				if ((*it).first == k)
					return (const_iterator(++it));
				if (this->_comp((*it).first, k) < 0)
					return (const_iterator(it));
				it++;
			}
			return this->end();
		}

		// 컨테이너의 원소 중 기준 원소보다 같거나 큰 값 중 가장 왼쪽에 있는 원소의 iter
		iterator lower_bound(const key_type &k)
		{
			iterator it = this->begin();
			iterator it2 = this->end();

			while (it != it2)
			{
				if (this->_comp((*it).first, k) <= 0)
					return (iterator(it));
				it++;
			}
			return this->end();
		}
		const_iterator lower_bound(const key_type &k) const
		{
			const_iterator it = this->begin();
			const_iterator it2 = this->end();

			while (it != it2)
			{
				if (this->_comp((*it).first, k) <= 0)
					return (const_iterator(it));
				it++;
			}
			return this->end();
		}
		ft::pair<iterator, iterator> equal_range(const key_type &k)
		{
			return ft::make_pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return ft::make_pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k));
		}

		key_compare key_comp() const
		{
			return (this->_comp);
		}
		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(this->root));
		}
		value_compare value_comp() const
		{
			return (this->value_compare);
		}

		allocator_type get_allocator() const
		{
			return this->_alloc;
		}

		mapped_type &operator[](const key_type &k)
		{
			Node<Key, T> *node;

			node = this->root;
			while (node && node != this->_start && node != this->_end)
			{
				if (k == node->pair.first)
					return (node->pair.second);
				if (this->_comp(k, node->pair.first))
				{
					if (node->left)
						node = node->left;
					else										  //start 노드쪽 제외하면 모든 좌측 리프노드가 없으면 해당 위치에 새로 생성한다.
						insert(iterator(node), value_type(k, 0)); //값은 레퍼런스여서 반환되고 넣을 수 있어서 0으로 우선 넣는듯
				}
				else
				{
					if (node->right)
						node = node->right;
					else
						insert(iterator(node), value_type(k, 0));
				}
			}
			insert(value_type(k, 0)); // start이거나 end일 경우 그 root에서 insert
			return (this->root->pair.second);
		}
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		typename Map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (it != lhs.end())
		{
			// operator-> 로 인해 pair를 참조하여 first 값을 가져온다
			typename Map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.find(it->first);
			if (it2 == rhs.end())
				return (false);
			if (it2->first != it->first || it2->second != it->second)
				return false;
			it++;
		}
		return (true);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		typename Map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
		size_t n;
		size_t i;

		if (lhs.size() > rhs.size()) //사이즈가 작은 Map의 크기와 it를 가지고 판별을 시작한다.
		{
			n = rhs.size();
		}
		else
		{
			it = lhs.begin();
			n = lhs.size();
		}
		i = 0;
		while (i < n)
		{
			if (lhs.size() > rhs.size())
			{
				typename Map<Key, T, Compare, Alloc>::const_iterator it2 = lhs.find(it->first);
				if (it2 == lhs.end())
					return (true);
				// if (it->first != it2->first) //key가 같아야 여기까지 내려올텐데 왜 다른걸 체크하는가?
				// 	return (it2->first < it->first);
				if (it->second != it2->second)
					return (it2->second < it->second);
			}
			else
			{
				typename Map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.find(it->first);
				if (it2 == rhs.end())
					return (false);
				// if (it->first != it2->first)
				// 	return (it->second < it2->second);
				if (it->second != it2->second)
					return (it->second < it2->second);
			}
			it++;
			i++;
		}
		return (lhs.size() < rhs.size());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs) && !(lhs == rhs));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::Map<Key, T, Compare, Alloc> &x, ft::Map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	}
};

#endif
