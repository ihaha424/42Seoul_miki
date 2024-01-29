/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:12 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 18:53:46 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class	Animal
{
	protected:
		std::string _type;

	public:
		/*
		//	Orthodox Canonical Form
		*/
		Animal(void);
		Animal(const Animal& src);
		
		virtual ~Animal(void);

		Animal&	operator=(const Animal& rhs);

		/*
		//	Get Attributes Function
		*/
		const std::string	getType(void) const;

		/*
			Action Function
		*/
		virtual void makeSound(void) const;
};

#endif