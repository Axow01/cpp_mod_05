/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:40:23 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/01 15:59:30 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_AForm
# define HPP_AForm

class Bureaucrat;
# include "Bureaucrat.hpp"

class AForm {
	public:
		AForm(std::string name);
		AForm(std::string name, int signRequiredGrade, int executeRequiredGrade);
		AForm(const AForm &copy);
		virtual ~AForm(void);

		AForm	&operator=(const AForm &rhs);

		class GradeTooHighException: public std::exception {
			const char	*what(void) const throw();
		};
		
		class GradeTooLowException: public std::exception {
			const char	*what(void) const throw();
		};
		
		class SignedException: public std::exception {
			const char	*what(void) const throw();
		};
		
		class FileFailledException: public std::exception {
			const char	*what(void) const throw();
		};

		void				beSigned(const Bureaucrat &bureaucrat);
		bool				isSigned(void) const;
		const std::string	getName(void) const;
		int					getSignRequiredGrade(void) const;
		int					getExecuteRequiredGrade(void) const;
		virtual void	execute(Bureaucrat const &executor) const = 0;
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_signRequiredGrade;
		const int			_executeRequiredGrade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &rhs);

#endif
