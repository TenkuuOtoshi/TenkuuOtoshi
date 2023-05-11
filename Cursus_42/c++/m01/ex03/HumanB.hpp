/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:11:44 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 14:17:14 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.h"

class HumanB
{
	public:

					HumanB(std::string name);
					~HumanB();
		void		attack();
		void		setWeapon(Weapon& weapon);
		void		delWeapon();
		std::string	get_name();

	private:

		std::string _name;
		Weapon		*_weapon;

};
