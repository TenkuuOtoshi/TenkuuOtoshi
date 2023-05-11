/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:25 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/05 14:20:51 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << name + " woke up ! (Frag)" << std::endl;
	_Name = name;
	_Hit_point = 100;
	_Energy_points = 100;
	_Attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << _Name + " fell asleep ! (Frag)" << std::endl;
}

FragTrap::FragTrap(const FragTrap &a) : ClapTrap(a)
{
	std::cout << "Copy Constructor of " + a._Name + " called" << std::endl;
	_Name = a._Name;
	_Hit_point = a._Hit_point;
	_Energy_points = a._Energy_points;
	_Attack_damage = a._Attack_damage;
}

FragTrap& FragTrap::operator = (const FragTrap &a)
{
	std::cout << "Copy assignment operator of " + a._Name + " called" << std::endl;
	_Name = a._Name;
	_Hit_point = a._Hit_point;
	_Energy_points = a._Energy_points;
	_Attack_damage = a._Attack_damage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_Hit_point > 0 && _Energy_points > 0)
	{
		std::cout << "FragTrap " + _Name + " launched a suprise attack on " + target;
		std::cout << " causing " << _Attack_damage << " points of damage !" << std::endl;
		this->_Energy_points--;
	}
	
}

void	FragTrap::highFivesGuys(void)
{
	if (_Energy_points > 0 && _Hit_point > 0)
	{
		std::cout << "Hey humans, this FragTrap unit " + _Name +" is in need of some positive energy! Anyone up for some high fives? !" << std::endl;
	}
}
