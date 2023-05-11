/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:56:55 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/11 13:59:52 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << name + " say Hello World !" << std::endl;
	_Name = name;
	_Hit_point = 100;
	_Energy_points = 50;
	_Attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << _Name + " say Goodbye World !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &a) : ClapTrap(a)
{
	std::cout << "Copy Constructor of " + a._Name + " called" << std::endl;
	_Name = a._Name;
	_Hit_point = a._Hit_point;
	_Energy_points = a._Energy_points;
	_Attack_damage = a._Attack_damage;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &a)
{
	std::cout << "Copy assignment operator of " + a._Name + " called" << std::endl;
	_Name = a._Name;
	_Hit_point = a._Hit_point;
	_Energy_points = a._Energy_points;
	_Attack_damage = a._Attack_damage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_Hit_point > 0 && _Energy_points > 0)
	{
		std::cout << "ClapTrap " + _Name + " launched a suprise attack on " + target;
		std::cout << " causing " << _Attack_damage << " points of damage !" << std::endl;
		this->_Energy_points--;
	}
	
}

void	ScavTrap::guardGate()
{
	if (this->_Hit_point > 0 && _Energy_points > 0)
	{
		std::cout << "ScavTrap " + _Name + " is now in Gate keeper Mode, You shall Not pass !" << std::endl;
		_Energy_points--;
	}
}