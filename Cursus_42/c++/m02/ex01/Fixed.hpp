/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:07:29 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/02 18:29:00 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.h"

class	Fixed
{
	public :

								Fixed();
								Fixed(const int n);
								Fixed(const float n);
								~Fixed();
								Fixed(const Fixed &a);
				int				toInt(void) const;
				float			toFloat(void) const;
				int				getRawBits(void) const;
				void			setRawBits(int const raw);
				Fixed&			operator = (const Fixed &a);

	private :

	int					_fixed_point_value;
	static const int	_Fractional_bits = 8;

};
	std::ostream&	operator<<(std::ostream &ofs, const Fixed &a);
