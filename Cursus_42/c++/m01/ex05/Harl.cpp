/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:30:38 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 14:07:00 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "harl.h"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f)(void);
	int		i;

	i = compare(level);
	switch(i)
	{
		case (0):
			f = &Harl::debug;
			(this->*f)();
			break;
		case (1):
			f = &Harl::info;
			(this->*f)();
			break;
		case (2):
			f = &Harl::warning;
			(this->*f)();
			break;
		case (3):
			f = &Harl::error;
			(this->*f)();
			break;
	}
	// if (level == "DEBUG")
	// 	this->debug();
	// if (level == "INFO")
	// 	this->info();
	// if (level == "WARNING")
	// 	this->warning();
	// if (level == "ERROR")
	// 	this->error();
}

int	Harl::compare(std::string level)
{
	std::string tab[4];
	int	i;

	i = 0;
	tab[0] = (std::string)"DEBUG";
	tab[1] = (std::string)"INFO";
	tab[2] = (std::string)"WARNING";
	tab[3] = (std::string)"ERROR";
	while (i < 4)
	{
		if (level.compare(tab[i]) == 0)
			return (i);
		i++;
	}
	return (5);
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nCommander :\nCrew, we are about to make a hyperspace jump. Please confirm that your stations are secure and the systems is fully ready." << std::endl;
	std::cout << std::endl;
	return ;
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]\nCommander :\nCrew, we need to perform a scan. Our last jump didn't go as smoothly as planned, and I want to make sure that there aren't any unexpected objects on the path and i want a full scan of the ship to check its integrity. Crew member 1 and 2, please take charge of the scan and report back with your findings." << std::endl;
	std::cout << std::endl;
	return ;
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nCrew member 1 :\nCommander, I've detected an unusual energy fluctuation in the ship's power grid. It's not causing any immediate problems." << std::endl;
	std::cout << std::endl;
	return ;
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nCrew member 2 :\nCommander, we have a critical problem. The hyperspace jump has caused a catastrophic failure in our engine. We're losing power and the engine is on the verge of exploding. We need to shut it down immediately to prevent any further damage." << std::endl;
	std::cout << std::endl;
	return ;
}
