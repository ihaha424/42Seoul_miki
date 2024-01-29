/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:12 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 18:35:44 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	_brain;
		
	public:
		/*
		//	Orthodox Canonical Form
		*/
		Cat(void);
		Cat(const Cat& src);
		
		~Cat(void);

		Cat&	operator=(const Cat& rhs);

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