/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:21:13 by pedde-so          #+#    #+#             */
/*   Updated: 2026/03/12 12:21:14 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(const int other);
		Fixed(const float other);
		Fixed(const Fixed& other);
		Fixed();
		~Fixed();

		bool operator>(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);

		Fixed& operator+(const Fixed& other) const;
		Fixed& operator-(const Fixed& other) const;
		Fixed& operator*(const Fixed& other) const;
		Fixed& operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed operator++(int dummy);
		Fixed& operator--();
		Fixed operator--(int dummy);
		
		int getRawBits() const;
		void setRawBits(int const rawBits);
		float toFloat(void) const;
		int toInt(void) const;

		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);

	private:
		static const int _fractionalBits = 8;
		int _rawBits;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
