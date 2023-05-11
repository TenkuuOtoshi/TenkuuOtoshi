/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:22:25 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/05 17:30:41 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "m04.h"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator = (const Animal &a)
{
	type = a.type;
	return (*this);
}

Animal::Animal(const Animal &a)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->operator=(a);
}

std::string	Animal::get_type(void) const
{
	return (type);
}

void	Animal::set_type(std::string type)
{
	this->type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal " + type + " Yell !" << std::endl;
}