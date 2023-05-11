/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:50:57 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/22 18:14:16 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr2_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n != 0)
		ft_putnbr2_fd(n, fd);
	else
		ft_putchar_fd(n + '0', fd);
}

static void	ft_putnbr2_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		write(fd, "147483648", 9);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}		
	if (n > 0)
	{
		ft_putnbr2_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
