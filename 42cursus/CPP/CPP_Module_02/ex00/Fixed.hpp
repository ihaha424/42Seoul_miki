/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:37 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/09 19:32:50 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class	Fixed
{
	private:
		int					_FixedPoint;
		static const int	_FracticalBit = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& obj);
		Fixed& operator = (const Fixed& obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif