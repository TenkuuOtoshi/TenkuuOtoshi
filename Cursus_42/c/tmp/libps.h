/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:49:47 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/22 15:41:55 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include <libft.h>

typedef struct s_chain
{
	struct s_chain	*next;
	int				n;
	int				pos;
	struct s_chain	*prev;
}	t_chain;

t_chain	*ft_swap_first(t_chain *chain, char c);
void	ft_init_chain(t_chain *ca1);
void	ft_print(t_chain *ca1);
t_chain	*ft_head_chain(int n);
void	ft_add_block(int n, t_chain *head, char c);
t_chain	*ft_make_chain_a(char **argv);
t_chain	*ft_make_chain_b(t_chain *a);
t_chain	*ft_first_block(t_chain *head);
t_chain	*ft_push(t_chain *src, t_chain *dst, char c);
t_chain	*ft_process_3(t_chain *a);
t_chain *ft_process_5(t_chain *a);
t_chain	*ft_rotate(t_chain *head, char c);
t_chain	*ft_reverse_rotate(t_chain *head, char c);
void	ft_algo_3(char **argv);
void	ft_algo_5(char **argv);
void	ft_quicksort(char **argv);
int		ft_check_nbr(char **argv);
int		ft_check_order(t_chain *head);
int		ft_check_smallest(t_chain *head);
void	ft_algo_3_first(t_chain *head);
int		ft_count(t_chain *head);
t_chain	*ft_putbiggest_first(t_chain *a);
t_chain *ft_putsmallest_first(t_chain *a);
int		ft_check_biggest(t_chain *head);
t_chain	*ft_algo_3_last(t_chain *head);
void	ft_free_lst(t_chain *lst);
t_chain	*ft_move(t_chain *a, int i, int j);
t_chain *ft_rotation(t_chain *a, int i, int pos);
int		ft_check_nb(t_chain *a, int j);
void	ft_set_pos(t_chain *a);
void	ft_algo_100(char **argv);
int	ft_search_smallest(t_chain *a, int i);
int	ft_is_small(t_chain *a, int pos);
t_chain	*ft_move_forward(t_chain *a, int i);
t_chain	*ft_move_backward(t_chain *a, int i);
int	ft_average_nb(t_chain *a);

#endif