/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:07:00 by tlarraze          #+#    #+#             */
/*   Updated: 2022/05/03 14:06:50 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexmin(unsigned int nb, int count)
{
	if (nb == 0)
		count = ft_putchar2('0', count);
	if (nb != 0)
		count = ft_puthexmin2(nb, count);
	return (count);
}

int	ft_puthexmin2(unsigned int nb, int count)
{	
	if (nb >= 16)
	{
		count = ft_puthexmin2(nb / 16, count);
		count = ft_puthexmin2(nb % 16, count);
	}
	if (nb >= 10 && nb <= 15)
	{
		count = count + ft_putchar2(nb + 'a' - 10, count);
	}
	if (nb <= 9)
		count = count + ft_putchar2(nb + '0', count);
	return (count);
}
