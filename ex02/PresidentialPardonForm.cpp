/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:52:58 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 14:00:48 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy._name, copy._signRequiredGrade, copy._executeRequiredGrade), _target(copy._target) {
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_signed = rhs._signed;
	}
	return (*this);
}

const std::string	PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!_signed)
		throw SignedException();
	if (executor.getGrade() > _executeRequiredGrade)
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
