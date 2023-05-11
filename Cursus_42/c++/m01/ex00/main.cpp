/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:14:46 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 14:41:04 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

int	main()
{
	Zombie	zomb;
	Zombie	*zomb_ptr;

	zomb.give_name("Bob");
	zomb.announce();

	zomb.randomChump("Roger");
	zomb_ptr = zomb.newZombie("Rick");
	zomb_ptr->announce();

	delete zomb_ptr;
	zomb_ptr = zomb.newZombie("John");
	zomb_ptr->announce();
	delete zomb_ptr;
	zomb.randomChump("Alexender The Great 3");
	return (0);
	
}
