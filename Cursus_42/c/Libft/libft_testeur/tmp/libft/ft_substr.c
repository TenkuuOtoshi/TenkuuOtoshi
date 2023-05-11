/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:02:21 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/15 16:19:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*st;
	size_t	i;

	i = 0;
	st = (char *)&s[start];
	ptr = (char *)malloc(ft_strlen(st) + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ptr);
	while (st[i] != '\0' && i < len)
	{
		ptr[i] = st[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
