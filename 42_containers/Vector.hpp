#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include "Vector_Iter.hpp"
#include "Utility.hpp"
namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class Vector
	{

	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef ConstVectorIterator<T> const_iterator;
		typedef ConstReverseVectorIterator<T> const_reverse_iterator;
		typedef typename Allocator::difference_type difference_type;
		typedef VectorIterator<T> iterator;
		typedef ReverseVectorIterator<T> reverse_iterator;
		typedef typename Allocator::size_type size_type;
		typedef const T &const_reference;
		typedef T &reference;
		typedef T *pointer;
		typedef const T *const_pointer;

	private:
		allocator_type alloc;
		pointer start;
		pointer _end;
		pointer end_capacity;

	public:
		// 필자의 경우, 암시적 타입 변환에 생성자가 사용될 여지를 남겨둘 뚜렷한 이유가 없는 한, 생성자는 explicit 선언을 우선적으로 합니다.
		// 여러분도 주저 마시고 이런 식으로 해 보시기를 적극 추천하는 바입니다.
		// 출처: https://gyugyu.tistory.com/99 [GYU's DEV STORY]
		// https://modoocode.com/253 explicit 설명
		// https://en.cppreference.com/w/cpp/header/vector
		explicit Vector(const allocator_type &alloc = allocator_type()) : alloc(alloc), start(NULLPTR), _end(NULLPTR), end_capacity(NULLPTR)
		{
			start = this->alloc.allocate(0);
			_end = start;
			end_capacity = start;
		} // defalut
		explicit Vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: alloc(alloc), start(NULLPTR), _end(NULLPTR), end_capacity(NULLPTR)
		{
			start = this->alloc.allocate(n);
			_end = start;
			end_capacity = start + n;
			while (n--)
			{
				this->alloc.construct(_end, val);
				_end++;
			}
		}

		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range,
		// in the same order.
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type())
			: alloc(alloc), start(NULLPTR), _end(NULLPTR), end_capacity(NULLPTR)
		{
			size_t n = std::distance(first, last);
			start = this->alloc.allocate(n);
			_end = start;
			end_capacity = start + n;
			while (n--)
			{
				this->alloc.construct(_end, *first++);
				_end++;
			}
		}
		~Vector()
		{
			this->clear();
			alloc.deallocate(start, this->capacity());
		}

		Vector(const Vector &x) //main_vector.cpp 각 함수 진행 후 소멸할 때 모든 값을 x에서 복사해오면 얕은 복사때문에 같은 주소를 두번 free해서 오류가 발생한다.
		{
			alloc = x.alloc; //이거는 복사하면 무슨일이?
			start = alloc.allocate(0);
			_end = start;
			end_capacity = start;
			*this = x;
		}

		Vector &operator=(const Vector &ref)
		{
			this->clear();
			for (size_t i = 0; i < ref.size(); i++)
				push_back(ref[i]);
			return *this;
		}

		/*
			vector끼리 교환한다.
			이 때, alloc에 저장된 값을 바꾸지 않고, start,end,end_capacity가 가리키는 주소만 교환해주는 방식으로
			기존 공간을 유지한 채로 바꿔준다.
			참고자료 : https://en.cppreference.com/w/cpp/container/vector/swap
		*/

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			this->clear();
			this->insert(this->begin(), first, last);
		}
		/*
			벡터에 저장되어있던 값들을 전부 버리고 새로운 값으로 작성한다.
			count > end_capacity -> end_capacity 유지
			count < end_capacity -> end_capacity 크기의 변화 없음(절반 이하여도 capacity가 안 줄어듦)
		*/
		void assign(size_type count, const T &value)
		{
			this->clear();

			if (count == 0) //쓸 값이 없는 경우 종료
				return;
			if (count < this->capacity()) //공간이 여유가 있는 경우 별도의 재할당 작업 없이 진행한다.
			{
				for (size_t i = 0; i < count; i++)
				{
					alloc.construct(_end++, value);
				}
			}
			else //써야할 공간이 할당된 공간보다 큰 경우 써야할 공간만큼 새로 할당을 받아서 값을 넣어준다.
			{
				this->alloc.deallocate(start, this->capacity());
				start = this->alloc.allocate(count);
				_end = start; //start의 위치가 갱신되었으므로 end를 start에 맞춰준다.(위의 123줄과는 allocate의 유무 차이가 있으므로 clear()다음에 한번에 작성하면 오류가 날것.)
				end_capacity = start + count;
				for (size_t i = 0; i < count; i++)
				{
					alloc.construct(_end++, value);
				}
			}
		}

		reference at(size_type n)
		{
			if (n >= this->size())
				throw(std::out_of_range("vector::checkRange"));
			return *(start + n);
		}

		const_reference at(size_type n) const
		{
			if (n >= this->size())
				throw(std::out_of_range("vector::checkRange"));
			return *(start + n);
		}
		reference back()
		{
			return *(_end - 1);
		}
		const_reference back() const
		{
			return *(_end - 1);
		}

		const_iterator begin() const
		{
			return const_iterator(start);
		}
		iterator begin()
		{
			return iterator(start);
		}

		size_type capacity() const
		{
			return this->end_capacity - this->start;
		}

		void clear()
		{
			size_type cap = this->capacity();
			for (size_type x = 0; x < cap; x++)
				alloc.destroy(start + x);
			_end = start;
		}

		bool empty() const
		{
			if (this->size() == 0)
				return 1;
			return 0;
		}

		iterator end()
		{
			return _end;
		}
		const_iterator end() const
		{
			return _end;
		}

		iterator erase(iterator position) // 1개의 값만 있을때, 해당 값이 리턴되는 메인문확인
		{
			alloc.destroy(&(*position));
			if (&(*position) + 1 == _end) // destroy를 두번 하는 이유가 뭔지?
				alloc.destroy(&(*position));
			else
			{
				for (int i = 0; i < _end - &(*position) + 1; i++)
				{
					alloc.construct(&(*position) + i, *(&(*position) + i + 1));
					alloc.destroy(&(*position) + i + 1);
				}
			}
			_end -= 1;
			return &(*position);
		}
		iterator erase(iterator first, iterator last)
		{
			size_t len = &(*last) - &(*first);
			for (size_t i = 0; i < len; i++)
			{
				alloc.destroy(&(*first) + i);
			}
			for (size_t i = 0; i < (size_t)(_end - &(*last)); i++)
			{
				alloc.construct(&(*first) + i, *(&(*last) + i));
				alloc.destroy(&(*last) + i);
			}
			_end -= (len);
			return (&(*first));
		}

		reference front()
		{
			return *start;
		}
		const_reference front() const
		{
			return *start;
		}
		allocator_type get_allocator() const
		{
			return alloc;
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_type pos = &(*position) - start;
			if (size() + 1 > this->capacity() / 2) // 절반이상 찬 경우 배열 크기를 2배로 늘린다
				reserve(this->capacity() == 0 ? 2 : this->capacity() * 2);
			for (iterator tmp = _end; tmp != start + pos; --tmp)
				*tmp = *(tmp - 1); // 한칸씩 오른쪽으로 옮겨준다
			*(start + pos) = val;  // 값을 위치에 넣어준다
			++_end;
			return iterator(start + pos);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type index = &(*position) - start;
			iterator pos = position;
			if (this->size() < n)
			{
				reserve(this->capacity() == 0 ? 2 : this->capacity() * 2);
				pos = start + index;
			}
			for (size_t i = 0; i < n; i++)
			{
				insert(pos + i, val);
			}
		}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				position = this->insert(position, *first);
				first++;
				position++;
			}
		}

		void pop_back()
		{
			if (start == _end)
			{
				return;
			}
			alloc.destroy(_end--);
		}

		void push_back(const T &value)
		{
			if (_end == end_capacity)
			{
				int next_capacity = (capacity() > 0) ? (int)(capacity() * 2) : 1;
				reserve(next_capacity);
			}
			alloc.construct(_end, value);
			_end++;
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(&back());
		}
		const_reverse_iterator rbegin() const
		{
			return reverse_iterator(&back());
		}

		const_reverse_iterator rend() const
		{
			return reverse_iterator(start - 1);
		}
		reverse_iterator rend()
		{
			return reverse_iterator(start - 1);
		}

		size_type max_size(void) const { return allocator_type().max_size(); }

		void reserve(size_type n)
		{
			if (n > this->max_size())
				throw(std::length_error("vector::reserve length error"));
			else if (n > this->capacity())
			{
				pointer prev_start = start;
				pointer prev_end = _end;
				size_type prev_size = this->size();
				size_type prev_capacity = this->capacity();

				start = alloc.allocate(n);
				end_capacity = start + n;
				_end = start;
				while (prev_start != prev_end)
				{
					alloc.construct(_end, *prev_start);
					_end++;
					prev_start++;
				}
				alloc.deallocate(prev_start - prev_size, prev_capacity);
			}
		}

		void resize(size_t n, value_type val = value_type())
		{
			if (n < 0)
				throw(std::length_error("vector::resize length error"));
			if (n > this->size()) // 남은 부분에 값 넣기
			{
				while (n - this->size() > 0)
					this->push_back(val);
			}
			else
			{
				while (this->size() - n > 0)
				{
					this->pop_back();
				}
			}
		}

		size_type size() const
		{
			return std::distance(this->start, this->_end);
		}

		void swap(Vector<value_type, allocator_type> &right)
		{
			if (right == *this)
				return;

			pointer save_start = right.start;
			pointer save_end = right._end;
			pointer save_end_capacity = right.end_capacity;
			allocator_type save_alloc = right.alloc;

			right.start = this->start;
			right._end = this->_end;
			right.end_capacity = this->end_capacity;
			right.alloc = this->alloc;

			this->start = save_start;
			this->_end = save_end;
			this->end_capacity = save_end_capacity;
			this->alloc = save_alloc;
		}

		value_type &operator[](int n) const
		{
			return *(this->start + n);
		}
	};

	template <class T, class Alloc>
	void swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator==(const Vector<T, Alloc> &left, const Vector<T, Alloc> &right)
	{
		typename Vector<T, Alloc>::iterator left_it = left.begin();
		typename Vector<T, Alloc>::iterator right_it = right.begin();
		for (; left_it < left.end(); left_it++)
		{
			if (right_it == right.end())
				return false;
			if (*left_it != *right_it)
				return false;
			right_it++;
		}
		if (right_it != right.end())
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const Vector<T, Alloc> &left, const Vector<T, Alloc> &right)
	{
		return !(left == right);
	}

	template <class T, class Alloc>
	bool operator<(const Vector<T, Alloc> &left, const Vector<T, Alloc> &right)
	{
		typename Vector<T, Alloc>::iterator left_it = left.begin();
		typename Vector<T, Alloc>::iterator right_it = right.begin();
		for (; left_it < left.end(); left_it++)
		{
			// 끝 부분을 체크하지 않으면 쓰레기 값을 참조할 수 있음
			if (right_it == right.end())
				return false;
			if (*left_it < *right_it)
				return true;
			else if (*left_it > *right_it)
				return false;
			right_it++;
		}
		if (right_it != right.end())
			return true;
		return (false); //다 같은거
	}

	template <class T, class Alloc>
	bool operator<=(const Vector<T, Alloc> &left, const Vector<T, Alloc> &right)
	{
		typename Vector<T, Alloc>::iterator left_it = left.begin();
		typename Vector<T, Alloc>::iterator right_it = right.begin();
		for (; left_it < left.end(); left_it++)
		{
			if (right_it == right.end())
				return false;
			if (*left_it < *right_it)
				return true;
			else if (*left_it > *right_it)
				return false;
			right_it++;
		}
		return (true); //다 같은거
	}

	template <class T, class Alloc>
	bool operator>(const Vector<T, Alloc> &left, const Vector<T, Alloc> &right)
	{
		return (!(left < right) && !(left == right));
	}

	template <class T, class Alloc>
	bool operator>=(const Vector<T, Alloc> &left, const Vector<T, Alloc> &right)
	{
		return !(left < right);
	}
};

#endif
