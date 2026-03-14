/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:46:49 by pedde-so          #+#    #+#             */
/*   Updated: 2026/03/12 12:46:50 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed&other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int other) : _rawBits(other << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}
/**
 * Imagine _rawBits as:
 * [ 24 bits for whole part | 8 bits for fraction ]
 *
 * Basically, the whole trick is just to multiply by 256 to store, divide 256 to read. the _rawBits
 * integer is just carrying both the whole and the fractional parts squeezed together.
 * example: 
 * 	3.75 * 256 = 960 -> _rawBits stores it as 960
 *	960 / 256 = 3.75 -> back again :D
 */
Fixed::Fixed(const float other) : _rawBits(roundf(other * (1 <<_fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	return _rawBits;
}

void Fixed::setRawBits(int const rawBits)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = rawBits;
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return stream;
}
