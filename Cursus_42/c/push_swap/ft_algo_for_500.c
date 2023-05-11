/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_500.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:30:28 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 14:44:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_algo_500(char **argv, int arg)
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
		a = ft_move_big_2(a);
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
	ft_algo_500_p2(a, b);
}

void	ft_algo_500_p2(t_chain *a, t_chain *b)
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
	a = ft_big_while_2(a, b, c);
	a = ft_check_end(a);
	while (ft_check_order(a) != 0)
		a = ft_process_5(a);
	b = NULL;
	ft_free_lst(a);
}

t_chain	*ft_big_while_2(t_chain *a, t_chain *b, int c)
{
	while (ft_count(a) != c)
	{
		b = ft_move_2_big(b, a);
		a = ft_reset(a);
		b = ft_push(b, a, 'a');
		a = ft_reset(a);
		if (a->pos > a->next->pos && b->next != NULL
			&& b->pos < b->next->pos && ft_check_order(a) != 0)
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

int	ft_search_smallest_2(t_chain *a, int i)
{
	if (i == 0)
	{
		while (i <= 11 && a->next != NULL)
		{
			if (ft_is_small(a, a->pos) == 0)
				return (i);
			a = a->next;
			i++;
		}
		i = -1;
	}
	if (i == 1)
	{
		i = 0;
		while (a->next != NULL)
			a = a->next;
		while (i <= 11 && a->prev != NULL)
		{			
			if (ft_is_small_2(a, a->pos) == 0)
				return (i + 1);
			a = a->prev;
			i++;
		}
	}
	return (-1);
}

int	ft_is_small_2(t_chain *a, int pos)
{
	int		i;
	int		c;
	t_chain	*tmp;

	i = 1;
	c = 0;
	while (a->prev != NULL)
		a = a->prev;
	tmp = a;
	while (i != ft_count(a))
	{
		if (tmp->pos < pos)
			c++;
		tmp = tmp->next;
		i++;
	}
	if (c < 23)
		return (0);
	else
		return (1);
}
