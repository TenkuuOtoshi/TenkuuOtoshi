/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpip_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:49:47 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/18 15:17:15 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPIP_BONUS_H
# define LIBPIP_BONUS_H

# include <libft.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

void	ft_middle_command(char *argv, int fd[2], int fd2[2], char **env);
void	ft_first_command(char *argv, int fd[2], int fdd[2], char **env);
int		ft_big_while_fd(int fd[2], int fd2[2], char **argv, char **env);
void	ft_last_command(char *argv, int fd[2], int fdd[2], char **env);
void	ft_while_arg(char **argv, int fd[2], int fdd[2], char **env);
int		ft_big_while_2(char *s, char **str, int i, int *y);
char	*ft_free_double(char **str, char *str2, char *s);
int		ft_big_while(char *s, char **str, int i, int y);
int		ft_check_error(char **argv, int fdd[2]);
void	ft_close(int a, int b, int c, int d);
void	ft_put_arg(char **mini, char *arg);
void	ft_close_fd(int fd[2], int fdd[2]);
char	*ft_access(char *str, char **env);
char	*ft_last_arg(char **argv);
void	ft_init_pipe(int fd[2]);
int		ft_init_fork(int id);
int		ft_exit(int i);

#endif
