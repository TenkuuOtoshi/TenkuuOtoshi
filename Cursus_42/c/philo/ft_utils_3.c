/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:53:44 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/19 15:10:40 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

int	ft_check_overflow(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > (long int)2147483647)
		{
			printf("Error\n");
			return (1);
		}
		if (argv[5] && ft_atoi(argv[5]) == 0)
		{
			printf("Number of times each philosopher must eat can't be 0\n");
			return (1);
		}
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
	{
		printf("Number of philosopher can't be less than 1");
		return (1);
	}
	return (0);
}
