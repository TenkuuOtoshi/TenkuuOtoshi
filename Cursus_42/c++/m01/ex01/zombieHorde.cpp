/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:16:57 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/04 17:37:16 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	int i;
	Zombie	*ptr;

	i = 0;
	if (N <= 0)
	{
		std::cout << "Error invalid number (" << N << ")" << std::endl;
		return (NULL);
	}
	ptr = new Zombie[N];
	while (i < N)
	{
		ptr[i].give_name(name);
		i++;
	}
	return (ptr);
}