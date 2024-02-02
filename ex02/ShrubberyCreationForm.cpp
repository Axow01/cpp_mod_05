/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:10:28 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/01 17:33:46 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), _target(target) {
	std::cout << _name << " initialized!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy._name, copy._signRequiredGrade, copy._executeRequiredGrade), _target(copy._target) {
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << _name << " deleted!" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator==(const ShrubberyCreationForm &rhs) {
	_signed = rhs._signed;
	_target = rhs._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::fstream	file;
	std::string		fileName = _target + "_shrubbery";

	if (!_signed)
		throw SignedException();
	else if (executor.getGrade() > _executeRequiredGrade)
		throw GradeTooLowException();
	file.open(fileName, std::fstream::out);
	if (file.bad()) {
		file.close();
		throw FileFailledException();
	}
	for (int i = 0; i < 25; i++)
		file << "     _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\" << std::endl;
	file.close();
}
