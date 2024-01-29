/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:12 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/12 12:43:05 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		/*
		//	Orthodox Canonical Form
		*/
		Dog(void);
		Dog(const Dog& src);
		
		~Dog(void);

		Dog&	operator=(const Dog& rhs);

		/*
			Action Function
		*/
		virtual void makeSound(void) const;
};

#endif