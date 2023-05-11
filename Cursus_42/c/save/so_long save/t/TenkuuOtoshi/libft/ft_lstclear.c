/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:22:56 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/21 17:28:16 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*lst);
	while (tmp != NULL)
	{
		tmp2 = tmp;
		del(tmp->content);
		tmp = tmp->next;
		free(tmp2);
	}
	*lst = NULL;
}
