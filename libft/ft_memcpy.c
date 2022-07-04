/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:23:21 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/06 10:52:20 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cdest;
	char	*csrc;

	i = 0;
	cdest = (char *) dest;
	csrc = (char *) src;
	while (i < n && cdest[i] != '\0')
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
