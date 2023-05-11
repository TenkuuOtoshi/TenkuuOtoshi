/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:00:08 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/15 15:45:24 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tab;
	char	*cdest;
	char	*csrc;

	tab = (char *)ft_calloc(ft_strlen(src - n), sizeof(char));
	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	while (i < n)
	{
		tab[i] = csrc[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		cdest[i] = tab[i];
		i++;
	}
	free(tab);
	return (dest);
}
