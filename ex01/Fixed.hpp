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
		Fixed& operator=(const Fixed&other);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const rawBits);
		float toFloat(void) const;
		int toInt(void) const;
		
	private:
		static const int _fractionalBits = 8;
		int _rawBits;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
