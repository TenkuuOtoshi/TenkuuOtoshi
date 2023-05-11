/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:18:59 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/19 15:03:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

int	ft_init_time_and_thread(t_ptr *philo)
{
	pthread_t	checker;
	int			id;

	sem_wait(philo->sem_id);
	id = philo->id;
	ft_update_last_eat(philo);
	philo->id = id;
	sem_post(philo->sem_id);
	pthread_create(&checker, NULL, &ft_checker, philo);
	pthread_detach(checker);
	return (id);
}

void	*ft_wait_death(void	*arg)
{
	t_ptr	*philo;
	int		state;

	philo = (t_ptr *)arg;
	state = 0;
	sem_wait(philo->sem_big_dead);
	sem_wait(philo->sem_dead);
	while (state < ft_atoi(philo->argv[1]))
	{
		kill(philo->pid[state], SIGKILL);
		state++;
	}
	sem_post(philo->sem_dead);
	if (ft_check_succes(philo) == 0)
	{
		sem_wait(philo->sem_dead);
		philo->dead = 1;
		sem_post(philo->sem_dead);
		sem_post(philo->sem_big_succes);
		sem_post(philo->sem_big_succes);
	}
	return (0);
}

int	ft_check_overflow(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > (long int)2147483647)
		{
			printf("Error\n");
			return (1);
		}
		if (argv[5] && ft_atoi(argv[5]) == 0)
		{
			printf("Number of times each philosopher must eat can't be 0\n");
			return (1);
		}
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
	{
		printf("Number of philosopher can't be less than 1");
		return (1);
	}
	return (0);
}

int	ft_check_sem(t_ptr *philo)
{
	if (philo->sem_big_dead == SEM_FAILED)
		return (1);
	if (philo->sem_big_succes == SEM_FAILED)
		return (1);
	if (philo->sem_print == SEM_FAILED)
		return (1);
	if (philo->sem_id == SEM_FAILED)
		return (1);
	if (philo->sem_fork == SEM_FAILED)
		return (1);
	if (philo->sem_dead == SEM_FAILED)
		return (1);
	if (philo->sem_last_eat == SEM_FAILED)
		return (1);
	return (0);
}
