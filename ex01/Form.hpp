/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:40:23 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/26 17:38:15 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_FORM
# define HPP_FORM

class Bureaucrat;
# include "Bureaucrat.hpp"

class Form {
	public:
		Form(std::string name);
		Form(std::string name, int signRequiredGrade, int executeRequiredGrade);
		Form(const Form &copy);
		~Form(void);

		Form	&operator=(const Form &rhs);

		class GradeTooHighException: public std::exception {
			const char	*what(void) const throw();
		};
		
		class GradeTooLowException: public std::exception {
			const char	*what(void) const throw();
		};

		void				beSigned(const Bureaucrat &bureaucrat);
		bool				isSigned(void) const;
		const std::string	getName(void) const;
		int					getSignRequiredGrade(void) const;
		int					getExecuteRequiredGrade(void) const;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signRequiredGrade;
		const int			_executeRequiredGrade;
};

std::ostream	&operator<<(std::ostream &os, const Form &rhs);

#endif
