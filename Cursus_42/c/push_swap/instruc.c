/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:02:44 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 16:06:17 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_chain	*ft_swap_first(t_chain *chain, char c)
{
	t_chain	*tmp;
	t_chain	*tmp2;

	if (ft_count(chain) > 2)
		tmp2 = chain->next->next;
	tmp = chain->next;
	chain->next = tmp->next;
	tmp->next = chain;
	tmp->prev = NULL;
	chain->prev = tmp;
	if (ft_count(chain) >= 2)
		tmp2->prev = chain;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
	if (c == 's')
		ft_printf("ss\n");
	return (tmp);
}

t_chain	*ft_push(t_chain *src, t_chain *dst, char c)
{
	t_chain	*tmp;

	tmp = src;
	if (src->next)
	{
		src = src->next;
		src->prev = NULL;
	}
	tmp->next = dst;
	dst->prev = tmp;
	if (c == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	return (src);
}

t_chain	*ft_rotate(t_chain *head, char c)
{
	t_chain	*tmp;
	t_chain	*tmp2;

	tmp = head;
	while (head->next != NULL)
	{
		tmp2 = head;
		head = head->next;
		head->prev = tmp2;
	}
	tmp2 = head->prev;
	tmp2->next = NULL;
	tmp->prev = head;
	head->prev = NULL;
	head->next = tmp;
	if (c == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	return (head);
}

t_chain	*ft_reverse_rotate(t_chain *head, char c)
{
	t_chain	*tmp;
	t_chain	*first;

	first = head;
	tmp = head->next;
	while (head->next != NULL)
		head = head->next;
	head->next = first;
	tmp->prev = NULL;
	first->prev = head;
	first->next = NULL;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
	return (tmp);
}
