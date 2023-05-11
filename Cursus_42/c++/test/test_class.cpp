/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:54:39 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/28 14:22:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test.hpp"

test_class::test_class(void) {

	std::cout << "Constructor called" << std::endl;
	return ;
}
test_class::~test_class(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}