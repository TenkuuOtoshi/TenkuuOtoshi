/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/01 00:00:02 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 14:26:26 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_algo_100(char **argv, int arg)
{
	t_chain	*a;
	t_chain	*b;

	a = ft_make_chain_a(argv, arg);
	b = NULL;
	if (ft_check_order(a) == 0)
		return ;
	a = ft_move_big(a);
	a = a->next;
	b = ft_make_chain_b(a->prev);
	while (ft_count(a) != 1)
	{
		a = ft_move_big(a);
		a = ft_push(a, b, 'b');
		b = b->prev;
		if (a->next != NULL && a->n > a->next->n && b->n < b->next->n)
		{
			a = ft_swap_first(a, 0);
			b = ft_swap_first(b, 's');
		}
		else if (b->n < b->next->n)
			b = ft_swap_first(b, 'b');
		a = ft_reset(a);
	}
	ft_algo_100_p2(a, b);
}

t_chain	*ft_move_big(t_chain *a)
{
	if (ft_search_smallest(a, 0) < ft_search_smallest(a, 1))
		a = ft_move_forward(a);
	else if (ft_search_smallest(a, 0) > ft_search_smallest(a, 1))
		a = ft_move_backward(a);
	else if (ft_search_smallest(a, 0) == ft_search_smallest(a, 1))
		a = ft_move_small(a);
	else
		a = ft_putsmallest_first(a);
	return (a);
}

void	ft_algo_100_p2(t_chain *a, t_chain *b)
{
	int	c;

	c = ft_count(a) + ft_count(b);
	if (a->pos != 100)
	{
		b = ft_putbiggest_first(b);
		b = ft_push(b, a, 'a');
		a = a->prev;
		a = ft_swap_first(a, 'a');
		a = ft_push(a, b, 'b');
		b = b->prev;
	}
	a = ft_big_while(a, b, c);
	a = ft_check_end(a);
	while (ft_check_order(a) != 0)
		a = ft_process_5(a);
	b = NULL;
	ft_free_lst(a);
}

t_chain	*ft_big_while(t_chain *a, t_chain *b, int c)
{
	while (ft_count(a) != c)
	{
		b = ft_move_2_big(b, a);
		a = ft_reset(a);
		b = ft_push(b, a, 'a');
		a = ft_reset(a);
		if (a->pos > a->next->pos && b->next
			!= NULL && b->pos < b->next->pos && ft_check_order(a) != 0)
		{
				a = ft_swap_first(a, 0);
				b = ft_swap_first(b, 's');
				a = ft_reset(a);
				b = ft_reset(b);
		}
		else if (a->pos > a->next->pos && ft_check_order(a) != 0)
				a = ft_swap_first(a, 'a');
		if (ft_count(a) >= 3 && a->next->pos > a->next->next->pos)
		{
			a = ft_reverse_rotate(a, 'a');
			a = ft_swap_first(a, 'a');
			a = ft_rotate(a, 'a');
		}
	}
	return (a);
}

void	ft_set_pos(t_chain *a)
{
	int		i;
	int		j;
	int		n;
	t_chain	*head;
	t_chain	*tmp;

	i = 1;
	j = 1;
	head = a;
	tmp = a;
	while (i <= ft_count(head))
	{
		n = tmp->n;
		tmp->pos = 1;
		while (j++ <= ft_count(head))
		{
			if (a->n < n)
				tmp->pos++;
			a = a->next;
		}
		tmp = tmp->next;
		a = head;
		j = 1;
		i++;
	}
}
