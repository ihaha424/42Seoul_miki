/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:32:48 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/09 20:22:26 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : _FixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _FixedPoint(num << _FracticalBit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _FixedPoint(roundf(num * (1 << _FracticalBit)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &rhs)
		this->_FixedPoint = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_FixedPoint;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_FixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_FixedPoint / (float)(1 << _FracticalBit));
}

int		Fixed::toInt(void) const
{
	return (this->_FixedPoint >> _FracticalBit);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return out;
}