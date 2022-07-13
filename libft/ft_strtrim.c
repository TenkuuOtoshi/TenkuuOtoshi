/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:42:09 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/19 13:09:29 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comp(char c, const char *set);
static int	ft_count(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (ft_comp(s1[i], set) == 0)
		i++;
	return (ft_substr(s1, i, ft_count(s1, set)));
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

static	int	ft_count(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_comp(s1[i], set) == 0)
		i++;
	while (s1[i] != '\0')
	{
		i++;
		count++;
	}
	i--;
	while (ft_comp(s1[i], set) == 0)
	{
		i--;
		count--;
	}
	return (count);
}
