/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:20:56 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/26 13:23:40 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpip_bonus.h"

char	*ft_last_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i + 1] != NULL)
		i++;
	return (argv[i]);
}

int	ft_big_while_fd(int fd[2], int fd2[2], char **argv, char **env)
{
	int		id;
	int		i;

	i = 3;
	while (argv[i + 2] != NULL)
	{
		id = ft_init_fork(id);
		if (i % 2 == 1)
		{
			if (id == 0 && i % 2 == 1)
				ft_middle_command(argv[i], fd, fd2, env);
			ft_close(fd[0], fd[1], -1, -1);
			ft_init_pipe(fd);
		}
		if (i % 2 == 0)
		{
			if (id == 0 && i % 2 == 0)
				ft_middle_command(argv[i], fd2, fd, env);
			ft_close(fd2[0], fd2[1], -1, -1);
			ft_init_pipe(fd2);
		}
		waitpid(id, NULL, 0);
		i++;
	}
	return (i);
}

int	ft_exit(int i)
{
	if (i == 1)
		perror("fork");
	if (i == 2)
		perror("pipe");
	if (i == 3)
		perror("open");
	if (i != 3)
		exit(EXIT_FAILURE);
	return (1);
}

int	ft_init_fork(int id)
{
	id = 0;
	id = fork();
	if (id < 0)
		ft_exit(1);
	return (id);
}

void	ft_init_pipe(int fd[2])
{
	if (pipe(fd) == -1)
		ft_exit(2);
}
