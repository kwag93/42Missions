#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include "colors.h"

template <class Container>
void printContainer(Container c)
{
	int n;
	typename Container::iterator i;

	i = c.begin();
	n = 0;
	std::cout << _YELLOW << "---------------------- "
			  << "[" << _GREEN;
	while (i != c.end())
	{
		if (n != 0)
			std::cout << ", ";
		std::cout << _GREEN << *i << _END;
		i++;
		n++;
	}
	std::cout << _YELLOW << "]" << _END << std::endl;
	std::cout << std::endl;
}

void test_map(void);
void test_vector(void);

#endif
