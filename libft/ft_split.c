/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:32:09 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/23 11:01:18 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_bigwhile(char **pt2, const char *s, int c, int si);
static size_t	shin_ft_strlcpy(char *dst, const char *src, char c);
static int		ft_countc(const char *s, char c);
static size_t	ft_shin_strlen(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**pt2;
	int		si;

	si = 0;
	pt2 = (char **)ft_calloc((ft_countc(s, c) + 1), sizeof(char *));
	if (!pt2)
		return (0);
	if (s[0] == 0)
	{
		pt2[0] = 0;
		return (pt2);
	}
	while (s[si] == c)
		si++;
	return (ft_bigwhile(pt2, s, c, si));
}

static char	**ft_bigwhile(char **pt2, const char *s, int c, int si)
{
	int	pi2;

	pi2 = 0;
	while (s[si] != '\0')
	{
		pt2[pi2] = (char *)ft_calloc((ft_shin_strlen(s + si, c) + 1),
				sizeof(char));
		if (!pt2[pi2])
			return (NULL);
		shin_ft_strlcpy(pt2[pi2], s + si, c);
		pi2++;
		while (s[si] != c && s[si] != '\0')
			si++;
		while (s[si] == c && s[si] != '\0')
			si++;
	}	
	pt2[pi2] = NULL;
	return (pt2);
}

static int	ft_countc(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

static size_t	shin_ft_strlcpy(char *dst, const char *src, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dst[i] = src[i];
		i++;
		len++;
	}
	dst[i] = '\0';
	return (len);
}

static size_t	ft_shin_strlen(const char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && s[count] != c)
		count++;
	return (count);
}
