/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:27:03 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 14:55:52 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		/*
		//	Orthodox Canonical Form
		*/
		WrongCat(void);
		WrongCat(const WrongCat& src);
		
		~WrongCat(void);

		WrongCat&	operator=(const WrongCat& rhs);

		/*
			Action Function
		*/
		void makeSound(void) const;
};

#endif