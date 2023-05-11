/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:42:09 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/15 16:21:51 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_comp(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	while (ft_comp(s1[i], set) == 0)
		i++;
	while (s1[i])
	{
		ptr[j] = s1[i];
		i++;
		j++;
	}
	if (ptr[j] == '\0')
		j--;
	while (ft_comp(ptr[j], set) == 0)
	{
		ptr[j] = '\0';
		j--;
	}
	return (ptr);
}

static int	ft_comp(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			c = '\0';
			return (0);
		}
		i++;
	}
	return (1);
}
