/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:22:25 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/05 15:41:26 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "m04.h"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator = (const Dog &a)
{
	type = a.type;
	return (*this);
}

Dog::Dog(const Dog &a) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->operator=(a);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog bark !" << std::endl;
}
