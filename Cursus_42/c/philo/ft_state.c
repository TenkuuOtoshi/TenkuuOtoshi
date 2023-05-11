/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:56:08 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/19 18:48:05 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

int	ft_sleep(t_ptr *philo, int id, int state)
{
	long int		tmp;

	pthread_mutex_lock(&philo->mutex_id);
	tmp = ft_get_time(philo);
	if (ft_are_you_dead(philo) == 0)
		printf("%ld		%d	is sleeping\n", tmp, id);
	pthread_mutex_unlock(&philo->mutex_id);
	if (ft_are_you_dead(philo) == 0)
		usleep(philo->time_sleep * 1000 - 150);
	state++;
	return (state);
}

int	ft_think(t_ptr *philo, int id, int state)
{
	long int		tmp;

	pthread_mutex_lock(&philo->mutex_id);
	tmp = ft_get_time(philo);
	if (ft_are_you_dead(philo) == 0)
		printf("%ld		%d	is thinking\n", tmp, id);
	pthread_mutex_unlock(&philo->mutex_id);
	state = 0;
	return (state);
}

int	ft_eating(t_ptr *philo, int id, int state)
{
	long int	tmp;

	ft_mutiple_lock(0, &philo->mutex_fork[id - 1], &philo->mutex_id);
	tmp = ft_get_time(philo);
	if (ft_are_you_dead(philo) == 0)
		printf("%ld		%d	has taken a fork\n", tmp, id);
	pthread_mutex_unlock(&philo->mutex_id);
	if (philo->nb_of_fork != 1)
	{
		if (id == philo->nb_of_fork)
			pthread_mutex_lock(&philo->mutex_fork[0]);
		else
			pthread_mutex_lock(&philo->mutex_fork[id]);
	}
	else
	{
		usleep(philo->time_die * 1000);
	}
	tmp = ft_get_time(philo);
	ft_eating_two(philo, id, tmp);
	state = 1;
	return (state);
}

void	ft_eating_two(t_ptr *philo, int id, long int tmp)
{
	if (ft_are_you_dead(philo) == 0 && philo->nb_of_fork != 1)
	{
		pthread_mutex_lock(&philo->mutex_id);
		if (ft_are_you_dead(philo) == 0)
		{
			printf("%ld		%d	has taken a fork\n", tmp, id);
			printf("%ld		%d	is eating\n", tmp, id);
		}
		ft_update_last_eat(id, philo);
		pthread_mutex_unlock(&philo->mutex_id);
	}
	if (ft_are_you_dead(philo) == 0)
	{
		usleep(philo->time_eat * 1000 - 150);
	}
	pthread_mutex_unlock(&philo->mutex_fork[id - 1]);
	pthread_mutex_lock(&philo->mutex_id);
	if (philo->nb_of_fork != 1)
	{
		if (id == philo->nb_of_fork)
			pthread_mutex_unlock(&philo->mutex_fork[0]);
		else
			pthread_mutex_unlock(&philo->mutex_fork[id]);
	}
	pthread_mutex_unlock(&philo->mutex_id);
}

void	ft_update_last_eat(int id, t_ptr *philo)
{
	if (ft_are_you_dead(philo) == 0)
	{
		pthread_mutex_lock(&philo->mutex_last_eat);
		if (ft_are_you_dead(philo) == 0)
			philo->last_eat[id] = ft_get_time(philo);
		pthread_mutex_unlock(&philo->mutex_last_eat);
	}
}
