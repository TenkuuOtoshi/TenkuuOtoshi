/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:13:20 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/09 11:34:06 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr2(unsigned int nb, int count)
{
	if (nb != 0)
		count = ft_putunbr22(nb, count);
	else
		count = ft_putchar2(nb + '0', count);
	return (count);
}

int	ft_putunbr22(unsigned int nb, int count)
{
	if (nb > 0)
	{
		count = ft_putunbr22(nb / 10, count);
		count = count + ft_putchar2(nb % 10 + '0', count);
	}
	return (count);
}
