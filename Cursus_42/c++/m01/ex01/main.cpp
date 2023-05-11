/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:14:46 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/10 14:03:40 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

int	main()
{
	Zombie	zomb;
	Zombie	*zomb_ptr;

	zomb.give_name("Bob");
	zomb.announce();

	zomb_ptr = zomb.zombieHorde(0,"Roger");
	zomb_ptr = zomb.zombieHorde(-666,"Sam");
	zomb_ptr = zomb.zombieHorde(-42,"Dude");
	zomb_ptr = zomb.zombieHorde(5,"Smith");

	zomb_ptr[0].announce();
	zomb_ptr[1].announce();
	zomb_ptr[2].announce();
	zomb_ptr[3].announce();
	zomb_ptr[4].announce();

	delete[] zomb_ptr;
	return (0);
}