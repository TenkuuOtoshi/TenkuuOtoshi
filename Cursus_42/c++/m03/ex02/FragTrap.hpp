/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:21:35 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/03 16:30:27 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

class	FragTrap : public ClapTrap
{
	public :

					~FragTrap();
					FragTrap(std::string name);
					FragTrap(const FragTrap &a);
	FragTrap&		operator = (const FragTrap &a);

	void			highFivesGuys(void);
	void			attack(const std::string& target);

};