/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:46:08 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 14:17:14 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.h"

Weapon::Weapon(std::string	new_type)
{
	Weapon::setType(new_type);
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
	return ;
}

const std::string&	Weapon::getType(void)	const
{
	return (_type);
}
