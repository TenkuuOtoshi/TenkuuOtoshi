/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:00:19 by tlarraze          #+#    #+#             */
/*   Updated: 2022/05/03 14:09:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_voidp(long unsigned int p, int count)
{
	if (!p)
		count = ft_putstr2("(nil)", count);
	else
	{
		count = ft_putstr2("0x", count);
		count = ft_puthexminp(p, count);
	}
	return (count);
}
