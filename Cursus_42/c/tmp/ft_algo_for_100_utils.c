/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_100_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:31:01 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/22 15:26:33 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_chain	*ft_move_forward(t_chain *a, int i)
{
	while (i != ft_search_smallest(a, 0))
		a = ft_rotate(a, 'a');
	return (a);
}

t_chain	*ft_move_backward(t_chain *a, int i)
{
	while (i != ft_search_smallest(a, 0))
		a = ft_reverse_rotate(a, 'a');
	return (a);
}
