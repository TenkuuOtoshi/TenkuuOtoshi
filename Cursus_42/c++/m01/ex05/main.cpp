/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:28:08 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 14:03:05 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "harl.h"

int	main(void)
{
	Harl	test;

	test.complain("");
	test.complain("DEBUG");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("ERROR");
	test.complain("HELP");
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// test.complain("");
	// test.complain("ERROR");
	// test.complain("WARNING");
	// test.complain("INFO");
	// test.complain("DEBUG");
	// test.complain(NULL);
	return (0);
}