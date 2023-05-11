/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:10:02 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/15 18:00:03 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_H
# define LIBPHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct t_ptr
{
	int				id;
	pthread_mutex_t	mutex_id;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_last_eat;
	int				nb_of_philo;
	int				nb_of_fork;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_must_eat;
	int				dead;
	int				succes;
	long int		start;
	long int		*last_eat;
	char			**argv;
	struct timeval	tv;
}	t_ptr;

void		ft_main_part_2(t_ptr *philo, pthread_t *th,
				pthread_t satan, int id);
void		ft_mutiple_lock(int i, pthread_mutex_t *m1, pthread_mutex_t *m2);
int			ft_check_usleep_death(t_ptr *philo, long int last_eat, int id);
void		ft_choose_state(t_ptr *philo, int id, int state, int eat);
int			ft_check_death(t_ptr *philo, long int time_die, int id);
int			ft_check_mutex_dead(t_ptr *philo, long int last_eat);
void		ft_eating_two(t_ptr *philo, int id, long int tmp);
int			ft_eating(t_ptr *philo, int id, int state);
void		ft_init_struc_2(t_ptr *philo, char **argv);
int			ft_sleep(t_ptr *philo, int id, int state);
int			ft_think(t_ptr *philo, int id, int state);
void		ft_init_struc(t_ptr *philo, char **argv);
void		ft_update_last_eat(int id, t_ptr *philo);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_print(t_ptr *ft_philo, int i);
int			ft_check(int argc, char **argv);
int			ft_check_overflow(char **argv);
int			ft_are_you_dead(t_ptr *philo);
void		*ft_bzero(void *s, size_t n);
long int	ft_atoi(const char *nptr);
long int	ft_get_time(t_ptr *philo);
void		*ft_print_arg(void *arg);
void		*ft_philo(void *arg);
void		*ft_satan(void *arg);

#endif