/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:17:05 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/05 17:26:34 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "m04.h"

class Dog : public Animal
{
	public :

					Dog();
					~Dog();
					Dog(const Dog &a);
	Dog&			operator = (const Dog &a);

   	virtual void	makeSound(void) const;

	protected :

	std::string		type;
};