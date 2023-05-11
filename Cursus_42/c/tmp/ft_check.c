/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:20:38 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/17 09:43:18 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_check_order(t_chain *head)
{
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
			return (1);
		head = head->next;
	}
	return (0);
}
