/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:55:59 by tlarraze          #+#    #+#             */
/*   Updated: 2022/03/31 17:00:34 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	len2;

	i = 0;
	j = 0;
	len = 0;
	len2 = 0;
	while (dst[len])
		len++;
	i = len;
	while (src[len2])
		len2++;
	if (size < len)
		return (size + len2);
	if (size == 0)
		return (len + len2);
	while (i + j < size - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len + len2);
}
