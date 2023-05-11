/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:21:18 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/03 14:20:15 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

int	main(void)
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

	std::cout << "\n-------ScavTrap-------\n" << std::endl;
	ScavTrap	t("Tsuna");
	t.attack(a.get_Name());
	a.takeDamage(t.get_Attack_damage());
	a.attack(t.get_Name());
	t.takeDamage(a.get_Attack_damage());
	t.guardGate();
}