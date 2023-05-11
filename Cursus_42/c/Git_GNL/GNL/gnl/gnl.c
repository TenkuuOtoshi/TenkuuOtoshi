/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:58:57 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/21 17:36:07 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clear_malloc(char *str, int size);
char	*ft_strjoin(char *s1, char *s2, int free);
int		ft_search_nl(char *str);
void	ft_free_null(char *str);
int		ft_strlen(char *str);

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = s[i];
	free(s);
	return (str);
}

void	ft_free_null(char *str)
{
	free(str);
	str = NULL;
}

int		ft_search_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str || str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int f)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(i + 1 * sizeof(char));
	str[i] = '\0';
	ft_clear_malloc(str, i);
	i = 0;
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;	
	}
	if (f == 1)
	{
		free(s1);
		s1 = NULL;
	}
	if (f == 2)
	{
		free(s2);
		s2 = NULL;
	}
	if (f == 3)
	{
		free(s1);
		free(s2);
		s1 = NULL;
		s2 = NULL;
	}
	return (str);
}

void	ft_clear_malloc(char *str, int size)
{
	int	i;

	i = 0;
	while (i != size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_calloc()
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	str[BUFFER_SIZE] = '\0';
	while (i != BUFFER_SIZE)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char *ft_return_instant_buf(char *buf)
{
	char	*str;
	int		i;

	i = 0;
	if (ft_search_nl(buf) == -1)
		return (buf);
	str = (char *)malloc(ft_search_nl(buf) + 2 * sizeof(char));
	str[ft_search_nl(buf) + 1] = '\0';
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = buf[i];
	return (str);
}

char	*get_next_line(int fd)
{
	static char *buf;
	char		*str;
	char		*tmp;
	int			ret;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf && ft_search_nl(buf) != -1)
	{
		str = ft_return_instant_buf(buf);
		tmp = ft_strjoin(buf + ft_search_nl(buf) + 1, "", 0);
		free(buf);
		buf = tmp;
		return (str);
	}
	if (!buf)
		buf = ft_calloc();
	str = ft_calloc();
	ret = read(fd, str, BUFFER_SIZE);
	if (ret <= 0)
	{
		if (buf && ft_strlen(str) == 0 && ft_strlen(buf) > 0)
		{
			free(str);
			str = ft_strdup(buf);
			buf = NULL;
			return (str);
		}
		free(buf);
		buf = NULL;
		free(str);
		return (NULL);
	}

	str[ret] = '\0';
	if (str[0] == '\0')
	{
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		if (str)
			ft_free_null(str);
		return (NULL);
	}
	while (ft_search_nl(str) == -1 && ret != 0)
	{
		buf = ft_strjoin(buf, str, 3);
		str = ft_calloc();
		ret = read(fd, str, BUFFER_SIZE);
	}
	//printf("t%st", buf);
	buf = ft_strjoin(buf, str, 3);
	str = ft_return_instant_buf(buf);
	tmp = ft_strjoin(buf + ft_search_nl(buf) + 1, "", 0);
	if (ret != 0)
	{
		free(buf);
		buf = tmp;
	}
	buf = tmp;
	return (str);
}

int	main()
{
	int	fd;
	char *str;
	int	i;

	i = 0;
	fd = open("t", O_RDWR, 6666);
	str = get_next_line(fd);
	while (i != 6)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
}