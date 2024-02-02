/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:58:32 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 13:22:59 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_ROBOTOMY
# define HPP_ROBOTOMY

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

		const std::string	getTarget(void) const;
		void	execute(const Bureaucrat &executor) const;
	private:
		const std::string	_target;
};

#endif
