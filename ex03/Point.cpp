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

void Point::addXAndY(const float x, const float y)
{
	_x = _x + Fixed(x);
	_y = _y + Fixed(y);
}

Point::Point(const Point& other)
{
	*this = other;
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

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		_x = other.getX();
		_y = other.getY();
	}
	return *this;
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
	stream << point.getX().toFloat();
	stream << " ";
	stream << point.getY().toFloat();
	return stream;
}
