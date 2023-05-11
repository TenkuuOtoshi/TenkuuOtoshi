/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:13:20 by tlarraze          #+#    #+#             */
/*   Updated: 2022/05/03 14:18:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb, int count)
{
	if (nb != 0)
		count = ft_putunbr2(nb, count);
	else
		count = ft_putchar(nb + '0', count);
	return (count);
}

int	ft_putunbr2(unsigned int nb, int count)
{
	if (nb > 0)
	{
		count = ft_putunbr2(nb / 10, count);
		count = count + ft_putchar(nb % 10 + '0', count);
	}
	return (count);
}
