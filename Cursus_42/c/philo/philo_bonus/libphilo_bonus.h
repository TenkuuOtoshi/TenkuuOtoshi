/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:10:02 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/19 14:25:43 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_BONUS_H
# define LIBPHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct t_ptr
{
	int				id;
	sem_t			*sem_id;
	sem_t			*sem_fork;
	sem_t			*sem_dead;
	sem_t			*sem_print;
	sem_t			*sem_big_dead;
	sem_t			*sem_big_succes;
	sem_t			*sem_last_eat;
	int				nb_of_philo;
	int				nb_of_fork;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_must_eat;
	int				dead;
	int				succes;
	long int		start;
	long int		last_eat;
	int				*pid;
	char			**argv;
	struct timeval	tv;
}	t_ptr;

int			ft_check_usleep_death(t_ptr *philo, long int last_eat, int id);
void		ft_choose_state(t_ptr *philo, int id, int state, int eat);
int			ft_check_death(t_ptr *philo, long int time_die, int id);
int			ft_check_mutex_dead(t_ptr *philo, long int last_eat);
void		ft_eating_two(t_ptr *philo, int id, long int tmp);
void		ft_mutiple_lock(int i, sem_t *m1, sem_t *m2);
int			ft_eating(t_ptr *philo, int id, int state);
void		ft_init_struc_2(t_ptr *philo, char **argv);
int			ft_sleep(t_ptr *philo, int id, int state);
int			ft_think(t_ptr *philo, int id, int state);
void		ft_init_struc(t_ptr *philo, char **argv);
int			ft_init_time_and_thread(t_ptr *philo);
size_t		ft_strcpy(char *dst, const char *src);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_main_part_2(t_ptr *philo, int id);
void		ft_print(t_ptr *ft_philo, int i);
void		ft_update_last_eat(t_ptr *philo);
void		*ft_check_big_succes(void *arg);
int			ft_check(int argc, char **argv);
int			ft_check_overflow(char **argv);
int			ft_are_you_dead(t_ptr *philo);
int			ft_check_succes(t_ptr *philo);
void		*ft_bzero(void *s, size_t n);
int			ft_check_sem(t_ptr *philo);
void		*ft_wait_death(void	*arg);
long int	ft_atoi(const char *nptr);
long int	ft_get_time(t_ptr *philo);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
void		*ft_checker(void *arg);
void		*ft_philo(void *arg);
#endif