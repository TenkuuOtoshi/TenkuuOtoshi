/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:07:03 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/27 13:43:40 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpip_bonus.h"

void	ft_close_fd(int fd[2], int fdd[2])
{
	if (fd != NULL)
	{
		if (fd[0] >= 0)
			close(fd[0]);
		if (fd[1] >= 0)
			close(fd[1]);
	}
	if (fdd != NULL)
	{
		if (fdd[0] >= 0)
			close(fdd[0]);
		if (fdd[1] >= 0)
			close(fdd[1]);
	}
}

char	**ft_make_mini_arg(char *argv)
{
	char	**str;

	str = (char **)ft_calloc(1 + 1, sizeof(char *));
	str[0] = argv;
	str[1] = NULL;
	return (str);
}

char	*ft_access(char *str, char **env)
{
	char	*path;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (access(str, R_OK) == 0)
		return (str);
	str = ft_strjoin("/", str, 0);
	while (ft_strncmp("PATH", env[i], 3) != 0)
		i++;
	env[i] = env[i] + 5;
	env = ft_split(env[i], ':');
	i = 0;
	while (env[i])
	{
		path = ft_strjoin(env[i], str, 0);
		i++;
		path = ft_check_access(env, path, str);
		if (path != NULL)
			return (path);
		free(path);
	}
	ft_free_double(env, str);
	return (NULL);
}

void	ft_free_double(char **str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	free(str2);
}

void	ft_close(int a, int b, int c, int d)
{
	if (a >= 0)
		close(a);
	if (b >= 0)
		close(b);
	if (c >= 0)
		close(c);
	if (d >= 0)
		close(d);
}
