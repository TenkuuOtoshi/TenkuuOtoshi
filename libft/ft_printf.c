/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:58:10 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/09 11:32:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		result;

	count = 0;
	result = 0;
	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (ft_verif(s[i], s[i + 1]) != 0)
		{
			count = ft_bigprint(s[i], s[i + 1], args, count);
			i++;
		}
		else
			count = ft_putchar2(s[i], count);
		result = result + count;
		count = 0;
		i++;
	}
	return (result);
}

int	ft_verif(char c, char cc)
{
	if (c == '%')
	{
		if (cc == 'c')
			return (1);
		if (cc == 's')
			return (2);
		if (cc == 'p')
			return (3);
		if (cc == 'd')
			return (4);
		if (cc == 'i')
			return (5);
		if (cc == 'u')
			return (6);
		if (cc == 'x')
			return (7);
		if (cc == 'X')
			return (8);
		if (cc == '%')
			return (9);
	}
	return (0);
}

int	ft_bigprint(char c, char cc, va_list args, int count)
{
	if (c == '%')
	{
		if (cc == 'c')
			count = ft_putchar2(va_arg(args, int), count);
		if (cc == 's')
			count = ft_putstr2(va_arg(args, char *), count);
		if (cc == 'p')
			count = ft_voidp(va_arg(args, long unsigned int), count);
		if (cc == 'd')
			count = ft_putnbr2(va_arg(args, int), count);
		if (cc == 'i')
			count = ft_putnbr2(va_arg(args, int), count);
		if (cc == 'u')
			count = ft_putunbr2(va_arg(args, unsigned int), count);
		if (cc == 'x')
			count = ft_puthexmin(va_arg(args, int), count);
		if (cc == 'X')
			count = ft_puthexmaj(va_arg(args, int), count);
		if (cc == '%')
			count = ft_putchar2('%', count);
	}
	return (count);
}
