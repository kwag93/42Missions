/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:31:12 by skybt             #+#    #+#             */
/*   Updated: 2021/09/03 10:45:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"

int main()
{
	std::cout << ":: Vector ::" << std::endl;
	test_vector();
	std::cout << ":: Stack ::" << std::endl;
	test_stack();
	std::cout << ":: Map ::" << std::endl;
	test_map();
	std::cout << ":: Everything is ok! ::" << std::endl;
	return 0;
}
