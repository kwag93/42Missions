#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft
{
	template <class T, class Allocator = ft::Vector<T> >
	class Stack
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::size_type size_type;

	private:
		allocator_type alloc;

	public:
		explicit Stack(const allocator_type &ctnr = allocator_type())
		{
			this->alloc = ctnr;
		}

		~Stack()
		{
		}

		Stack(const Stack &stack)
		{
			*this = stack;
		}

		Stack &operator=(const Stack &stack)
		{
			this->alloc = stack.alloc;
			return (*this);
		}

		bool empty() const
		{
			return this->alloc.empty();
		}
		void pop()
		{
			this->alloc.pop_back();
		}
		void push(const value_type &val)
		{
			this->alloc.push_back(val);
		}
		size_type size() const
		{
			return this->alloc.size();
		}
		value_type &top()
		{
			return this->alloc.back();
		}
		const value_type &top() const
		{
			return this->alloc.back();
		}

	private:
		template <class U, class V>
		friend bool operator==(const Stack<U, V> &lhs, const Stack<U, V> &rhs);
		template <class U, class V>
		friend bool operator!=(const Stack<U, V> &lhs, const Stack<U, V> &rhs);
		template <class U, class V>
		friend bool operator<(const Stack<U, V> &lhs, const Stack<U, V> &rhs);
		template <class U, class V>
		friend bool operator<=(const Stack<U, V> &lhs, const Stack<U, V> &rhs);
		template <class U, class V>
		friend bool operator>(const Stack<U, V> &lhs, const Stack<U, V> &rhs);
		template <class U, class V>
		friend bool operator>=(const Stack<U, V> &lhs, const Stack<U, V> &rhs);
	};
	template <class T, class Container>
	bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.alloc == rhs.alloc);
	}
	template <class T, class Container>
	bool operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.alloc != rhs.alloc);
	}
	template <class T, class Container>
	bool operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.alloc < rhs.alloc);
	}
	template <class T, class Container>
	bool operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.alloc <= rhs.alloc);
	}
	template <class T, class Container>
	bool operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.alloc > rhs.alloc);
	}
	template <class T, class Container>
	bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.alloc >= rhs.alloc);
	}
};

#endif
