/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexmaj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:50:24 by tlarraze          #+#    #+#             */
/*   Updated: 2022/05/03 14:06:28 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexmaj(unsigned int nb, int count)
{
	if (nb == 0)
		count = ft_putchar2('0', count);
	if (nb != 0)
		count = ft_puthexmaj2(nb, count);
	return (count);
}

int	ft_puthexmaj2(unsigned int nb, int count)
{	
	if (nb >= 16)
	{
		count = ft_puthexmaj2(nb / 16, count);
		count = ft_puthexmaj2(nb % 16, count);
	}
	if (nb >= 10 && nb <= 15)
	{
		count = count + ft_putchar2(nb + 'A' - 10, count);
	}
	if (nb <= 9)
		count = count + ft_putchar2(nb + '0', count);
	return (count);
}
