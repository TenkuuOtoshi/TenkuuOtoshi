/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:34:20 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/24 10:03:56 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpip_bonus.h"

void	ft_first_command(char *argv, int fd[2], int fdd[2], char **env)
{
	char	**str;
	char	*path;		

	str = ft_split(argv, ' ');
	path = ft_access(str[0], env);
	if (path != NULL && fdd[1] >= 0 && ft_strlen(argv) > 0)
	{
		dup2(fdd[1], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_close(-1, fdd[1], fd[0], fd[1]);
		execve(path, str, env);
	}
	if (path == NULL)
		ft_printf("pipex: command not found: %s\n", str[0]);
	ft_free_double(str, path, NULL);
	ft_close(fdd[0], fdd[1], fd[0], fd[1]);
	ft_close(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, -1);
	exit(127);
}

void	ft_middle_command(char *argv, int fd[2], int fd2[2], char **env)
{
	char	**str;
	char	*path;

	str = ft_split(argv, ' ');
	path = ft_access(str[0], env);
	if (path != NULL && ft_strlen(argv) > 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd2[1], STDOUT_FILENO);
		ft_close(fd2[0], fd2[1], fd[0], fd[1]);
		execve(path, str, env);
	}
	if (path == NULL)
		ft_printf("pipex: command not found: %s\n", str[0]);
	ft_free_double(str, path, NULL);
	ft_close(fd2[0], fd2[1], fd[0], fd[1]);
	ft_close(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, -1);
	exit(127);
}

void	ft_last_command(char *argv, int fd[2], int fdd[2], char **env)
{
	char	**str;
	char	*path;

	str = ft_split(argv, ' ');
	path = ft_access(str[0], env);
	if (path != NULL && ft_strlen(argv) > 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fdd[0], STDOUT_FILENO);
		ft_close(fdd[0], fdd[1], fd[0], fd[1]);
		execve(path, str, env);
	}
	if (path == NULL)
		ft_printf("pipex: command not found: %s\n", str[0]);
	ft_free_double(str, path, NULL);
	ft_close(fdd[0], fdd[1], fd[0], fd[1]);
	ft_close(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, -1);
	exit(127);
}

void	ft_while_arg(char **argv, int fd[2], int fdd[2], char **env)
{
	int		i;
	int		fd2[2];
	int		id;

	id = ft_init_fork(0);
	if (id == 0)
		ft_first_command(argv[2], fd, fdd, env);
	close(fdd[1]);
	ft_init_pipe(fd2);
	i = ft_big_while_fd(fd, fd2, argv, env);
	id = ft_init_fork(id);
	fdd[0] = open(ft_last_arg(argv), O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fdd[0] < 0)
		ft_exit(3);
	if (id == 0 && i % 2 == 0)
	{
		ft_close(fd[0], fd[1], -1, -1);
		ft_last_command(argv[i], fd2, fdd, env);
	}
	if (id == 0 && i % 2 == 1)
	{
		ft_close(fd2[0], fd2[1], -1, -1);
		ft_last_command(argv[i], fd, fdd, env);
	}
	ft_close(fd2[0], fd2[1], fd[0], fd[1]);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		fdd[2];

	if (!argv[4] || !argv[3] || !argv[2] || !argv[1])
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (pipe(fd) == -1)
		ft_exit(2);
	fdd[0] = -1;
	fdd[1] = open(argv[1], O_RDONLY, 0666);
	if (fdd[1] < 0)
		ft_exit(3);
	ft_while_arg(argv, fd, fdd, env);
	wait(NULL);
	ft_close(fdd[1], fdd[0], fd[0], fd[1]);
	return (0);
	(void)argc;
}
