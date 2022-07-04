/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:26:44 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/19 12:11:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	if (n == 0)
		return (0);
	while (i < n)
	{
		ps[i] = 0;
		i++;
	}
	return (0);
}