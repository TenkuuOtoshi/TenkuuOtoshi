/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:18:26 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 15:55:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_search_2_big(t_chain *b)
{
	t_chain	*tmp;
	int		pos;

	tmp = b;
	pos = 0;
	while (tmp->next != NULL)
	{
		if (tmp->pos > pos)
		pos = tmp->pos;
		tmp = tmp->next;
	}
	return (pos - 1);
}

t_chain	*ft_move_2_big(t_chain *b, t_chain *a)
{
	int	pos;

	pos = ft_search_2_big(b);
	while (ft_check_biggest(b) != 1)
	{
		if (b->pos == pos)
			b = ft_push(b, a, 'a');
		if (ft_check_biggest(b) == 1)
			return (b);
		if (ft_check_biggest(b) <= (ft_count(b) / 2))
			b = ft_reverse_rotate(b, 'b');
		else
			b = ft_rotate(b, 'b');
	}
	return (b);
}

t_chain	*ft_move_big_2(t_chain *a)
{
	if (ft_search_smallest_2(a, 0) < ft_search_smallest_2(a, 1) + 1)
		a = ft_move_forward_2(a);
	else if (ft_search_smallest_2(a, 0) > ft_search_smallest_2(a, 1) + 1)
		a = ft_move_backward_2(a);
	else if (ft_search_smallest_2(a, 0) == ft_search_smallest_2(a, 1) + 1)
		a = ft_move_small_2(a);
	else
		a = ft_putsmallest_first(a);
	return (a);
}

t_chain	*ft_reset(t_chain *a)
{
	while (a->prev != NULL)
		a = a->prev;
	return (a);
}

int	ft_search_smallest(t_chain *a, int i)
{
	if (i == 0)
	{
		while (i != 5 && a->next != NULL)
		{
			if (ft_is_small(a, a->pos) == 0)
				return (i);
			a = a->next;
			i++;
		}
		return (-1);
	}
	if (i == 1)
	{
		while (a->next != NULL)
			a = a->next;
		while (i != 4 && a->prev != NULL)
		{
			if (ft_is_small(a, a->pos) == 0)
				return (i);
			a = a->prev;
			i++;
		}
	}
	return (-1);
}
