/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:50:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/04/12 17:40:16 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "sed.h"

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		buff;
	std::string		str_del;
	std::string		str_add;
	std::size_t		pos;

	if (ft_check_arg(argc, argv) == false)
		return (1);
	buff = argv[1];
	ifs.open(argv[1]);
	ofs.open(buff.append(".replace").c_str());
	str_del = argv[2];
	str_add = argv[3];
	std::getline(ifs, buff, '\0');
	while (buff.find(str_del) != std::string::npos && str_del.length() != 0)
	{
		pos = buff.find(str_del);
		buff.erase(pos, str_del.length());
		buff.insert(pos, str_add);
		ofs << buff.substr(0, pos + str_add.length());
		buff = buff.erase(0, pos + str_add.length());
	}
	ofs << buff;
	
}

bool	ft_check_arg(int argc, char **argv)
{
	std::ifstream	ifs;
	int				error;

	error = 0;
	if (argc != 4)
	{
		std::cout << "Error\nInvalid number of parameter" << std::endl;
		error++;
	}
	if (argv[1])
	{
		ifs.open(argv[1]);
		if (!ifs)
		{
			if (error == 0)
				std::cout << "Error\nFile \"" << argv[1] << "\" dont exist" << std::endl;
			else
				std::cout << "File \"" << argv[1] << "\" dont exist" << std::endl;
			error++;
		}
		if (argv[2] && argv[2][0] == '\0')
		{
			if (error == 0)
				std::cout << "Error\nEmpty string to replace are not valid" << std::endl;
			if (error > 0)
				std::cout << "Empty string to replace are not valid" << std::endl;
			error++;
		}
	}
	if (error > 0)
		return (false);
	return (true);
}