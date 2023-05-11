/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:21:18 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/05 14:41:35 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

int	main(void)
{
	{
		ClapTrap	a("Robot");
		ClapTrap	b("John");

		a.attack(b.get_Name());	
		b.takeDamage(a.get_Attack_damage());
		b.beRepaired(5);
		a.attack(b.get_Name());	
		b.takeDamage(a.get_Attack_damage());
		a.attack(b.get_Name());	
		b.takeDamage(a.get_Attack_damage());
		std::cout << "\n-------END ALL DESTRUCTOR START HERE-------\n" << std::endl;

	}
	std::cout << "\n\n-------ScavTrap-------\n\n" << std::endl;
	{
		ClapTrap	a("Robot");
		ScavTrap	b("Tsuna");

		b.attack(a.get_Name());
		a.takeDamage(b.get_Attack_damage());
		a.attack(b.get_Name());
		b.takeDamage(a.get_Attack_damage());
		b.beRepaired(6);
		b.guardGate();
		std::cout << "\n-------END ALL DESTRUCTOR START HERE-------\n" << std::endl;
	}
	
	//need to change the ClapTrap of the dmg takken cause they all say ClapTrap

	std::cout << "\n\n-------FragTrap-------\n\n" << std::endl;
	{
		ScavTrap	a("Tsuna");
		FragTrap	b("Reborn");
		b.highFivesGuys();
		b.attack(b.get_Name());
		a.takeDamage(b.get_Attack_damage());
		a.takeDamage(b.get_Attack_damage());
		a.takeDamage(b.get_Attack_damage());
		a.takeDamage(b.get_Attack_damage());
		a.takeDamage(b.get_Attack_damage());
		a.takeDamage(b.get_Attack_damage());
		a.takeDamage(b.get_Attack_damage());
		a.takeDamage(b.get_Attack_damage());
		a.takeDamage(b.get_Attack_damage());
		a.beRepaired(6);
		std::cout << "\n-------END ALL DESTRUCTOR START HERE-------\n" << std::endl;
	}

}