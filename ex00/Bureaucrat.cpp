/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:18:32 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/26 16:19:43 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Exception: The grade is too high for the range 1 to 150!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Exception: The grade is too low for the range 1 to 150!");
}

Bureaucrat::Bureaucrat(const std::string name): _name(name) {
	_grade = 150; // 150 is the default grade.
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(150) {
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {
	_grade = rhs._grade;
	return (*this);
}

const std::string	Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::promote(void) {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	_grade -= 1;
}

void	Bureaucrat::demote(void) {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	_grade += 1;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}
