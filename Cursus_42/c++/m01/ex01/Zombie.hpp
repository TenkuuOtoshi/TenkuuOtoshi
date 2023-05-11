/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:17:38 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/04 15:20:51 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include "Zombie.h"

class	Zombie	{
	
	public :

			Zombie(void);
			~Zombie(void);
	void	announce(void);
	void	give_name(std::string name);
	Zombie*	newZombie(std::string name);
	void	randomChump( std::string name );
	Zombie*	zombieHorde(int N, std::string name);

	private :
		std::string	_name;
};

#endif