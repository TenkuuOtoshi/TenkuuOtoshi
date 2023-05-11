/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:49:21 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 15:05:25 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_algo_5(char **argv, int arg)
{
	t_chain	*a;

	a = ft_make_chain_a(argv, arg);
	a = ft_process_5(a);
	if (ft_check_order(a) != 0)
		ft_process_5(a);
	ft_free_lst(a);
}

t_chain	*ft_process_5(t_chain *a)
{
	t_chain	*b;
	int		c;

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
	if (ft_check_order(a) != 0)
		a = ft_process_3(a);
	while (ft_count(a) != c)
	{
		b = ft_push(b, a, 'a');
		a = a->prev;
	}
	return (a);
}

t_chain	*ft_putbiggest_first(t_chain *a)
{
	while (ft_check_biggest(a) != 1)
	{
		if (ft_check_biggest(a) <= (ft_count(a) / 2) + 1)
			a = ft_reverse_rotate(a, 'b');
		else
			a = ft_rotate(a, 'b');
	}
	return (a);
}

t_chain	*ft_putsmallest_first(t_chain *a)
{
	while (ft_check_smallest(a) != 1)
	{
		if (ft_check_smallest(a) <= (ft_count(a) / 2) + 1)
			a = ft_reverse_rotate(a, 'a');
		else
			a = ft_rotate(a, 'a');
	}
	return (a);
}

int	ft_check_nbr(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != '-')
			{
				ft_putstr_fd("Error\n", 2);
				return (42);
			}
			j++;
		}
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			return (42);
		}
		j = 0;
		i++;
	}
	return (0);
}
