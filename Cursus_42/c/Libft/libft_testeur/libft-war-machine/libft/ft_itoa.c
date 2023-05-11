/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:55 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/13 18:17:31 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countint(int n);
char	*ft_check_annoying_type(int n);
char	*ft_modulo(char *ptr, int tmp, int n);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		tmp;
	int		neg;

	neg = 1;
	if (n < 0)
	{
		n = n * -1;
		neg = -1;
	}
	if (n == 0 || n == -2147483648 || n > 2147483647 || n < 0)
		return (ft_check_annoying_type(n));
	tmp = ft_countint(n);
	ptr = (char *)calloc((tmp), sizeof(char));
	if (neg > 0)
		tmp--;
	ptr[tmp] = '\0';
	ft_modulo(ptr, tmp, n);
	if (neg < 0)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_modulo(char *ptr, int tmp, int n)
{
	while (n > 0)
	{
		ptr[tmp] = n % 10 + '0';
		n = n / 10;
		tmp--;
	}
	return (ptr);
}

int	ft_countint(int n)
{
	int	c;

	c = 0;
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_check_annoying_type(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}
