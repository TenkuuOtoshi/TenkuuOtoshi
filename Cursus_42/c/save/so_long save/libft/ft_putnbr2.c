/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:13:20 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/09 11:32:41 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb, int count)
{
	if (nb != 0)
		count = ft_putnbr2(nb, count);
	else
		count = ft_putchar2(nb + '0', count);
	return (count);
}

int	ft_putnbr2(int nb, int count)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		write(1, "147483648", 9);
		count = count + 11;
	}
	else if (nb < 0)
	{
		count = ft_putchar2('-', count);
		nb *= -1;
	}		
	if (nb > 0)
	{
		count = ft_putnbr2(nb / 10, count);
		count = count + ft_putchar2(nb % 10 + '0', count);
	}
	return (count);
}
