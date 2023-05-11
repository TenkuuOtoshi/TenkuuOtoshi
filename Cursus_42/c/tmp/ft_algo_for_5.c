/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:49:21 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/22 15:26:32 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_algo_5(char **argv)
{
	t_chain *a;
	t_chain *b;
	int		c;

	a = ft_make_chain_a(argv);
	c = ft_count(a);
	if (ft_check_order(a) == 0)
		return ;
	a = ft_putsmallest_first(a);
	a = a->next;
	b = ft_make_chain_b(a->prev);
	while (ft_count(a) != 3)
	{
		a = ft_putsmallest_first(a);
		a = ft_push(a, b, 'b');
		b = b->prev;
	}
	if (ft_check_order(a) != 0)
		a = ft_process_3(a);
	while (ft_count(a) != c)
	{
		b = ft_push(b, a, 'a');
		a = a->prev;
	}
	if (ft_check_order(a) != 0)
		ft_process_5(a);
	//ft_print(a);
	//ft_printf("%d\n", ft_count(a));
	//ft_print(b);
	ft_free_lst(a);
}

t_chain *ft_process_5(t_chain *a)
{
	t_chain *b;
	int	c;

	c = ft_count(a);
	if (ft_check_order(a) == 0)
		return (a);
	a = ft_putsmallest_first(a);
	a = a->next;
	b = ft_make_chain_b(a->prev);
	while (ft_count(a) != 3)
	{
		a = ft_putsmallest_first(a);
		a = ft_push(a, b, 'b');
		b = b->prev;
	}
	a = ft_process_3(a);
	while (ft_count(a) != c)
	{
		b = ft_push(b, a, 'a');
		a = a->prev;
	}
	return (a);
}


t_chain *ft_putbiggest_first(t_chain *a)
{
	while (ft_check_biggest(a) != 1)
	{
		if (ft_check_biggest(a) <= ft_count(a) / 2)
			a = ft_reverse_rotate(a, 'b');
		else
			a = ft_rotate(a, 'b');
		
	}
	return (a);
}

t_chain *ft_putsmallest_first(t_chain *a)
{
	while (ft_check_smallest(a) != 1)
	{
		if (ft_check_smallest(a) <= ft_count(a) / 2)
			a = ft_reverse_rotate(a, 'a');
		else
			a = ft_rotate(a, 'a');
		
	}
	return (a);
}
