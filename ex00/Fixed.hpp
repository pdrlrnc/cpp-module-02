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

/*
 * Orthodox Canonical Form (OCF)
 * It consists of these four things, all present in this class:
 * Fixed(); — default constructor
 * Fixed(const Fixed& other); — copy constructor
 * Fixed& operator=(const Fixed& other); — copy assignment operator
 * ~Fixed(); — destructor
 *
 * It is required because if the class manages any resource (memory, file handles,
 * etc.) you need to explicitly define all four - otherwise the compiler will generate
 * them for you, which might be wrong (lime a shallow copy when you need a deep copy).
 */

class Fixed
{
	public:
		/*
		 * The constructor receives a reference to the original Fixed 
		 * object rather than a copy of it. 
		 */
		Fixed(const Fixed& other);
		/*
		 * Fixed& as the return type — the assignment operator returns a reference 
		 * to the current object (i.e. *this). This is what allows chaining 
		 * like a = b = c; to work.
		 */
		Fixed& operator=(const Fixed&other);
		~Fixed();
		Fixed();
		/*
		 * const here (after the parentheses) means the method promises not to 
		 * modify the object. It can be called on const Fixed instances. The 
		 * compiler will enforce this — if you try to modify _rawBits inside
		 * that method, it won't compile.
		 */
		int getRawBits() const;
		void setRawBits(int const rawBits);

	private:
		/*
		 * static — there's only one copy of this variable shared across all 
		 * instances of the class. It belongs to the class itself, not to any
		 * particular object. Every Fixed object reads the same _fractionalBits.
		 *
		 * const — the value cannot be changed after initialization. Combined
		 * with static, this makes it essentially a class-level constant.
		*/
		static const int _fractionalBits = 8;
		int _rawBits;
};

#endif
