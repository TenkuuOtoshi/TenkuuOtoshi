/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:52:44 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/28 15:23:32 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test.hpp"
#include <algorithm>


using namespace std;

int	main(int argc, char **argv)
{
	std::string str;
	test_class	test_instance;
	int	i;

	i = 1;
	if (argc == 1)
	 	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i])
		{
			str = argv[i];
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout << str;
			i++;
		}
		std::cout << endl;
	}
	return (0);
	(void)test_instance;

}









