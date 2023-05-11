/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_100_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:31:01 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 14:18:16 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_chain	*ft_move_forward(t_chain *a)
{
	while (ft_is_small(a, a->pos) != 0)
		a = ft_rotate(a, 'a');
	return (a);
}

t_chain	*ft_move_backward(t_chain *a)
{
	while (ft_is_small(a, a->pos) != 0)
		a = ft_reverse_rotate(a, 'a');
	return (a);
}

t_chain	*ft_move_small(t_chain *a)
{
	t_chain	*tmp;
	t_chain	*tmp2;

	tmp = a;
	tmp2 = a;
	while (ft_is_small(tmp, tmp->pos) != 0)
		tmp = tmp->next;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	while (ft_is_small(tmp2, tmp2->pos) != 0)
		tmp2 = tmp2->prev;
	if (tmp2->n > tmp->n)
		a = ft_move_backward(a);
	else
		a = ft_move_forward(a);
	return (a);
}

int	ft_is_small(t_chain *a, int pos)
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
	if (c < 11)
		return (0);
	else
		return (1);
}

t_chain	*ft_check_end(t_chain *a)
{
	if (ft_check_order(a) != 0)
	{
		a = ft_rotate(a, 'a');
		a = ft_rotate(a, 'a');
		a = ft_swap_first(a, 'a');
		a = ft_reverse_rotate(a, 'a');
		a = ft_reverse_rotate(a, 'a');
	}
	return (a);
}
