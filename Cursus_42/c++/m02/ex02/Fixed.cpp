/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:07:44 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/03 13:43:34 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.h"

Fixed::Fixed(void)
{
//	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_value = 0;
	return ;
}

Fixed::Fixed(const Fixed &a)
{
//	std::cout << "Copy constructor called" << std::endl;
	if (this != &a)
		this->setRawBits(a.getRawBits());
	return ;
}

Fixed	Fixed::operator = (const Fixed &a)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a)
		this->setRawBits(a.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
//	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n)
{
//	std::cout << "Int constructor called" << std::endl;
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
//	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(n * (1 << 8));
	return ;
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

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}


////////////////////////////////////////////////
///////////////     OPERATOR     ///////////////
////////////////////////////////////////////////

Fixed	Fixed::operator + (const Fixed &a)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + a.getRawBits());
	return (result);
}

Fixed	Fixed::operator - (const Fixed &a)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - a.getRawBits());
	return (result);
}

Fixed	Fixed::operator * (const Fixed &a)
{
	Fixed	result;

	result.setRawBits((this->getRawBits() * ((a.getRawBits() / (1 << 8)))));
	return (result);
}

Fixed	Fixed::operator / (const Fixed &a)
{
	Fixed	result;

	if (a.getRawBits() / (1 << 8) == 0)
	{
		std::cout << "Error : division by 0 are not allowed " << std::ends;
		result.setRawBits(0);
		return (result);
	}
	result.setRawBits(this->getRawBits() / ((a.getRawBits() / (1 << 8))));
	return (result);
}

Fixed	Fixed::operator ++ ()
{
	_fixed_point_value++;
	return (*this);
}

float	Fixed::operator ++ (int n)
{
	float	r;
	r = getRawBits() / (float)(1 << 8);
	_fixed_point_value++;
	return (r);
	(void)n;
}

Fixed	Fixed::operator -- ()
{
	_fixed_point_value--;
	return (*this);
}

float	Fixed::operator -- (int n)
{
	float	r;
	r = getRawBits() / (float)(1 << 8);
	_fixed_point_value--;
	return (r);
	(void)n;
}

bool	Fixed::operator == (const Fixed &a) const
{
	if (getRawBits() == a.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator != (const Fixed &a) const
{
	if (getRawBits() != a.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator > (const Fixed &a) const
{
	if (getRawBits() > a.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator < (const Fixed &a) const
{
	if (getRawBits() < a.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator >= (const Fixed &a) const
{
	if (getRawBits() >= a.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator <= (const Fixed &a) const
{
	if (getRawBits() <= a.getRawBits())
		return (true);
	return (false);
}

std::ostream&	operator << (std::ostream &ofs, const Fixed &a)
{
	float	n;
	n = a.getRawBits() / (float)(1 << 8);
	ofs << n;
	return (ofs);
}