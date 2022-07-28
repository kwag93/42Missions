#ifndef VECTOR_ITER_HPP
#define VECTOR_ITER_HPP

#include "Utility.hpp"

namespace ft
{
	template <typename T, class Category = random_access_iterator_tag>
	class VectorIterator
	{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

	protected:
		pointer ptr;

	public:
		VectorIterator() : ptr(NULLPTR){};
		VectorIterator(pointer p) : ptr(p){};
		~VectorIterator(){};
		VectorIterator(const VectorIterator &iter)
		{
			*this = iter;
		};

		VectorIterator operator+(int n) const
		{
			VectorIterator iv(*this);

			iv += n;
			return (iv);
		}
		VectorIterator operator-(int n) const
		{
			VectorIterator iv(*this);

			iv -= n;
			return (iv);
		}

		VectorIterator &operator--(void)
		{
			this->ptr--;
			return (*this);
		}
		VectorIterator &operator++(void)
		{
			this->ptr++;
			return (*this);
		}

		VectorIterator operator--(int)
		{
			VectorIterator iv(*this);

			--(*this);
			return (iv);
		}
		VectorIterator operator++(int)
		{
			VectorIterator iv(*this);

			++(*this);
			return (iv);
		}

		bool operator==(const VectorIterator &it)
		{
			return (this->ptr == it.ptr);
		}
		bool operator!=(const VectorIterator &it)
		{
			return (this->ptr != it.ptr);
		}
		bool operator>(const VectorIterator &it)
		{
			return (this->ptr > it.ptr);
		}
		bool operator>=(const VectorIterator &it)
		{
			return (this->ptr >= it.ptr);
		}
		bool operator<(const VectorIterator &it)
		{
			return (this->ptr < it.ptr);
		}
		bool operator<=(const VectorIterator &it)
		{
			return (this->ptr <= it.ptr);
		}
		VectorIterator &operator+=(int n)
		{
			while (n > 0) //양수일 때
			{
				n--;
				this->operator++();
			}
			while (n < 0) //음수일 때
			{
				n++;
				this->operator--();
			}
			return (*this);
		}
		VectorIterator &operator-=(int n)
		{
			while (n > 0) //양수일 때
			{
				n--;
				this->operator--();
			}
			while (n < 0) //음수일 때
			{
				n++;
				this->operator++();
			}
			return (*this);
		}
		T &operator[](int n) const
		{
			return (*(*this + n));
		}
		T &operator*(void)
		{
			return *this->ptr;
		}
		T *operator->(void)
		{
			return this->ptr;
		}
	};
	template <typename T, class Category = random_access_iterator_tag>
	class ReverseVectorIterator
	{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

	protected:
		pointer ptr;

	public:
		ReverseVectorIterator() : ptr(NULLPTR){};
		ReverseVectorIterator(pointer p) : ptr(p){};
		~ReverseVectorIterator(){};
		ReverseVectorIterator(const ReverseVectorIterator &iter)
		{
			*this = iter;
		};

		ReverseVectorIterator operator+(int n) const
		{
			ReverseVectorIterator iv(*this);

			iv += n;
			return (iv);
		}
		ReverseVectorIterator operator-(int n) const
		{
			ReverseVectorIterator iv(*this);

			iv -= n;
			return (iv);
		}

		ReverseVectorIterator &operator--(void)
		{
			this->ptr++;
			return (*this);
		}
		ReverseVectorIterator &operator++(void)
		{
			this->ptr--;
			return (*this);
		}
		ReverseVectorIterator operator--(int)
		{
			ReverseVectorIterator iv(*this);

			iv--;
			return (iv);
		}
		ReverseVectorIterator operator++(int)
		{
			ReverseVectorIterator iv(*this);

			iv++;
			return (iv);
		}

		bool operator==(const ReverseVectorIterator &it)
		{
			return (this->ptr == it.ptr);
		}
		bool operator!=(const ReverseVectorIterator &it)
		{
			return (this->ptr != it.ptr);
		}
		bool operator>(const ReverseVectorIterator &it)
		{
			return (this->ptr > it.ptr);
		}
		bool operator>=(const ReverseVectorIterator &it)
		{
			return (this->ptr >= it.ptr);
		}
		bool operator<(const ReverseVectorIterator &it)
		{
			return (this->ptr < it.ptr);
		}
		bool operator<=(const ReverseVectorIterator &it)
		{
			return (this->ptr <= it.ptr);
		}
		ReverseVectorIterator &operator+=(int n)
		{
			while (n > 0) //양수일 때
			{
				n--;
				this->operator--();
			}
			while (n < 0) //음수일 때
			{
				n++;
				this->operator++();
			}
			return (*this);
		}
		ReverseVectorIterator &operator-=(int n)
		{
			while (n > 0) //양수일 때
			{
				n--;
				this->operator++();
			}
			while (n < 0) //음수일 때
			{
				n++;
				this->operator--();
			}
			return (*this);
		}
		T &operator[](int n) const
		{
			return (*(*this + n));
		}
		T &operator*(void)
		{
			return *this->ptr;
		}
		T *operator->(void)
		{
			return this->ptr;
		}
	};
	template <typename T>
	class ConstVectorIterator : public VectorIterator<T>
	{
	public:
		ConstVectorIterator(void) {}
		~ConstVectorIterator(void) {}

		ConstVectorIterator(T *ptr)
		{
			this->ptr = ptr;
		}

		ConstVectorIterator(const ConstVectorIterator &it)
		{
			*this = it;
		}

		ConstVectorIterator &operator=(const ConstVectorIterator &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const T &operator*(void) // dereferenced lvalue
		{
			return (*this->ptr);
		}
	};
	template <typename T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
	public:
		ConstReverseVectorIterator(void) {}
		~ConstReverseVectorIterator(void) {}

		ConstReverseVectorIterator(T *ptr)
		{
			this->ptr = ptr;
		}

		ConstReverseVectorIterator(const ConstReverseVectorIterator &it)
		{
			*this = it;
		}

		ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const T &operator*(void) // dereferenced lvalue
		{
			return (*this->ptr);
		}
	};
}

#endif
