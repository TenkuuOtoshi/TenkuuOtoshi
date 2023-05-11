/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:00:11 by tlarraze          #+#    #+#             */
/*   Updated: 2022/05/05 10:42:00 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_bigprint(char c, char cc, va_list args, int count);
int		ft_putchar(char cha, int count);
int		ft_printf(const char *s, ...);
int		ft_verif(char c, char cc);
int		ft_putnbr2(int nb, int count);
int		ft_putnbr(int nb, int count);
int		ft_putunbr2(unsigned int nb, int count);
int		ft_putunbr(unsigned int nb, int count);
int		ft_putstr(char *str, int count);
int		ft_lownumber(unsigned int n, int count);
int		ft_puthexmaj(unsigned int n, int count);
int		ft_puthexmaj2(unsigned int n, int count);
int		ft_puthexmin(unsigned int nb, int count);
int		ft_puthexmin2(unsigned int nb, int count);
int		ft_voidp(long unsigned int p, int count);
int		ft_puthexminp(unsigned long int nb, int count);
int		ft_puthexminp2(unsigned long int nb, int count);
#endif
