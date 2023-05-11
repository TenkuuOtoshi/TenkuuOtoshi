/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_for_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:58:01 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/26 10:13:54 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_algo_3(char **argv, int arg)
{
	t_chain	*head;

	head = ft_make_chain_a(argv, arg);
	if (ft_check_order(head) == 0)
		return (ft_free_lst(head));
	else
		head = ft_process_3(head);
	ft_free_lst(head);
}

t_chain	*ft_algo_3_last(t_chain *head)
{
	if (ft_check_order(head) != 0)
		head = ft_swap_first(head, 'a');
	return (head);
}

t_chain	*ft_process_3(t_chain *a)
{
	if (ft_check_smallest(a) == 1)
	{
		a = ft_rotate(a, 'a');
		a = ft_swap_first(a, 'a');
		if (ft_check_order(a) != 0)
			a = ft_algo_3_last(a);
	}
	else if (ft_check_smallest(a) == 2)
	{
		if (ft_check_biggest(a) == 1)
			a = ft_reverse_rotate(a, 'a');
		else
			a = ft_swap_first(a, 'a');
	}
	else if (ft_check_smallest(a) == 3)
	{
		if (a->n > a->next->n)
			a = ft_swap_first(a, 'a');
		a = ft_rotate(a, 'a');
		if (ft_check_order(a) != 0)
			a = ft_process_3(a);
	}
	return (a);
}

int	ft_check_smallest(t_chain *head)
{
	t_chain	*tmp;
	int		i;
	int		block;

	tmp = head;
	i = head->n;
	block = 1;
	while (head->next != NULL)
	{
		if (head->n < i)
			i = head->n;
		head = head->next;
	}
	if (head->n < i)
	i = head->n;
	head = head->next;
	while (i != tmp->n)
	{
		tmp = tmp->next;
		block++;
	}
	return (block);
}

int	ft_check_biggest(t_chain *head)
{
	t_chain	*tmp;
	int		i;
	int		block;

	tmp = head;
	i = -2147483648;
	block = 1;
	while (head->next != NULL)
	{
		if (head->n > i)
			i = head->n;
		head = head->next;
	}
	if (head->n > i)
	i = head->n;
	head = head->next;
	while (i != tmp->n)
	{
		tmp = tmp->next;
		block++;
	}
	return (block);
}
