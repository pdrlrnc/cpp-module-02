/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:12:21 by pedde-so          #+#    #+#             */
/*   Updated: 2026/03/20 11:12:26 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

/*prototypes*/
bool bsp(Point a, Point b, Point c, Point point);

int main(void)
{
	Point a = Point(0.0, 0.0);
	Point b = Point(0.0, 5.0);
	Point c = Point(2.5, 2.5);
	
	Point belovedPoint = Point(0.5, 1.0);

	if (bsp(a, b, c, belovedPoint))
		std::cout << "The point " << belovedPoint << " is inside the triangle" << std::endl;
	else
		std::cout << "The point " << belovedPoint <<" is NOT inside the triangle" << std::endl;
	
	Point belovedPoint2 = Point(3.6, 5.3);

	if (bsp(a, b, c, belovedPoint2))
		std::cout << "The point " << belovedPoint2 << " is inside the triangle" << std::endl;
	else
		std::cout << "The point " << belovedPoint2 << " is NOT inside the triangle" << std::endl;

	return 0;
}


