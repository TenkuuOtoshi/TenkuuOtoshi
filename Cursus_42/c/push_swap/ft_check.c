/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:20:38 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/29 10:16:01 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_check_order(t_chain *head)
{
	int	i;

	i = 1;
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
			return (i);
		head = head->next;
		i++;
	}
	return (0);
}

t_chain	*ft_move_forward_2(t_chain *a)
{
	while (ft_is_small_2(a, a->pos) != 0)
		a = ft_rotate(a, 'a');
	return (a);
}

t_chain	*ft_move_backward_2(t_chain *a)
{
	while (ft_is_small_2(a, a->pos) != 0)
		a = ft_reverse_rotate(a, 'a');
	return (a);
}
