/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:12 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/12 12:53:11 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		/*
		//	Orthodox Canonical Form
		*/
		Cat(void);
		Cat(const Cat& src);
		
		~Cat(void);

		Cat&	operator=(const Cat& rhs);

		/*
			Action Function
		*/
		virtual void makeSound(void) const;
};

#endif