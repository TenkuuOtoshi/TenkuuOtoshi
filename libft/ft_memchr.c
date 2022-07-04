/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:44:05 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/05 14:35:45 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	cs = (unsigned char *)s;
	i = 0;
	while (i < n || cs[i] != '\0')
	{
		if (i < n)
		{
			if (cs[i] == (unsigned char)c)
				return ((void *)(s + i));
		}
		i++;
	}
	return (0);
}
