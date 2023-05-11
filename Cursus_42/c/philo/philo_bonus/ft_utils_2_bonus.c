/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:13:26 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/19 14:08:19 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

void	ft_init_struc_2(t_ptr *philo, char **argv)
{
	sem_unlink("id");
	sem_unlink("dead");
	sem_unlink("print");
	sem_unlink("big dead");
	sem_unlink("succes");
	sem_unlink("fork");
	sem_unlink("last_eat");
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

void	ft_print(t_ptr *philo, int id)
{
	sem_wait(philo->sem_print);
	sem_wait(philo->sem_dead);
	sem_wait(philo->sem_id);
	if (philo->dead == 0)
		printf("%ld		%d	died\n", ft_get_time(philo), id);
			philo->dead = 1;
	sem_post(philo->sem_big_dead);
	sem_post(philo->sem_dead);
	sem_post(philo->sem_id);
}

void	ft_mutiple_lock(int i, sem_t *m1, sem_t *m2)
{
	if (i == 0)
	{
		if (m1 != NULL)
			sem_wait(m1);
		if (m2 != NULL)
			sem_wait(m2);
	}
	if (i == 1)
	{
		if (m1 != NULL)
			sem_post(m1);
		if (m2 != NULL)
			sem_post(m2);
	}
	if (i == 2)
	{
		if (m1 != NULL)
			sem_close(m1);
		if (m2 != NULL)
			sem_close(m2);
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

void	ft_main_part_2(t_ptr *philo, int id)
{
	pthread_t		ft_check_succes;

	pthread_create(&ft_check_succes, NULL, &ft_wait_death, philo);
	ft_check_big_succes(philo);
	if (ft_are_you_dead(philo) == 0)
	{
		sem_wait(philo->sem_dead);
		philo->succes = 1;
		printf("%ld		All philosophers agree the answer is 42\n",
			ft_get_time(philo));
		sem_post(philo->sem_dead);
	}
	pthread_join(ft_check_succes, NULL);
	ft_mutiple_lock(2, philo->sem_fork, philo->sem_last_eat);
	ft_mutiple_lock(2, philo->sem_id, philo->sem_dead);
	ft_mutiple_lock(2, philo->sem_big_succes, philo->sem_big_dead);
	sem_close(philo->sem_print);
	free(philo->pid);
	(void)id;
}
