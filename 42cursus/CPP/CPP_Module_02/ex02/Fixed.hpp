/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:37 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/29 14:35:39 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_FixedPoint;
		static const int	_FracticalBit = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		
		~Fixed(void);

		bool operator > (const Fixed& rhs) const;
		bool operator < (const Fixed& rhs) const;
		bool operator >= (const Fixed& rhs) const;
		bool operator <= (const Fixed& rhs) const;
		bool operator == (const Fixed& rhs) const;
		bool operator != (const Fixed& rhs) const;
		
		Fixed& operator = (const Fixed& rhs);
		Fixed operator + (const Fixed& rhs) const;
		Fixed operator - (const Fixed& rhs) const;
		Fixed operator * (const Fixed& rhs) const;
		Fixed operator / (const Fixed& rhs) const;
		
		Fixed& operator ++ (void);
		Fixed operator ++ (int);
		Fixed& operator -- (void);
		Fixed operator -- (int);
				
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		
		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
};

std::ostream& operator << (std::ostream& out, const Fixed& rhs);

#endif