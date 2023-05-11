/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:07:29 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/02 18:18:03 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.h"

class	Fixed
{
	public :

						Fixed();
						~Fixed();
						Fixed(const Fixed &a);
				Fixed&	operator = (const Fixed &a);
				int		getRawBits(void) const;
				void	setRawBits(int const raw);

	private :

	int					fixed_point_number;
	static const int	Fractional_bits = 8;

	
};