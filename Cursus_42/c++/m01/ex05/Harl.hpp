/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:30:29 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/13 13:58:17 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "harl.h"

class Harl
{
	public:

			Harl(void);
			~Harl(void);
	void	complain(std::string level);

	private:

	int		compare(std::string level);
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

};
