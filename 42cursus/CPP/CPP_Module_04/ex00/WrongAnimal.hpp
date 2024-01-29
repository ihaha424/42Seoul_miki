/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:27:09 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 14:53:43 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string _type;
	public:
		/*
		//	Orthodox Canonical Form
		*/
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& src);
		
		~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& rhs);

		/*
		//	Get Attributes Function
		*/
		const std::string	getType(void) const;

		/*
			Action Function
		*/
		void makeSound(void) const;
};

#endif