/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:54:38 by tlarraze          #+#    #+#             */
/*   Updated: 2022/05/03 11:26:46 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr2(char *str, int count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr2("(null)", count);
		return (6);
	}
	while (str[i] != '\0')
	{
		count = count + ft_putchar2(str[i], count);
		i++;
	}
	return (count);
}
