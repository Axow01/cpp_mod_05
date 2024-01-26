/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
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
		throw Form::GradeTooHighException();
	else if (i > rangeEnd)
		throw Form::GradeTooLowException();
	return (true);
}

const char	*Form::GradeTooHighException::what(void) const throw() {
	return ("Exception: Form grade too high, for range 1 to 150!");
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return ("Exception: Form grade too low, for range 1 to 150!");
}

std::ostream	&operator<<(std::ostream &os, const Form &rhs) {
	os << "Form " << rhs.getName() << " signed: " << rhs.isSigned() << ", grade " << rhs.getSignRequiredGrade() << " required to sign and grade " << rhs.getExecuteRequiredGrade() << " required to execute.";
	return (os);
}

Form::Form(std::string name): _name(name), _signed(false), _signRequiredGrade(150), _executeRequiredGrade(150) {}

Form::Form(std::string name, int signRequiredGrade, int executeRequiredGrade): _name(name), _signed(false), _signRequiredGrade(signRequiredGrade), _executeRequiredGrade(executeRequiredGrade) {
	isInRange(signRequiredGrade, 1, 150);
	isInRange(executeRequiredGrade, 1, 150);
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed), _signRequiredGrade(copy._signRequiredGrade), _executeRequiredGrade(copy._executeRequiredGrade) {
	*this = copy;
}

Form::~Form(void) {}

Form	&Form::operator=(const Form &rhs) {
	_signed = rhs._signed;
	return (*this);
}

bool	Form::isSigned(void) const {
	return (_signed);
}

const std::string	Form::getName(void) const {
	return (_name);
}

int	Form::getSignRequiredGrade(void) const {
	return (_signRequiredGrade);
}

int	Form::getExecuteRequiredGrade(void) const {
	return (_executeRequiredGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _signRequiredGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}
