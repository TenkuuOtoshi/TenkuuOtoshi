/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_500_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:27:33 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 14:31:38 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_chain	*ft_move_small_2(t_chain *a)
{
	t_chain	*tmp;
	t_chain	*tmp2;

	tmp = a;
	tmp2 = a;
	while (ft_is_small_2(tmp, tmp->pos) != 0)
		tmp = tmp->next;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	while (ft_is_small_2(tmp2, tmp2->pos) != 0)
		tmp2 = tmp2->prev;
	if (tmp2->n > tmp->n)
		a = ft_move_backward_2(a);
	else
		a = ft_move_forward_2(a);
	return (a);
}
