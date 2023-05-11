/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:26:06 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/24 09:37:28 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_chain	*ft_quicksort(t_chain *a)
{
	t_chain *pivot;
	int i;
	int j;

	i = 0;
	j = 1;
	pivot = a;
	if (ft_check_order(a) == 0)
		return (a);
	while (pivot->next != NULL)
		pivot = pivot->next;
	while (ft_check_nb(a, j) != pivot->n)
	{
		if (ft_check_nb(a, j) < pivot->n)
			{
				i++;
				a = ft_move(a, i, j);
			}
		j++;
	}
	return (a);
}

t_chain	*ft_move(t_chain *a, int i, int j)
{
	if (i == 1 && j == 2)
		a = ft_swap_first(a, 'a');
	else if (i + 1 == j)
	{
		a = ft_rotation(a, i,1);
		a = ft_swap_first(a, 'a');
		a = ft_rotation(a, ft_count(a) - 1, ft_count(a));
	}
	else
		{
			
		}
	return (a);
}

t_chain *ft_rotation(t_chain *a, int i, int pos)
{
	int j;

	j = ft_check_nb(a, i);
	while (ft_check_nb(a, pos) != j)
	{
		if (i <= ft_count(a) / 2)
			a = ft_reverse_rotate(a, 'a');
		else
			a = ft_rotate(a, 'a');
	}
	return (a);
}

int	ft_check_nb(t_chain *a, int j)
{
	int i;

	i = 1;
	while (a->prev != NULL)
		a = a->prev;
	while (i != j)
	{

		a = a->next;
		i++;
	}
	return (a->n);
}
