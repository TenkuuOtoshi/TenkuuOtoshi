/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:19:22 by tlarraze          #+#    #+#             */
/*   Updated: 2022/10/26 13:55:06 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpip.h"

int	ft_init_fork(int id)
{
	id = 0;
	id = fork();
	if (id < 0)
		ft_exit(1);
	return (id);
}

char	*ft_check_access(char **env, char *path, char *str)
{
	if (access(path, R_OK) == 0)
	{
		ft_free_double(env, str);
		return (path);
	}
	return (NULL);
}
