/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:56:08 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/19 13:57:05 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

int	ft_sleep(t_ptr *philo, int id, int state)
{
	long int		tmp;

	sem_wait(philo->sem_id);
	tmp = ft_get_time(philo);
	if (ft_are_you_dead(philo) == 0)
		printf("%ld		%d	is sleeping\n", tmp, id);
	sem_post(philo->sem_id);
	if (ft_are_you_dead(philo) == 0)
		usleep(philo->time_sleep * 1000);
	state++;
	return (state);
}

int	ft_think(t_ptr *philo, int id, int state)
{
	long int		tmp;

	sem_wait(philo->sem_id);
	tmp = ft_get_time(philo);
	if (ft_are_you_dead(philo) == 0)
		printf("%ld		%d	is thinking\n", tmp, id);
	sem_post(philo->sem_id);
	state = 0;
	return (state);
}

int	ft_eating(t_ptr *philo, int id, int state)
{
	long int	tmp;

	usleep(500);
	ft_mutiple_lock(0, philo->sem_fork, philo->sem_id);
	tmp = ft_get_time(philo);
	if (ft_are_you_dead(philo) == 0)
		printf("%ld		%d	has taken a fork\n", tmp, id);
	sem_post(philo->sem_id);
	sem_wait(philo->sem_fork);
	ft_eating_two(philo, id, tmp);
	state = 1;
	return (state);
}

void	ft_eating_two(t_ptr *philo, int id, long int tmp)
{
	tmp = ft_get_time(philo);
	if (ft_are_you_dead(philo) == 0)
	{
		sem_wait(philo->sem_id);
		if (ft_are_you_dead(philo) == 0)
		{
			sem_wait(philo->sem_dead);
			sem_wait(philo->sem_print);
			printf("%ld		%d	has taken a fork\n", tmp, id);
			printf("%ld		%d	is eating\n", tmp, id);
			sem_post(philo->sem_print);
			sem_post(philo->sem_dead);
		}
		sem_post(philo->sem_id);
	}
	ft_update_last_eat(philo);
	if (ft_are_you_dead(philo) == 0)
		usleep(philo->time_eat * 1000);
	sem_post(philo->sem_fork);
	sem_post(philo->sem_fork);
}

void	ft_update_last_eat(t_ptr *philo)
{
	sem_wait(philo->sem_last_eat);
	philo->last_eat = ft_get_time(philo);
	sem_post(philo->sem_last_eat);
}
