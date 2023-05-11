/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:07:29 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/02 18:36:20 by tlarraze         ###   ########.fr       */
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
				int					toInt(void) const;
				float				toFloat(void) const;
				int					getRawBits(void) const;
				void				setRawBits(int const raw);
				static Fixed&		min(Fixed &a, Fixed &b);
				static Fixed&		max(Fixed &a, Fixed &b);
				static const Fixed&	min(const Fixed &a, const Fixed &b);
				static const Fixed&	max(const Fixed &a, const Fixed &b);

				Fixed				operator = (const Fixed &a);
				Fixed				operator + (const Fixed &a);
				Fixed				operator ++ ();			//++n
				float				operator ++ (int n);	//n++
				Fixed				operator -- ();			//--n
				float				operator -- (int n);	//n--
				Fixed				operator - (const Fixed &a);
				Fixed				operator * (const Fixed &a);
				Fixed				operator / (const Fixed &a);
				bool				operator == (const Fixed &a) const;
				bool				operator != (const Fixed &a) const;
				bool				operator > (const Fixed &a) const;
				bool				operator < (const Fixed &a) const;
				bool				operator >= (const Fixed &a) const;
				bool				operator <= (const Fixed &a) const;

	private :

	int					_fixed_point_value;
	static const int	_Fractional_bits = 8;

};
	std::ostream&	operator<<(std::ostream &ofs, const Fixed &a);
