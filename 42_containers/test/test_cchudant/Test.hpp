/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 06:27:31 by cchudant          #+#    #+#             */
/*   Updated: 2021/09/07 15:50:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP
#include "../../Vector.hpp"
#include "../../Stack.hpp"
#include "../../Map.hpp"

#include <iostream>
#include <assert.h>

class ConstrCounter
{
public:
	static int g_constr;
	static int g_destr;

	int val;

	ConstrCounter(int val);
	ConstrCounter(const ConstrCounter &o);
	~ConstrCounter();

	static void reset_counters();
};

bool operator==(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator!=(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator<(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator<=(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator>(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator>=(const ConstrCounter &lhs, const ConstrCounter &rhs);

void test_one(std::string name, void (&fn)());

void test_vector();
void test_stack();
void test_map();

#endif
