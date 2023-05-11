/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:28:08 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/11 14:12:48 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "harl.h"

int	main(int argc, char **argv)
{
	Harl	test;

	if (argc != 2)
	{
		std::cout << "Error\nCorrect use is \"./harlFilter <level>" << std::endl;
		return (0);
	}
	test.complain(argv[1]);
	return (0);
}