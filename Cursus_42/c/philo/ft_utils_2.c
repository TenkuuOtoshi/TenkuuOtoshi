/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:13:26 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/07 18:15:45 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

void	ft_init_struc_2(t_ptr *philo, char **argv)
{
	philo->id = 1;
	philo->succes = 0;
	gettimeofday(&philo->tv, NULL);
	philo->nb_of_philo = ft_atoi(argv[1]);
	philo->nb_of_fork = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->argv = argv;
	philo->dead = 0;
	if (!argv[5])
		philo->nb_must_eat = -1;
	else
		philo->nb_must_eat = ft_atoi(argv[5]);
}

void	ft_print(t_ptr *philo, int i)
{
	pthread_mutex_lock(&philo->mutex_id);
	printf("%ld		%d	died\n", ft_get_time(philo), i);
	pthread_mutex_unlock(&philo->mutex_id);
}

void	ft_mutiple_lock(int i, pthread_mutex_t *m1, pthread_mutex_t *m2)
{
	if (i == 0)
	{
		if (m1 != NULL)
			pthread_mutex_lock(m1);
		if (m2 != NULL)
			pthread_mutex_lock(m2);
	}
	if (i == 1)
	{
		if (m1 != NULL)
			pthread_mutex_unlock(m1);
		if (m2 != NULL)
			pthread_mutex_unlock(m2);
	}
	if (i == 2)
	{
		if (m1 != NULL)
			pthread_mutex_destroy(m1);
		if (m2 != NULL)
			pthread_mutex_destroy(m2);
	}
}

void	ft_choose_state(t_ptr *philo, int id, int state, int eat)
{
	while (ft_are_you_dead(philo) == 0 && eat != philo->nb_must_eat)
	{
		if (state == 1)
			state = ft_sleep(philo, id, state);
		if (state == 2)
			state = ft_think(philo, id, state);
		if (state == 0)
		{
			state = ft_eating(philo, id, state);
			eat++;
			usleep(100);
		}
	}
}

void	ft_main_part_2(t_ptr *philo, pthread_t *th, pthread_t satan, int id)
{
	id = 1;
	while (id < ft_atoi(philo->argv[1]) + 1)
	{
		pthread_join(th[id], NULL);
		id++;
	}
	pthread_mutex_lock(&philo->mutex_dead);
	usleep(10000);
	if (philo->dead == 0)
	{
		pthread_mutex_unlock(&philo->mutex_dead);
		philo->succes = 1;
		printf("%ld		All philosophers agree the answer is 42\n",
			ft_get_time(philo));
	}
	if (philo->succes != 1)
		pthread_mutex_unlock(&philo->mutex_dead);
	pthread_join(satan, NULL);
	ft_mutiple_lock(2, &philo->mutex_id, &philo->mutex_dead);
	free(th);
	free(philo->last_eat);
	free(philo->mutex_fork);
}
