/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:45:41 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 14:17:14 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.h"

int	main()
{
	{
		Weapon blade = Weapon("Dual Blade");
		HumanA Yoshi("Yoshi", blade);
		Yoshi.attack();
		blade.setType("Great Sword");
		Yoshi.attack();
	}
	std::cout << std::endl << std::endl;
	{
		Weapon Bow = Weapon("Bow");
		HumanB jim("Luigi");
		jim.attack();
		jim.setWeapon(Bow);
		jim.attack();
		Bow.setType("Ray Gun");
		jim.attack();
	}

	std::cout << std::endl << std::endl;

	{
		Weapon club = Weapon("crude spiked club");
		HumanB bob("Bob");
		club.setType("some other type of club");
		bob.attack();
		bob.setWeapon(club);
		bob.attack();
		bob.delWeapon();
		bob.attack();
	}

	std::cout << std::endl << "[ SUBJECT TEST ]" << std::endl << std::endl;

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;

	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return (0);
}