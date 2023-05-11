/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:09:38 by tlarraze          #+#    #+#             */
/*   Updated: 2022/09/05 16:26:31 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_check_bad_char(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (ft_check_bad_char_2(s, i, c) == 1)
		return (1);
	if (ft_check_bad_char_3(s, i, c) == 0)
	{
		free(s);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	ft_check_bad_char_2(char *s, int i, int c)
{
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
		{
			if ((s[i] != '-' && s[i] != '+' && s[i] != ' ') || ((s[i] == '+'
						|| s[i] == '-') && (s[i + 1] == ' ' || s[i + 1] == '+'
						|| s[i + 1] == '-')))
			{
				ft_free_and_error(s);
				return (1);
			}
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i + 1] == '-' || s[i + 1] == '+')
			{
				ft_free_and_error(s);
				return (1);
			}
			c++;
		}
		i++;
	}
	return (0);
}

int	ft_check_bad_char_3(char *s, int i, int c)
{
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
		{
			if ((s[i] != '-' && s[i] != '+' && s[i] != ' ') || ((s[i] == '+'
						|| s[i] == '-') && (s[i + 1] == ' ' || s[i + 1] == '+'
						|| s[i + 1] == '-')))
			{
				ft_free_and_error(s);
				return (1);
			}
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i + 1] == '-' || s[i + 1] == '+')
			{
				ft_free_and_error(s);
				return (1);
			}
			c++;
		}
		i++;
	}
	return (c);
}

void	ft_free_and_error(char *s)
{
	free(s);
	ft_putstr_fd("Error\n", 2);
}

void	ft_choose_best_algo(char **argv, int arg)
{
	if (ft_count_arg(argv) == 3)
		ft_algo_3(argv, arg);
	else if (ft_count_arg(argv) > 3 && ft_count_arg(argv) <= 70)
		ft_algo_5(argv, arg);
	else if (ft_count_arg(argv) >= 71 && ft_count_arg(argv) <= 350)
		ft_algo_100(argv, arg);
	else if (ft_count_arg(argv) > 350)
		ft_algo_500(argv, arg);
}
