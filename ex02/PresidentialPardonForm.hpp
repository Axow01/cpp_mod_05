/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:49:26 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 13:52:46 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_PRESIDENTIAL
# define HPP_PRESIDENTIAL

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

		const std::string	getTarget(void) const;
		void				execute(const Bureaucrat &executor) const;
	private:
		const std::string	_target;
};

#endif
