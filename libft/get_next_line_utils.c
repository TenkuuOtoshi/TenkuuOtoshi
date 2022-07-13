/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:42:09 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/09 11:22:43 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2, int y)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	ptr = ft_calloc(i + j + 1, sizeof(char));
	if (ptr == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	if (y == 0)
		free(s1);
	free(s2);
	return (ptr);
}

char	*ft_check_buff(char *buff)
{
	int		i;
	int		size;
	char	*tmp;
	char	*tmpbuff;

	size = 0;
	while (buff[size] != '\0')
		size++;
	i = ft_search_nl(buff);
	tmp = (char *)ft_calloc(i + 3, sizeof(char));
	tmpbuff = (char *)ft_calloc(size - i + 2, sizeof(char));
	tmp = ft_strlcpy2(tmp, buff, ft_search_nl(buff) + 1);
	tmpbuff = ft_strlcpy2(tmpbuff, buff + ft_search_nl(buff) + 1, -1);
	buff = ft_strlcpy2(buff, tmpbuff, -1);
	tmp[ft_search_nl(tmp) + 1] = '\0';
	free(tmpbuff);
	return (tmp);
}

void	*ft_calloc2(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	if (nmemb > 9223372036854775807 || size > 9223372036854775807)
		return (NULL);
	if (nmemb <= 0 || size <= 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_search_nl(char *s1)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] != '\0' && s1[i] != 1)
	{
		if (s1[i] == '\n')
			return (i);
		i++;
	}
	if (s1[i] == 1)
		return (-2);
	return (-1);
}

char	*ft_strlcpy2(char *dst, const char *src, int max)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (max == -1)
		max = 2147483647;
	while (src[len] != '\0')
		len++;
	while (src[i] != '\0' && i <= max)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
