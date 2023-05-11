/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:25:03 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/15 18:00:23 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

void	*ft_satan(void	*arg)
{
	t_ptr			*philo;
	int				i;
	long int		leat;

	i = 1;
	philo = (t_ptr *)arg;
	while (ft_are_you_dead(philo) == 0 && philo->succes == 0)
	{
		pthread_mutex_lock(&philo->mutex_last_eat);
		leat = philo->last_eat[i];
		pthread_mutex_unlock(&philo->mutex_last_eat);
		if (ft_get_time(philo) >= leat + philo->time_die && leat != -1)
		{
			if (ft_are_you_dead(philo) == 0)
				ft_print(philo, i);
			pthread_mutex_lock(&philo->mutex_dead);
			philo->dead = 1;
			pthread_mutex_unlock(&philo->mutex_dead);
		}
		i++;
		if (i >= philo->nb_of_philo)
			i = 1;
	}
	return (0);
}

void	ft_init_struc(t_ptr *philo, char **argv)
{
	int				i;
	int				tmp;
	pthread_mutex_t	mutex_id;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_dead;

	pthread_mutex_init(&mutex_id, NULL);
	pthread_mutex_init(&mutex_dead, NULL);
	pthread_mutex_init(&philo->mutex_last_eat, NULL);
	i = 0;
	tmp = ft_atoi(argv[1]);
	mutex_fork = (pthread_mutex_t *)ft_calloc(tmp, sizeof(pthread_mutex_t));
	philo->last_eat = (long int *)ft_calloc(tmp + 2, sizeof(long int));
	if (mutex_fork == NULL)
		exit(0);
	while (i < tmp)
	{
		pthread_mutex_init(&mutex_fork[i], NULL);
		philo->last_eat[i] = (long int)0;
		i++;
	}
	philo->mutex_id = mutex_id;
	philo->mutex_fork = mutex_fork;
	philo->mutex_dead = mutex_dead;
	ft_init_struc_2(philo, argv);
}

int	ft_are_you_dead(t_ptr *philo)
{
	pthread_mutex_lock(&philo->mutex_dead);
	if (philo->dead == 1)
	{
		pthread_mutex_unlock(&philo->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex_dead);
	return (0);
}

void	*ft_philo(void	*arg)
{
	t_ptr	*philo;
	int		id;
	int		state;
	int		eat;

	state = 0;
	eat = 0;
	philo = (t_ptr *)arg;
	pthread_mutex_lock(&philo->mutex_id);
	id = philo->id;
	philo->last_eat[id] = ft_get_time(philo);
	pthread_mutex_unlock(&philo->mutex_id);
	ft_choose_state(philo, id, state, eat);
	ft_mutiple_lock(0, &philo->mutex_id, &philo->mutex_last_eat);
	philo->last_eat[id] = (long int)-1;
	pthread_mutex_unlock(&philo->mutex_last_eat);
	if (ft_are_you_dead(philo) == 0)
		printf("%ld		%d	found the answer\n",
			ft_get_time(philo), id);
	pthread_mutex_unlock(&philo->mutex_id);
	return (0);
}

int	main(int argc, char **argv)
{	
	pthread_t		*th;
	t_ptr			philo;
	pthread_t		satan;
	int				id;

	if (ft_check(argc - 1, argv) != 0 || ft_check_overflow(argv) != 0)
		return (0);
	ft_init_struc(&philo, argv);
	philo.start = philo.tv.tv_usec / 1000 + (philo.tv.tv_sec * 1000);
	th = (pthread_t *)ft_calloc(ft_atoi(argv[1]) + 1, sizeof(pthread_t));
	if (th == NULL)
		return (1);
	id = 1;
	while (id < ft_atoi(argv[1]) + 1)
	{
		pthread_create(&th[id], NULL, &ft_philo, &philo);
		usleep(200);
		pthread_mutex_lock(&philo.mutex_id);
		philo.id++;
		id++;
		pthread_mutex_unlock(&philo.mutex_id);
	}
	pthread_create(&satan, NULL, &ft_satan, &philo);
	ft_main_part_2(&philo, th, satan, id);
	return (0);
}
