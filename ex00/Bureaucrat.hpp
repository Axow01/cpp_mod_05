/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:10:31 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/26 15:10:33by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_BUREAUCRAT
# define HPP_BUREAUCRAT

# include <iostream>
# include <exception>

class Bureaucrat {
	public:
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &rhs);

		class GradeTooHighException: public std::exception {
			public:
				const char* what(void) const throw();
		};
		
		class GradeTooLowException: public std::exception {
			public:
				const char* what(void) const throw();
		};

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				promote(void);
		void				demote(void);
		void				setGrade(int grade);
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif
