/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:10 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 14:02:51 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	try {
		Bureaucrat				bob("bob", 1);
		ShrubberyCreationForm	formHouse("House");
		ShrubberyCreationForm	anotherOne("DJ Khaled's house");
		RobotomyRequestForm		jean("Jean");
		PresidentialPardonForm	pablo("Pablo Escobar");

		formHouse.beSigned(bob);
		bob.executeForm(formHouse);
		formHouse.execute(bob);
		bob.executeForm(anotherOne);
		bob.executeForm(jean);
		bob.signAForm(jean);
		for (int i = 0; i < 10; i++)
			bob.executeForm(jean);
		bob.executeForm(pablo);
		bob.signAForm(pablo);
		bob.executeForm(pablo);
		std::cout << bob << std::endl;
		std::cout << formHouse << std::endl;
		std::cout << anotherOne << std::endl;
		std::cout << jean << std::endl;
		std::cout << pablo << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
