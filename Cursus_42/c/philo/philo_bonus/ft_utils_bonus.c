/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:31:46 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/16 13:32:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

//check the number of argument and verify if they only contain number
//if check is ok return 0 else return 1
int	ft_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 4 || argc > 5)
	{
		printf("Error, Number of arg can only be 4 or 5\n");
		return (1);
	}
	while (argv[j])
	{
		while (argv[j][i])
		{	
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				printf("Error, only numbers are allowed in argument\n");
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

//Take the number in the string 'nptr' and return the value in the int
long int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;
	int		tmp;

	i = 0;
	result = 0;
	sign = 1;
	tmp = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
		tmp++;
	}
	if (tmp > 1)
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	result = result * sign;
	return (result);
}

long int	ft_get_time(t_ptr *philo)
{
	struct timeval	tv;
	int				time;

	gettimeofday(&tv, NULL);
	time = tv.tv_usec / 1000 + (tv.tv_sec * 1000) - philo->start;
	return (time);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb > 9223372036854775807 || size > 9223372036854775807)
		return (NULL);
	if (nmemb <= 0 || size <= 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	if (n == 0)
		return (0);
	while (i < n)
	{
		ps[i] = 0;
		i++;
	}
	return (0);
}
