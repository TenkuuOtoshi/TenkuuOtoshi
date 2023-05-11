/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:36:10 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 16:00:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_chain	*ft_make_chain_a(char **argv, int arg)
{
	t_chain	*head;
	int		i;

	i = 1;
	if (arg == 1)
		i = 0;
	head = ft_head_chain(ft_atoi(argv[i]));
	i++;
	while (argv[i])
	{
		ft_add_block(ft_atoi(argv[i]), head, 'a');
		i++;
	}
	ft_set_pos(head);
	return (head);
}

int	ft_free_arg(char **argv, int arg)
{
	int	i;

	if (arg == 0)
		return (1);
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (0);
}

void	ft_free_lst(t_chain *lst)
{
	t_chain	*tmp;

	while (lst->prev != NULL)
		lst = lst->prev;
	while (lst->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
}

int	ft_check_double(char **argv, int arg)
{
	t_chain	*back;
	t_chain	*front;
	t_chain	*head;
	t_chain	*a;
	int		i;

	a = ft_make_chain_a(argv, arg);
	head = a;
	back = head;
	front = head;
	i = ft_check_double_2(head, back, front, a);
	if (i == 0)
		ft_free_lst(a);
	return (i);
}

int	ft_check_double_2(t_chain *head, t_chain *back, t_chain *front, t_chain *a)
{
	while (head)
	{
		while (back->prev != NULL)
		{
			back = back->prev;
			if (back->n == head->n)
			{
				ft_free_lst(a);
				return (1);
			}
		}
		while (front->next != NULL)
		{
			front = front->next;
			if (front->n == head->n)
			{
				ft_free_lst(a);
				return (1);
			}
		}
		head = head->next;
		back = head;
		front = head;
	}
	return (0);
}
