/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:07:44 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/04 13:37:08 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.h"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_value = 0;
	return ;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = n << _Fractional_bits;
	return ;
}

int	Fixed::toInt(void) const
{
	int	n;

	n = _fixed_point_value >> _Fractional_bits;
	return (n);
}

float	Fixed::toFloat(void) const
{
	float	n;

	n = getRawBits() / (float)(1 << 8);
	return (n);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(n * (1 << 8));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &a)
		this->setRawBits(a.getRawBits());
	return ;
}

Fixed&	Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a)
		this->setRawBits(a.getRawBits());
	return (*this);
}

std::ostream&	operator<<(std::ostream &ofs, const Fixed &a)
{
	float	n;
	n = a.getRawBits() / (float)(1 << 8);
	ofs << n;
	return (ofs);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point_value = raw;
	return ;
}
