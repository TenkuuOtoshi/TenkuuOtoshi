/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:17:53 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/19 12:11:17 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;
	int				rslt;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n || (cs1[i] != '\0' || cs2[i] != '\0'))
	{
		if (i < n)
		{
			if (cs1[i] != cs2[i])
			{
				rslt = cs1[i] - cs2[i];
				return (rslt);
			}
		}
		i++;
	}
	return (0);
}
