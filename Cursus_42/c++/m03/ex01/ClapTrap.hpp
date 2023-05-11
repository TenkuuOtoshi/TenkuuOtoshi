/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:14:31 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/02 15:02:01 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

class ClapTrap
{
	public :

					~ClapTrap();
					ClapTrap(std::string name);
					ClapTrap(const ClapTrap &a);
	ClapTrap&		operator = (const ClapTrap &a);

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		get_Name();
	int				get_Attack_damage();

	protected :

	std::string		_Name;
	int				_Hit_point;
	int				_Energy_points;
	int				_Attack_damage;

};