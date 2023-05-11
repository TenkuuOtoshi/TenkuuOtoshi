/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:07:47 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/21 17:17:13 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newhead;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	newhead = ft_lstnew(f(lst->content));
	new = newhead;
	tmp = lst->next;
	while (tmp != NULL)
	{
		new->next = ft_lstnew(f(tmp->content));
		if (new->content == NULL)
		{
			ft_lstclear(&newhead, del);
			return (NULL);
		}
		tmp = tmp->next;
		new = new->next;
	}
	return (newhead);
}
