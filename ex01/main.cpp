/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:10 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/26 17:31:57 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat bob("bob", 150);
		Form		ss("Some random contract", 40, 40);
		Form		dd("Super Cool Form", 150, 150);

		bob.promote();
		std::cout << bob << std::endl;
		std::cout << ss << std::endl;
		std::cout << dd << std::endl;
		bob.signForm(dd);
		bob.signForm(ss);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
