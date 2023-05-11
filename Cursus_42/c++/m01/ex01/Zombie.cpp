/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:17:10 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/04 15:20:27 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

Zombie::Zombie(void)
{
	std::cout << "Zombie created" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::_name << " destroyed" << std::endl;
	return ;
}

void	Zombie::give_name(std::string name)
{
	this->_name = name;
	return ;
}

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie	*ptr;

	ptr = new Zombie;
	ptr->give_name(name);
	return (ptr);
}

void	Zombie::randomChump(std::string name)
{
	Zombie	zomb;

	zomb.give_name(name);
	zomb.announce();
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}