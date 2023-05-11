/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:04:25 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/26 13:40:35 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int			i;
	long int	result;
	int			sign;
	int			tmp;

	i = 0;
	result = 0;
	sign = 1;
	tmp = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
		tmp++;
	}
	if (tmp > 1)
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
		result = result * 10 + nptr[i++] - '0';
	result = result * sign;
	return (result);
}
