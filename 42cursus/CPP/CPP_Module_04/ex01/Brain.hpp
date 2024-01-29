/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:12 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 17:58:15 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class	Brain
{
	private:
		std::string _ideas[100];

	public:
		/*
		//	Orthodox Canonical Form
		*/
		Brain(void);
		Brain(const Brain& src);
		
		~Brain(void);

		Brain&	operator=(const Brain& rhs);

		/*
		//	Get Attributes Function
		*/
		std::string		getIdeas(int i) const;
		
		/*
		//	Set Attributes Function
		*/
		void			setIdeas(std::string ideas, int i);
};

#endif