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

#include "Point.hpp"

//can't assing _x = other.getX() in the body since _x and _y are both const
//I am therefore required to use initializer list
Point::Point(const Point& other) : _x(other.getX()), _y(other.getY())
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point() : _x(0.0f), _y(0.0f)
{
}

Point::~Point()
{
}

const Fixed Point::getX(void) const
{
	return _x;
}

const Fixed Point::getY(void) const
{
	return _y;
}

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
	stream << "(";
	stream << point.getX().toFloat();
	stream << ",";
	stream << point.getY().toFloat();
	stream << ")";
	return stream;
}
