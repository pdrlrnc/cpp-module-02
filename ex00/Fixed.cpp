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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	/*
	 * for a = b
	 * this - is a pointer to the current object, so a
	 * other - is a reference to the right-hand side object
	 * &other - takes the address ofother, giving you a pointer to b
	 * 
	 * basially just checking if a and b are the same object
	 */
	if (this != &other)
		_rawBits = other.getRawBits();
	/*
	 * this is a pointer, so returning this would return a pointer (Fixed*)
	 * But the return type is Fixed& — a reference
	 * So you dereference it with *this to get the actual object, and C++ 
	 * automatically treats the return as a reference
	 */
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const rawBits)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = rawBits;
}
