/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:36:10 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/23 12:25:03 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_chain	*ft_make_chain_a(char **argv)
{
	t_chain	*head;
	int		i;

	i = 1;
	head = ft_head_chain(ft_atoi(argv[i]));
	i++;
	while (argv[i])
	{
			ft_add_block(ft_atoi(argv[i]), head, 'a');
		i++;
	}
	return (head);
}

void	ft_free_lst(t_chain *lst)
{
	t_chain *tmp;

	while (lst->prev)
		lst = lst->prev;
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);

	}
	free(lst);
}

int	ft_check_nbr(char **argv)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != '-') 
			{
				ft_putstr_fd("Error\n", 2);
				return (42);
			}
			j++;
		}
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483647)
		{
			ft_putstr_fd("Error\n", 2);
			return (42);
		}
		j = 0;
		i++;
	}
	return (0);
}