/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:14:31 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/11 13:54:13 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

class ClapTrap
{
	public :

					ClapTrap(std::string name);
					ClapTrap(const ClapTrap &a);
	ClapTrap&		operator = (const ClapTrap &a);
					~ClapTrap();

	void			attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		get_Name();
	int				get_Attack_damage();

	private :

	std::string		_Name;
	int				_Hit_point;
	int				_Energy_points;
	int				_Attack_damage;

};