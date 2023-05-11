/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpip.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:49:47 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/26 13:54:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPIP_H
# define LIBPIP_H

# include <libft.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

void	ft_second_command(char **argv, int fd[2], int fdd[2], char **env);
void	ft_first_command(char **argv, int fd[2], int fdd[2], char **env);
char	*ft_check_access(char **env, char *path, char *str);
int		ft_big_while_2(char *s, char **str, int i, int *y);
int		ft_big_while(char *s, char **str, int i, int y);
int		ft_check_error(char **argv, int fdd[2]);
void	ft_free_double(char **str, char *str2);
void	ft_close(int a, int b, int c, int d);
void	ft_put_arg(char **mini, char *arg);
void	ft_close_fd(int fd[2], int fdd[2]);
char	*ft_access(char *str, char **env);
void	ft_init_fd(int *fdd, char **argv);
int		ft_init_fork(int id);
int		ft_exit(int i);

#endif
