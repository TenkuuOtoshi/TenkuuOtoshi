/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:25:03 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/19 17:35:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

void	*ft_checker(void	*arg)
{
	t_ptr			*philo;
	long int		leat;

	philo = (t_ptr *)arg;
	while (ft_are_you_dead(philo) == 0 && ft_check_succes(philo) == 0)
	{
		sem_wait(philo->sem_last_eat);
		leat = philo->last_eat;
		sem_post(philo->sem_last_eat);
		if (ft_get_time(philo) >= leat + philo->time_die && leat != -1)
		{
			ft_print(philo, philo->id);
			while (1)
				;
		}
	}
	ft_mutiple_lock(2, philo->sem_fork, philo->sem_last_eat);
	ft_mutiple_lock(2, philo->sem_id, philo->sem_dead);
	ft_mutiple_lock(2, philo->sem_big_succes, philo->sem_big_dead);
	while (1)
		;
	exit(0);
}

void	ft_init_struc(t_ptr *philo, char **argv)
{
	int				i;

	i = 0;
	philo->sem_last_eat = sem_open("last_eat", O_CREAT, 6666, 1);
	philo->sem_dead = sem_open("dead", O_CREAT, 6666, 1);
	philo->sem_print = sem_open("print", O_CREAT, 6666, 1);
	philo->sem_big_dead = sem_open("big dead", O_CREAT, 6666, ft_atoi(argv[1]));
	philo->sem_big_succes = sem_open("succes", O_CREAT, 6666, ft_atoi(argv[1]));
	philo->sem_fork = sem_open("fork", O_CREAT, 6666, ft_atoi(argv[1]));
	philo->sem_id = sem_open("id", O_CREAT, 6666, 1);
	philo->pid = (int *)ft_calloc(ft_atoi(argv[1]), sizeof(int));
	if (philo->pid == NULL || ft_check_sem(philo) != 0)
		exit(0);
	while (i < ft_atoi(argv[1]))
	{
		philo->pid[i] = 0;
		i++;
	}
	philo->last_eat = (long int)-1;
	ft_init_struc_2(philo, argv);
}

int	ft_are_you_dead(t_ptr *philo)
{
	sem_wait(philo->sem_dead);
	if (philo->dead == 1)
	{
		sem_post(philo->sem_dead);
		return (1);
	}
	sem_post(philo->sem_dead);
	return (0);
}

void	*ft_philo(void	*arg)
{
	t_ptr		*philo;
	int			id;
	int			state;
	int			eat;

	state = 0;
	eat = 0;
	philo = (t_ptr *)arg;
	id = ft_init_time_and_thread(philo);
	ft_choose_state(philo, id, state, eat);
	if (ft_are_you_dead(philo) == 0)
	{
		sem_wait(philo->sem_dead);
		philo->succes = 1;
		sem_post(philo->sem_big_succes);
		sem_post(philo->sem_dead);
		printf("ld		%d	found the answer\n", ft_get_time(philo), id);
	}
	free(philo->pid);
	usleep(1000);
	while (1)
		;
	exit(0);
}

int	main(int argc, char **argv)
{	
	t_ptr			philo;
	int				id;

	if (ft_check(argc - 1, argv) != 0 || ft_check_overflow(argv) != 0)
		return (0);
	ft_init_struc(&philo, argv);
	gettimeofday(&philo.tv, NULL);
	philo.start = philo.tv.tv_usec / 1000 + (philo.tv.tv_sec * 1000);
	id = 1;
	while (id <= ft_atoi(argv[1]))
	{
		philo.pid[id - 1] = fork();
		if (philo.pid[id - 1] == -1)
			return (1);
		if (philo.pid[id - 1] == 0)
			ft_philo(&philo);
		sem_wait(philo.sem_id);
		philo.id++;
		id++;
		sem_post(philo.sem_id);
		sem_wait(philo.sem_big_dead);
		sem_wait(philo.sem_big_succes);
	}
	ft_main_part_2(&philo, id);
	return (0);
}
