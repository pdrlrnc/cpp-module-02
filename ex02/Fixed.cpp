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
}

Fixed::Fixed(const Fixed&other)
{
	*this = other;
}

Fixed::Fixed(const int other) : _rawBits(other << _fractionalBits)
{
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
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

Fixed& Fixed::operator+(const Fixed& other)
{
	if (this != &other)
		_rawBits += other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& other)
{
	if (this != &other)
		return _rawBits > other.getRawBits();
	return false;
}

bool Fixed::operator<(const Fixed& other)
{
	if (this != &other)
		return _rawBits < other.getRawBits();
	return false;
}

bool Fixed::operator>=(const Fixed& other)
{
	if (this != &other)
		return _rawBits >= other.getRawBits();
	return true;
}

bool Fixed::operator<=(const Fixed& other)
{
	if (this != &other)
		return _rawBits <= other.getRawBits();
	return true;
}

bool Fixed::operator==(const Fixed& other)
{
	if (this != &other)
		return _rawBits == other.getRawBits();
	return true;
}

bool Fixed::operator!=(const Fixed& other)
{
	if (this != &other)
		return _rawBits != other.getRawBits();
	return false;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}


Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
	{
		std::cerr << "Dividing by zero is a no-no." << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int dummy)
{
	(void)dummy;
	Fixed aux(*this);
	_rawBits++;
	return aux;
}

Fixed& Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int dummy)
{
	(void)dummy;
	Fixed aux(*this);
	_rawBits--;
	return aux;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return first;
	return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return first;
	return second;
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
		return first;
	return second;
}


const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first < second)
		return first;
	return second;
}

int Fixed::getRawBits() const
{
	return _rawBits;
}

void Fixed::setRawBits(int const rawBits)
{
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
