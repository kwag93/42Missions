#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Utility.hpp"
#include <memory>
#include <iterator>

namespace ft
{
	template <class Key, class T>
	struct Node
	{
		Node *parent;
		Node *left;
		Node *right;
		ft::pair<Key, T> pair;
		size_t left_height;
		size_t right_height;
	};


}
#endif
