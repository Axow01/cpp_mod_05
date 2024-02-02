/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:57:30 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 15:31:25 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern::~Intern(void) {}

Intern	&Intern::operator=(const Intern &rhs) {
	(void) rhs;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) const {
	const std::string	formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int					selected = 3;

	for (int i = 0; i < 3; i++) {
		if (formTypes[i] == formName) {
			selected = i;
			break;
		}
	}
	switch (selected) {
		case 0:
			std::cout << "Intern creates Shrubbery Creation Form." << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates Robotomy Request Form." << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates Presidential Pardon Form." << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Intern failled to create form: " << formName << std::endl;
			return (NULL);
	}
}
