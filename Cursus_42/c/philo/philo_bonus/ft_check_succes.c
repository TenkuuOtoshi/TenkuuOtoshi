/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_succes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:55:42 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/19 14:16:17 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

int	ft_check_succes(t_ptr *philo)
{
	sem_wait(philo->sem_dead);
	if (philo->succes == 1)
	{
		sem_post(philo->sem_dead);
		return (1);
	}
	sem_post(philo->sem_dead);
	return (0);
}

void	*ft_check_big_succes(void *arg)
{
	t_ptr			*philo;
	int				i;

	philo = (t_ptr *)arg;
	i = 0;
	while (i < ft_atoi(philo->argv[1]) && ft_are_you_dead(philo) == 0)
	{
		sem_wait(philo->sem_big_succes);
		i++;
		if (ft_are_you_dead(philo) != 0)
			return (0);
	}
	sem_wait(philo->sem_dead);
	if (philo->dead == 0)
		philo->succes = 1;
	sem_post(philo->sem_big_dead);
	sem_post(philo->sem_dead);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (ptr == NULL)
		return (0);
	ft_strcpy(ptr, s);
	return (ptr);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	c;

	if (s == NULL)
		return (0);
	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}
