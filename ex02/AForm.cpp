/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:51:27 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/26 17:31:35 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static bool	isInRange(int i, int rangeStart, int rangeEnd) {
	if (i < rangeStart)
		throw AForm::GradeTooHighException();
	else if (i > rangeEnd)
		throw AForm::GradeTooLowException();
	return (true);
}

const char	*AForm::GradeTooHighException::what(void) const throw() {
	return ("Exception: AForm grade too high, for range 1 to 150!");
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return ("Exception: AForm grade too low, for range 1 to 150!");
}

const char	*AForm::SignedException::what(void) const throw() {
	return ("Exception: AForm needs to be signed before executing.");
}

const char	*AForm::FileFailledException::what(void) const throw() {
	return ("Exception: File creation failled.");
}

std::ostream	&operator<<(std::ostream &os, const AForm &rhs) {
	os << "AForm " << rhs.getName() << " signed: " << rhs.isSigned() << ", grade " << rhs.getSignRequiredGrade() << " required to sign and grade " << rhs.getExecuteRequiredGrade() << " required to execute.";
	return (os);
}

AForm::AForm(std::string name): _name(name), _signed(false), _signRequiredGrade(150), _executeRequiredGrade(150) {}

AForm::AForm(std::string name, int signRequiredGrade, int executeRequiredGrade): _name(name), _signed(false), _signRequiredGrade(signRequiredGrade), _executeRequiredGrade(executeRequiredGrade) {
	isInRange(signRequiredGrade, 1, 150);
	isInRange(executeRequiredGrade, 1, 150);
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(copy._signed), _signRequiredGrade(copy._signRequiredGrade), _executeRequiredGrade(copy._executeRequiredGrade) {
	*this = copy;
}

AForm::~AForm(void) {}

AForm	&AForm::operator=(const AForm &rhs) {
	_signed = rhs._signed;
	return (*this);
}

bool	AForm::isSigned(void) const {
	return (_signed);
}

const std::string	AForm::getName(void) const {
	return (_name);
}

int	AForm::getSignRequiredGrade(void) const {
	return (_signRequiredGrade);
}

int	AForm::getExecuteRequiredGrade(void) const {
	return (_executeRequiredGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _signRequiredGrade)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}
