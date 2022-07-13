/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:55 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/22 18:17:53 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countint(int n);
static char		*ft_check_annoying_type(int n);
static char		*ft_modulo(char *ptr, int tmp, int n, int neg);

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
	if (neg == -1)
		ptr = (char *)ft_calloc((tmp) + 2, sizeof(char));
	else
		ptr = (char *)ft_calloc((tmp) + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (neg != -1)
		tmp--;
	ft_modulo(ptr, tmp, n, neg);
	ptr[ft_strlen(ptr)] = '\0';
	return (ptr);
}

static char	*ft_modulo(char *ptr, int tmp, int n, int neg)
{
	while (n > 0)
	{
		ptr[tmp] = n % 10 + '0';
		n = n / 10;
		tmp--;
	}
	if (neg < 0)
		ptr[0] = '-';
	return (ptr);
}

static int	ft_countint(int n)
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

static char	*ft_check_annoying_type(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}
