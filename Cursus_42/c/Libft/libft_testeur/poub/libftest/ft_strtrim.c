/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:42:09 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/05 10:10:52 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_comp(char c, const char *set);
int	ft_strlen(char *str);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr;
	int		tmp;

	i = 0;
	j = 0;
	tmp = ft_strlen(s1);
	ptr = (char *)malloc(*s1 * sizeof(char));
	if (ptr == NULL)
		return (0);
	while (ft_comp(s1[i], set) == 0)
		i++;
	while (ft_comp(s1[tmp], set) == 0)
		{
			s1[tmp];
			tmp--;
		}
	while (s1[i] != '\0' && i < tmp)
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	while (ft_comp(ptr[j], set) == 0)
	{
		ptr[j] = '\0';
		j--;
	}
	return (ptr);
}


int	ft_comp(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}
