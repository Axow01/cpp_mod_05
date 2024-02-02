/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:10 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 15:30:47 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	try {
		Intern		jack;
		Bureaucrat	robert("Robert", 1);
		AForm		*formOne = jack.makeForm("presidential pardon", "Pablo Escobar");
		AForm		*formTwo = jack.makeForm("robotomy request", "Bender");
		AForm		*formThree = jack.makeForm("shrubbery creation", "Bender's house");
		AForm		*formFour = jack.makeForm("employement contract", "Fry");
		
		std::cout << formFour << std::endl;
		robert.signAForm(*formOne);
		robert.signAForm(*formTwo);
		robert.signAForm(*formThree);
		robert.executeForm(*formOne);
		robert.executeForm(*formTwo);
		robert.executeForm(*formThree);
		delete formOne;
		delete formTwo;
		delete formThree;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
