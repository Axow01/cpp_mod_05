/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:10 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/01 17:34:23 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat bob("bob", 150);
		AForm		ss("Some random contract", 40, 40);
		AForm		dd("Super Cool AForm", 150, 150);

		bob.promote();
		std::cout << bob << std::endl;
		std::cout << ss << std::endl;
		std::cout << dd << std::endl;
		bob.signAForm(dd);
		bob.signAForm(ss);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
