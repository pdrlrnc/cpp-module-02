/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:24:55 by pedde-so          #+#    #+#             */
/*   Updated: 2026/03/19 10:25:00 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point& other);
		Point& operator=(const Point& other);


		const Fixed getX(void) const;
		const Fixed getY(void) const;
	private:
		const Fixed _x;
		const Fixed _y;
};

std::ostream& operator<<(std::ostream& stream, const Point& point);

#endif
