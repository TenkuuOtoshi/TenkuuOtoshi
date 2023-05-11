/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:38:23 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/09 11:16:20 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*str;

	if (fd == -1)
		return (NULL);
	if (!buff)
		buff = (char *)ft_calloc2(1 + 1, sizeof(char));
	if (ft_search_nl(buff) != -1)
		return (ft_check_buff(buff));
	str = (char *)ft_calloc2(1 + 1, sizeof(char));
	if (!buff || !str)
		return (NULL);
	while (ft_search_nl(str) == -1)
		str = ft_fuse_and_cut(fd, buff, str);
	if (ft_search_nl(str) == -2)
		return (ft_replace(str));
	if (str == NULL )
	{
		buff = ft_free_and_null(buff, 0);
		str = ft_free_and_null(str, buff);
		return (NULL);
	}
	return (str);
}

char	*ft_fuse_and_cut(int fd, char *buff, char *str)
{
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	if (buff == NULL)
		return (ft_free_and_null(str, 0));
	tmp = (char *)ft_calloc2(1 + 1, sizeof(char));
	ret = read(fd, tmp, 1);
	if (ret == -1)
		return (ft_free_and_null(tmp, str));
	tmp = ft_strjoin2(buff, tmp, 1);
	str = ft_strjoin2(str, tmp, 0);
	buff[0] = '\0';
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (ft_copy_and_return(str, buff, i));
		i++;
	}
	if (str[0] == '\0' && i == 0 && ret == 0)
		return (ft_free_and_null(str, 0));
	if (str[i] == '\0' && ret == 0)
		str[i] = 1;
	return (str);
}

char	*ft_replace(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 1)
		i++;
	if (str[i] == 1)
		str[i] = '\0';
	return (str);
}

char	*ft_free_and_null(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	s1 = NULL;
	if (s2 != NULL)
		free(s2);
	s2 = NULL;
	return (0);
}

char	*ft_copy_and_return(char *str, char *buff, int i)
{
	ft_strlcpy2(buff, str + i + 1, -1);
	str[i + 1] = '\0';
	return (str);
}
