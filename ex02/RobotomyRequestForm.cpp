/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:06:39 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 14:49:25 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy._name, copy._signRequiredGrade, copy._executeRequiredGrade), _target(copy._target) {
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return (*this);
}

const std::string	RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	static time_t	lastTime = time(NULL);

	if (!_signed)
		throw SignedException();
	if (executor.getGrade() > _executeRequiredGrade)
		throw GradeTooLowException();

	std::cout << "...Drilling noises..." << std::endl;
	while (time(NULL) == lastTime)
		srand(time(NULL));
	int	randomNumber = std::rand();
	lastTime = time(NULL);

	if (randomNumber % 2 == 1)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
		std::cout << _target << " has failled to robotomized, try again!" << std::endl;
}
