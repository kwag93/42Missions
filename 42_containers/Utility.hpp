#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <type_traits>
#define NULLPTR 0

namespace ft
{
	struct input_iterator_tag
	{
	};
	struct output_iterator_tag
	{
	};
	struct forward_iterator_tag : input_iterator_tag
	{
	};
	struct bidirectional_iterator_tag : forward_iterator_tag
	{
	};
	struct random_access_iterator_tag : bidirectional_iterator_tag
	{
	};
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
	template <bool is_integral, typename T>
	struct is_integral_res
	{
		typedef T type;
		static const bool value = is_integral;
	};

	template <typename>
	struct is_integral_type : public is_integral_res<false, bool>
	{
	};

	template <>
	struct is_integral_type<bool> : public is_integral_res<true, bool>
	{
	};

	template <>
	struct is_integral_type<char> : public is_integral_res<true, char>
	{
	};

	template <>
	struct is_integral_type<signed char> : public is_integral_res<true, signed char>
	{
	};

	template <>
	struct is_integral_type<short int> : public is_integral_res<true, short int>
	{
	};

	template <>
	struct is_integral_type<int> : public is_integral_res<true, int>
	{
	};

	template <>
	struct is_integral_type<long int> : public is_integral_res<true, long int>
	{
	};

	template <>
	struct is_integral_type<long long int> : public is_integral_res<true, long long int>
	{
	};

	template <>
	struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char>
	{
	};

	template <>
	struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int>
	{
	};

	template <>
	struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int>
	{
	};

	template <>
	struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int>
	{
	};

	template <>
	struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int>
	{
	};

	template <typename T>
	struct is_integral : public is_integral_type<T>
	{
	};

	template <bool B, typename T = void>
	struct enable_if
	{
	};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <typename T, typename C = typename T::iterator_category>
	struct is_input_iterator
	{
		typedef char yes[1];
		typedef char no[2];

		static yes &test(ft::input_iterator_tag); // input_iterator 면 이쪽으로 들어온다.
		static no &test(...);					  //input iterator tag가 아니면 no가 반환이 되서 value가 false가 된다.

		static const bool value = (sizeof(test(C())) == sizeof(yes));
	};

	template <class T>
	struct less
	{
		bool operator()(const T &x, const T &y) const { return (x < y); }
	};

	template <class T1, class T2>
	class pair
	{
	public:
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		pair() : first(), second() {}
		~pair() {}
		template <class U, class V>
		pair(const pair<U, V> &other) : first(other.first), second(other.second) {}
		pair(const first_type &a, const second_type &b) : first(a), second(b) {}
		pair &operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};
	template <class T1, class T2>
	bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template <class T1, class T2>
	bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}
	template <class T1, class T2>
	bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	template <class T1, class T2>
	bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}
	template <class T1, class T2>
	bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}
	template <class T1, class T2>
	bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}
	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
}

#endif
