/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:39:10 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/02 14:28:07 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> 
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_putstr(char *str);
int		ft_putchar(char c);
char	*ft_strjoin(char *s1, char *s2, int y);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_fuse_and_cut(int fd, char *buff, char *str);
int		ft_search_nl(char *s1);
char	*ft_strlcpy(char *dst, const char *src, int max);
char	*ft_replace(char *str);
char	*ft_free_and_null(char *s1, char *s2);
char	*ft_copy_and_return(char *str, char *buff, int i);
char	*ft_check_buff(char *buff);

#endif