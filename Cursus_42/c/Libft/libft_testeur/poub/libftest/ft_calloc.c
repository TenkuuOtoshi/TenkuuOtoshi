/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:26:51 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/04 14:00:05 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (0);
	while (ptr[i])
	{
		ptr[i] = 0;
	}
	return (ptr);
}
