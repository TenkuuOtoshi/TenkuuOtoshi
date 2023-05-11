/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:17:53 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/01 18:03:42 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*cs1;
	char	*cs2;
	int		rslt;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (cs1[i] || cs2[i] != '\0'))
	{
		if ((unsigned char)cs1[i] != (unsigned char)cs2[i])
		{
			rslt = (unsigned char)cs1[i] - (unsigned char)cs2[i];
			return (rslt);
		}
		i++;
	}
	return (0);
}
