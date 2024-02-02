/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:57:00 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/02 15:21:31 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_INTERN
# define HPP_INTERN

# include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);

		Intern	&operator=(const Intern &rhs);

		AForm	*makeForm(const std::string &formName, const std::string &target) const;
	private:
};

#endif
