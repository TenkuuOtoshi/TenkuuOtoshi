/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:34:20 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/26 17:02:20 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpip.h"

void	ft_first_command(char **argv, int fd[2], int fdd[2], char **env)
{
	char	**str;
	char	*path;

	str = ft_split(argv[2], ' ');
	path = ft_access(str[0], env);
	if (path != NULL && fdd[1] >= 0 && ft_strlen(argv[2]) > 0)
	{
		dup2(fdd[1], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_close(fdd[0], fdd[1], fd[0], fd[1]);
		execve(path, str, env);
	}
	if (path == NULL)
		ft_printf("pipex: command not found: %s\n", str[0]);
	ft_free_double(str, path);
	ft_close(fdd[0], fdd[1], fd[0], fd[1]);
	ft_close(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, -1);
	exit(127);
}

void	ft_second_command(char **argv, int fd[2], int fdd[2], char **env)
{
	char	**str;
	char	*path;

	str = ft_split(argv[3], ' ');
	path = ft_access(str[0], env);
	if (path != NULL && ft_strlen(argv[3]) > 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fdd[0], STDOUT_FILENO);
		ft_close(fdd[0], fdd[1], fd[0], fd[1]);
		execve(path, str, env);
	}
	if (path == NULL)
		ft_printf("pipex: command not found: %s\n", str[0]);
	ft_free_double(str, path);
	ft_close(fdd[0], fdd[1], fd[0], fd[1]);
	ft_close(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, -1);
	exit(127);
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

void	ft_init_fd(int *fdd, char **argv)
{
	fdd[1] = open(argv[1], O_RDONLY, 0666);
	fdd[0] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fdd[0] < 0 || fdd[1] < 0)
		ft_exit(3);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		fdd[2];
	int		id;

	if (!argv[1] || !argv[3] || argv[5])
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	id = 0;
	if (pipe(fd) == -1)
		ft_exit(2);
	ft_init_fd(fdd, argv);
	id = ft_init_fork(id);
	if (id == 0)
		ft_first_command(argv, fd, fdd, env);
	close(fdd[1]);
	id = ft_init_fork(id);
	if (id == 0)
		ft_second_command(argv, fd, fdd, env);
	wait(NULL);
	ft_close_fd(fd, fdd);
	ft_close(5, 6, 6, 6);
	return (0);
	(void)argc;
}
