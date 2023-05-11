/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:13:48 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 14:17:14 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.h"

HumanB::HumanB(std::string name)
{
	_weapon = NULL;
	_name = name;
	return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void	HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << get_name() << " attacks with their fist (no weapon)" << std::endl;
	else
		std::cout << get_name() << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

std::string	HumanB::get_name(void)
{
	return (this->_name);
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return ;
}

void	HumanB::delWeapon()
{
	this->_weapon = NULL;
	return ;
}