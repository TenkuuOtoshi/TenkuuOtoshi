/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:35:36 by tlarraze          #+#    #+#             */
/*   Updated: 2022/04/04 13:59:46 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(*s * sizeof(char));
	if (ptr == NULL)
		return (0);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}
