/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:51:44 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/05 10:45:55 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpip.h"
#include "libpipb.h"
/*
ft_Split version pour pipex
*/
char	**ft_splitex(char *s)
{
	int		i;
	int		y;
	char	**str;

	i = 0;
	y = 0;
	str = (char **)ft_calloc(ft_count(s) + 1, sizeof(char *));
	while (s[i] == ' ')
		i++;
	str[y] = s + i;
	y++;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' && s[i + 1] == 39)
		{
			ft_big_while(s, str, i, y);
			y++;
		}
		if (s[i] == ' ' && s[i + 1] == 34)
		{
			s[i] = '\0';
			str[y] = s + i + 1;
			i++;
			s[i] = ' ';
			while (s[i] != 34 && s[i] != '\0')
			{
				if (s[i] == 39)
					s[i] = ' ';
				i++;
			}
			s[i] = ' ';
			i++;
			if (s[i] == 39)
				s[i] = ' ';
			y++;
		}
		if (s[i] == ' ' && s[i + 1] != '\0')
		{
			str[y] = s + i + 1;
			s[i] = '\0';
			i++;
			y++;
		}
		i++;
	}
	str[y] = NULL;
	return (str);
}

int	ft_count(char *str)
{
	int	i;
	int	c;

	c = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == 39 && ft_check(str, i) == 0)
		{
			i++;
			while (str[i] != 39)
				i++;
			c++;
		}
		if (str[i] == ' ')
			c++;
		i++;
	}
	return (c);
}

int	ft_check(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '}')
			return (0);
		i++;
	}
	return (-1);
}

int	ft_big_while(char *s, char **str, int i, int y)
{
	s[i] = '\0';
	str[y] = s + i + 1;
	i++;
	s[i] = ' ';
	while (s[i] != 39 && s[i] != '\0')
	{
		if (s[i] == 34)
			s[i] = ' ';
		i++;
	}
	s[i] = ' ';
	if (s[i] == 39)
		s[i] = ' ';
	return (i);
}

