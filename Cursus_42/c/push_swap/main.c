/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:53:46 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 16:26:27 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
		if (tmp->n == 0)
			ft_printf("%u\n", tmp->n);
		ft_printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	ft_printf("end\n");
}

int	ft_count_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	ft_check_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fuse(char **argv)
{
	int		j;
	char	*str;

	j = 2;
	str = ft_strjoin(argv[1], " ", 0);
	while (argv[j])
	{
		if (argv[j][0] == '\0')
			str = ft_strjoin(str, "WWW", 1);
		str = ft_strjoin(str, argv[j], 1);
		str = ft_strjoin(str, " ", 1);
		j++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	arg;

	arg = 1;
	if (!argv[1])
		return (0);
	argv[1] = ft_fuse(argv);
	if (ft_check_bad_char(argv[1]) == 1)
		return (0);
	argv = ft_split(argv[1], ' ');
	if (ft_check_nbr(argv) != 0)
		return (ft_free_arg(argv, arg));
	if (ft_check_double(argv, arg) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_free_arg(argv, arg));
	}
	if (ft_count_arg(argv) == 2)
	{
		if (ft_atoi(argv[0]) > ft_atoi(argv[1]))
			ft_printf("sa\n");
		return (ft_free_arg(argv, arg));
	}
	ft_choose_best_algo(argv, arg);
	ft_free_arg(argv, arg);
	(void)argc;
}
