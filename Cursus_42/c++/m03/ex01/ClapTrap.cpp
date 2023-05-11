/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:19:09 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/05 14:43:43 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << name + " is here !" << std::endl;
	_Name = name;
	_Hit_point = 10;
	_Energy_points = 10;
	_Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &a)
{
	std::cout << "Copy Constructor of " + a._Name + " called" << std::endl;
	_Name = a._Name;
	_Hit_point = a._Hit_point;
	_Energy_points = a._Energy_points;
	_Attack_damage = a._Attack_damage;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &a)
{
	std::cout << "Copy assignment operator of " + a._Name + " called" << std::endl;
	_Name = a._Name;
	_Hit_point = a._Hit_point;
	_Energy_points = a._Energy_points;
	_Attack_damage = a._Attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << _Name + " is gone !" << std::endl;
}

void	ClapTrap::attack( const std::string& target)
{
	if (this->_Hit_point > 0 && _Energy_points > 0)
	{
		std::cout << "ClapTrap " + _Name + " attacks " + target;
		std::cout << " causing " << _Attack_damage << " points of damage !" << std::endl;
		this->_Energy_points--;
	}
	
}

void	ClapTrap::takeDamage(unsigned int ammout)
{
	if (_Hit_point > 0 && _Energy_points > 0)
	{
		std::cout << "ClapTrap " + _Name + " lost " << ammout << " Hit points";
		_Hit_point -= ammout;
		if (_Hit_point <= 0)
			std::cout << " (0 left)\nClapTrap " + _Name + " is dead" << std::endl;
		else
			std::cout << " (" << _Hit_point << " left)" << std::endl;
	}
	
}

void	ClapTrap::beRepaired(unsigned int ammout)
{
	if (_Hit_point > 0 && _Energy_points > 0)
	{
		std::cout << "ClapTrap " + _Name + " Repaired itself and";
		std::cout << " gained " <<	ammout << " hit points" << std::endl;
		_Hit_point += ammout;
		if (_Hit_point > 10)
			_Hit_point = 10;
		_Energy_points--;
	}
}

std::string	ClapTrap::get_Name()
{
	return (_Name);
}

int	ClapTrap::get_Attack_damage()
{
	return (_Attack_damage);
}