/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:10 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/26 16:17:53 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat bob("bob", 150);

		bob.promote();
		std::cout << bob << std::endl;
		while (true) {
			bob.promote();
			std::cout << bob << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
