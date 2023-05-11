/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:29:11 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/22 17:59:52 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_chain	*ft_head_chain(int n)
{
	t_chain	*head;

	head = NULL;
	head = (t_chain *)malloc(sizeof(t_chain));
	if (head == NULL)
		return (NULL);
	head->n = n;
	head->pos = 0;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

t_chain	*ft_make_chain_b(t_chain *a)
{
	t_chain	*tmp;

	tmp = a;
	a = a->next;
	a->prev = NULL;
	tmp->next = NULL;
	ft_printf("pb\n");
	return (tmp);
}

void	ft_add_block(int n, t_chain *head, char c)
{
	t_chain	*new;
	t_chain	*tmp;

	new = NULL;
	new = (t_chain *)malloc(sizeof(t_chain));
	if (new == NULL)
		return ;
	if (c == 'b')
		new->n = 0;
	else
		new->n = n;
	new->next = NULL;
	new->pos = 0;
	new->prev = ft_first_block(head);
	tmp = ft_first_block(head);
	tmp->next = new;
}

t_chain	*ft_first_block(t_chain *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

int	ft_count(t_chain *head)
{
	int	i;

	i = 1;
	while (head->next != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}
