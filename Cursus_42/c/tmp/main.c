/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:53:46 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/22 13:58:25 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

// 1500 max pour 100
//valgrind ./push_swap $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM

void	ft_print(t_chain *ca1)
{
	t_chain	*tmp;

	tmp = ca1;
	if (ca1 == NULL)
		return ;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	while (tmp != NULL)
	{
		if (tmp->pos == 0)
			ft_putstr("0\n");
		else
		ft_printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	ft_printf("end\n");
}

int	ft_count_arg(char **argv)
{
	int i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (--i);
}

int	main(int argc, char **argv)
{
	if (!argv[1])
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ft_check_nbr(argv) != 0)
		return (0);
	if (ft_count_arg(argv) == 2)
	{
		if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
			ft_printf("sa\n");
		return (0);
	}
	else if (ft_count_arg(argv) == 3)
		ft_algo_3(argv);
	else if (ft_count_arg(argv) > 3 && ft_count_arg(argv) <= 70)
		ft_algo_5(argv);
	else if (ft_count_arg(argv) >= 71)
		ft_algo_100(argv);
	//ft_quicksort(argv);
	//head = ft_rotate(head);
	//ft_swap_first(head);
	//ft_push(b, head);
	(void)argc;
}
