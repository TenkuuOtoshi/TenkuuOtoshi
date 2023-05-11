/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:19:19 by tlarraze          #+#    #+#             */
/*   Updated: 2023/05/11 13:49:14 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "m04.h"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();

	std::cout << j->get_type() << " " << std::endl;
	j->makeSound();
	meta->makeSound();

}