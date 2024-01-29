/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:12 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 18:48:20 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain*	_brain;
		
	public:
		/*
		//	Orthodox Canonical Form
		*/
		Dog(void);
		Dog(const Dog& src);
		
		~Dog(void);

		Dog&	operator=(const Dog& rhs);

		/*
		//	Get Attributes Function
		*/
		std::string		getBrainIdeas(int i) const;

		/*
		//	Set Attributes Function
		*/
		void		setBrainIdeas(std::string ideas, int i);
		

		/*
			Action Function
		*/
		virtual void makeSound(void) const;
};

#endif