/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:13:24 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/26 13:40:30 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpip_bonus.h"

int	ft_here_doc(char **argv)
{
	int		fd;
	char	*s;
	char	*str;

	fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		ft_exit(3);
	dup2(fd, 1);
	s = ft_strjoin(argv[2], "\n", 0);
	str = NULL;
	while (ft_cmp(s, str) != 0)
	{
		free(str);
		str = get_next_line(0);
		if (str != NULL && ft_strncmp(str, s, ft_strlen(argv[2]) - 1) != 0)
			ft_putstr(str);
	}
	ft_free_and_null(str, s);
	close(fd);
	fd = open(argv[1], O_RDONLY, 0666);
	if (fd < 0)
		ft_exit(3);
	argv[2] = "cat";
	return (fd);
}

int	ft_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_check_access(char **env, char *path, char *str)
{
	if (access(path, R_OK) == 0)
	{
		ft_free_double(env, str);
		return (path);
	}
	return (NULL);
}
