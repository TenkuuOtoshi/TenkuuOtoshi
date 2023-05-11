/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:39:57 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/11 13:58:05 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

class	ScavTrap : public ClapTrap
{
	public :

					~ScavTrap();
					ScavTrap(std::string name);
					ScavTrap(const ScavTrap &a);
	ScavTrap&		operator = (const ScavTrap &a);

	void			guardGate();
	void			attack(const std::string& target);

};