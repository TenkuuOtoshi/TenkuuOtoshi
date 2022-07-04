/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:35:36 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/22 14:37:09 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (ptr == NULL)
		return (0);
	ft_strcpy(ptr, s);
	return (ptr);
}

static size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
