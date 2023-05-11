/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:41:59 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/02 18:41:04 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.h"

int	main()
{
	Fixed	a;
	Fixed	t(10);
	Fixed	q(0);
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);
	Fixed const	r(10);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "a + b = " << a << " + " << b << " = " << a+b << std::endl;
	a = Fixed(1234.4321f);
	std::cout << "a - b = " << a << " - " << b << " = " << a-b << std::endl;
	std::cout << "t * q = " << t << " * " << q << " = " << t*q << std::endl;
	t = Fixed(10);
	std::cout << "t / q = " << t << " / " << q << " = " << t/q << std::endl;

	if (a > b)
		std::cout << "a > b" << " " << a << " > " << b << std::endl;

	if (a < b)
		std::cout << "a < b" << " " << a << " < " << b << std::endl;

	if (a >= b)
		std::cout << "a >= b" << " " << a << " >= " << b << std::endl;

	if (a <= b)
		std::cout << "a <= b" << " " << a << " <= " << b << std::endl;

	if (r == b)
		std::cout << "r == b " << r << " = " << b << std::endl;
	if (r != c)
		std::cout << "r != c " << r << " != " << c << std::endl;
	
	std::cout << q++ << std::endl;
	std::cout << q << std::endl;
	std::cout << ++q << std::endl;

	std::cout << "go --" << std::endl;
	q = Fixed(0);
	std::cout << q-- << std::endl;
	std::cout << q << std::endl;
	std::cout << --q << std::endl;
	
	a = Fixed(0);
	Fixed const bb( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << bb << std::endl;
	std::cout << Fixed().max( a, bb ) << std::endl;
	std::cout << Fixed().min( a, bb ) << std::endl;
}