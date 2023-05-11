/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:17:05 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/05 17:26:20 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "m04.h"

class Animal
{
	public :

					Animal();
					~Animal();
					Animal(const Animal &a);
	Animal&			operator = (const Animal &a);

	virtual void	makeSound(void) const;
	std::string		get_type(void) const;
	void			set_type(std::string type);

	protected :

	std::string		type;
};