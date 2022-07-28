#ifndef BINARYSEARCHTREE_ITER_HPP
#define BINARYSEARCHTREE_ITER_HPP

#include "Utility.hpp"
#include "BinarySearchTree.hpp"

namespace ft
{
	template <class Key, class T, class Category = ft::bidirectional_iterator_tag>
	class MapIterator
	{
	private:
		// 사용할 수 없는 operator 를 잠궈놓아 사용시 에러가 나도록 한다
		MapIterator operator+(const MapIterator &rhs) const;
		MapIterator operator+(int n) const;
		MapIterator operator-(const MapIterator &rhs) const;
		MapIterator operator-(int n) const;
		bool operator<(const MapIterator &rhs) const;
		bool operator>(const MapIterator &rhs) const;
		bool operator<=(const MapIterator &rhs) const;
		bool operator>=(const MapIterator &rhs) const;
		MapIterator &operator+=(int n) const;
		MapIterator &operator-=(int n) const;
		T &operator[](int n) const;

	protected:
		Node<Key, T> *ptr;

	public:
		MapIterator() : ptr(NULLPTR){};
		MapIterator(Node<Key, T> *p) : ptr(p){};
		~MapIterator(){};
		MapIterator(const Node<Key, T> &iter)
		{
			*this = iter;
		};
		MapIterator &operator=(const MapIterator &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		MapIterator &operator--(void)
		{
			Node<Key, T> *next;

			if (!this->ptr)
				return (*this);
			if (!this->ptr->left)
			{
				next = this->ptr;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = this->ptr->left;
				while (next->right)
					next = next->right;
			}
			this->ptr = next;
			return (*this);
		}

		MapIterator &operator++(void)
		{
			Node<Key, T> *next;

			if (!this->ptr)
				return (*this);
			if (!this->ptr->right)
			{
				next = this->ptr;
				while (next->parent && next == next->parent->right) //좌측 부분 트리의 맨 오른쪽 리프노드의 경우 다음 이터레이터는 부분트리의 root로 간다.
					next = next->parent;							//next가 좌측 자식인 경우 관계가 없다.
				next = next->parent;
			}
			else //우측 자식이 있는경우 우측 자식으로 가되, 우측 자식이 왼쪽 자식(손자)을 갖는경우 왼쪽 손자으로 가야한다.
			{
				next = this->ptr->right;
				while (next->left)
					next = next->left;
			}
			this->ptr = next;
			return (*this);
		}
		// 후위연산자
		MapIterator operator--(int)
		{
			MapIterator iv(*this);

			--(*this);
			return (iv);
		}

		MapIterator operator++(int)
		{
			MapIterator iv(*this);

			++(*this);
			return (iv);
		}

		bool operator==(const MapIterator &it) //동일한 노드인가
		{
			return (this->ptr == it.ptr);
		}
		bool operator!=(const MapIterator &it)
		{
			return (this->ptr != it.ptr);
		}

		Node<Key, T> *getPtr(void)
		{
			return (this->ptr);
		}

		ft::pair<Key, T> &operator*(void)
		{
			return (this->ptr->pair);
		}
		ft::pair<Key, T> *operator->(void)
		{
			return (&this->ptr->pair);
		}
	};

	template <class Key, class T, class Category = ft::bidirectional_iterator_tag>
	class MapReverseIterator
	{
	private:
		// 사용할 수 없는 operator 를 잠궈놓아 사용시 에러가 나도록 한다
		MapReverseIterator operator+(const MapReverseIterator &rhs) const;
		MapReverseIterator operator+(int n) const;
		MapReverseIterator operator-(const MapReverseIterator &rhs) const;
		MapReverseIterator operator-(int n) const;
		bool operator<(const MapReverseIterator &rhs) const;
		bool operator>(const MapReverseIterator &rhs) const;
		bool operator<=(const MapReverseIterator &rhs) const;
		bool operator>=(const MapReverseIterator &rhs) const;
		MapReverseIterator &operator+=(int n) const;
		MapReverseIterator &operator-=(int n) const;
		T &operator[](int n) const;

	protected:
		Node<Key, T> *ptr;

	public:
		MapReverseIterator() : ptr(NULLPTR){};
		MapReverseIterator(Node<Key, T> *p) : ptr(p){};
		~MapReverseIterator(){};
		MapReverseIterator(const Node<Key, T> &iter)
		{
			*this = iter;
		};
		MapReverseIterator &operator=(const MapReverseIterator &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		MapReverseIterator &operator--(void)
		{
			Node<Key, T> *next;

			if (!this->ptr)
				return (*this);
			if (!this->ptr->left)
			{
				next = this->ptr;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = this->ptr->left;
				while (next->right)
					next = next->right;
			}
			this->ptr = next;
			return (*this);
		}

		MapReverseIterator &operator++(void)
		{
			Node<Key, T> *next;

			if (!this->ptr)
				return (*this);
			if (!this->ptr->right)
			{
				next = this->ptr;
				while (next->parent && next == next->parent->right) //좌측 부분 트리의 맨 오른쪽 리프노드의 경우 다음 이터레이터는 부분트리의 root로 간다.
					next = next->parent;							//next가 좌측 자식인 경우 관계가 없다.
				next = next->parent;
			}
			else //우측 자식이 있는경우 우측 자식으로 가되, 우측 자식이 왼쪽 자식(손자)을 갖는경우 왼쪽 손자으로 가야한다.
			{
				next = this->ptr->right;
				while (next->left)
					next = next->left;
			}
			this->ptr = next;
			return (*this);
		}
		// 후위연산자
		MapReverseIterator operator--(int)
		{
			MapReverseIterator iv(*this);

			--(*this);
			return (iv);
		}

		MapReverseIterator operator++(int)
		{
			MapReverseIterator iv(*this);

			++(*this);
			return (iv);
		}

		bool operator==(const MapReverseIterator &it) //동일한 노드인가
		{
			return (this->ptr == it.ptr);
		}
		bool operator!=(const MapReverseIterator &it)
		{
			return (this->ptr != it.ptr);
		}

		ft::pair<Key, T> &operator*(void)
		{
			return (this->ptr->pair);
		}
		ft::pair<Key, T> *operator->(void)
		{
			return (&this->ptr->pair);
		}
	};

	template <class Key, class T>
	class ConstMapIterator : public MapIterator<Key, T>
	{
	public:
		ConstMapIterator() {}
		~ConstMapIterator() {}

		ConstMapIterator(Node<Key, T> *map)
		{
			this->ptr = map;
		}

		ConstMapIterator(const ConstMapIterator &it)
		{
			*this = it;
		}

		ConstMapIterator &operator=(const ConstMapIterator &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const ft::pair<Key, T> &operator*(void) // dereferenced lvalue
		{
			return (this->ptr->pair);
		}
	};

	template <class Key, class T>
	class ConstMapReverseIterator : public MapReverseIterator<Key, T>
	{
	public:
		ConstMapReverseIterator() {}
		~ConstMapReverseIterator() {}

		ConstMapReverseIterator(Node<Key, T> *map)
		{
			this->ptr = map;
		}

		ConstMapReverseIterator(const ConstMapReverseIterator &it)
		{
			*this = it;
		}

		ConstMapReverseIterator &operator=(const ConstMapReverseIterator &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const ft::pair<Key, T> &operator*(void)
		{
			return (this->ptr->pair);
		}
	};
};

#endif
