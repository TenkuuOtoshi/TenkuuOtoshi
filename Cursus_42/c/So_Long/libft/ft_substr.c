/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:02:21 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/19 12:06:55 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*st;
	size_t	i;

	i = 0;
	st = (char *)&s[start];
	ptr = (char *)ft_calloc(ft_count(s, start, len) + 1, sizeof(char));
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

static int	ft_count(char const *s, unsigned int start, size_t len)
{
	char	*st;
	size_t	i;

	i = 0;
	st = (char *)&s[start];
	if (start > ft_strlen(s))
		return (0);
	while (st[i] != '\0' && i < len)
		i++;
	return (i);
}
