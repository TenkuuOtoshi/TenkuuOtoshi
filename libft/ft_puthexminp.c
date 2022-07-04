/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexminp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:07:56 by tlarraze          #+#    #+#             */
/*   Updated: 2022/05/03 14:10:04 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexminp(unsigned long int nb, int count)
{
	if (nb == 0)
		count = ft_putchar2('0', count);
	if (nb != 0)
		count = ft_puthexminp2(nb, count);
	return (count);
}

int	ft_puthexminp2(unsigned long int nb, int count)
{	
	if (nb >= 16)
	{
		count = ft_puthexminp2(nb / 16, count);
		count = ft_puthexminp2(nb % 16, count);
	}
	if (nb >= 10 && nb <= 15)
	{
		count = count + ft_putchar2(nb + 'a' - 10, count);
	}
	if (nb <= 9)
		count = count + ft_putchar2(nb + '0', count);
	return (count);
}
