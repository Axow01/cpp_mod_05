/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:10:28 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 12:32:11 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_SHRUBERRY
# define HPP_SHRUBERRY

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator==(const ShrubberyCreationForm &rhs);

		void	execute(Bureaucrat const &executor) const;
	private:
		std::string	_target;
};

#endif

