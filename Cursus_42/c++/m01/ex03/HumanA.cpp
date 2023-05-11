/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:13:48 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 14:17:14 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) 
{
	this->_name = name;
	return ;
}

HumanA::~HumanA(void)
{
    return ;
}

std::string	HumanA::get_name(void)
{
	return (this->_name);
}

void	HumanA::attack(void)
{
	std::cout << get_name() << " attacks with their " << _weapon.getType() << std::endl;
	return ;
}

