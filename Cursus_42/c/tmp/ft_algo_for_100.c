/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/01 00:00:02 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/22 17:50:47 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_algo_100(char **argv)
{
	t_chain	*a;
	t_chain	*b;
	int		c;
	int		nb;

	a = ft_make_chain_a(argv);
	nb = ft_average_nb(a);
	b = NULL;
	c = ft_count(a);
	if (ft_check_order(a) == 0)
		return ;
	ft_set_pos(a);
	while (ft_count(a) != 1)
	{
		if (ft_search_smallest(a, 0) < ft_search_smallest(a, 1) + 1)
				a = ft_move_forward(a, ft_search_smallest(a, 0));
		else if (ft_search_smallest(a, 0) > ft_search_smallest(a, 1) + 1)
				a = ft_move_backward(a, ft_search_smallest(a, 1));
		else if	(ft_search_smallest(a, 0) == ft_search_smallest(a, 1) + 1)
				a = ft_move_forward(a, ft_search_smallest(a, 0));
		else
			a =ft_putsmallest_first(a);		
		if (b == NULL)
		{
			a = a->next;
			b = ft_make_chain_b(a->prev);
		}
		else 
		{
			a = ft_push(a, b, 'b');
			b = b->prev;
			if (b->n > nb)
				b = ft_reverse_rotate(b, 'b');
		}
	}
	b = ft_putbiggest_first(b);
	b = ft_push(b, a, 'a');
	a = a->prev;
	a = ft_swap_first(a, 'a');
	a = ft_push(a, b, 'b');
	b = b->prev;
	while (ft_count(a) != c)
	{
		b = ft_putbiggest_first(b);
		b = ft_push(b, a, 'a');
		a = a->prev;
	}
	/* if (ft_check_order(a) != 0)
		a = ft_process_5(a); */
	b = NULL;
/* 	ft_print(a);
	if (ft_check_order(a) == 0)
		ft_printf("ORDER OK\n");
	if (ft_check_order(a) != 0)
		ft_printf("ORDER KO\n"); */
	ft_free_lst(a);	
}

int	ft_average_nb(t_chain *a)
{
	long int	nb;
	int			i;

	nb = a->n;
	i = 0;
	a = a->next;
	while (a->next != NULL)
	{
		nb += a->n;
		a = a->next;
		i++;
	}
	return (nb / (i));
}


int	ft_search_smallest(t_chain *a, int i)
{
	if (i == 0)
	{
		while (i != 13 && a->next != NULL)
		{
			if (ft_is_small(a, a->pos) == 0)
				return (i);
			
			a = a->next;
			i++;
		}
	}
	if (i == 1)
	{
		while (a->next != NULL)
			a = a->next;
		while (i != ft_count(a) / 10 && a->prev != NULL)
		{			
			if (ft_is_small(a, a->pos) == 0)
				return (i);
			a = a->prev;
			i++;
		}
	}
	return (0);
}

int	ft_is_small(t_chain *a, int pos)
{
	int		i;
	int		c;
	t_chain *tmp;

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
	if (c < (ft_count(a) / 4) + 7)
		return (0);
	else
		return (1);
}

void	ft_set_pos(t_chain *a)
{
	int		i;
	int		j;
	int		n;
	t_chain *head;
	t_chain *tmp;

	i = 1;
	j = 1;
	head = a;
	tmp = a;
	while (i <= ft_count(head))
	{
		n = tmp->n;
		tmp->pos = 1;
		while (j <= ft_count(head))
		{
			if (a->n < n)
				tmp->pos++;
			a = a->next;
			j++;
		}
 		tmp = tmp->next;
		a = head;
		j = 1;
		i++;
	}
}
