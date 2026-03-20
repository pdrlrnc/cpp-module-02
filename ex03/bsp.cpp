/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:51:20 by pedde-so          #+#    #+#             */
/*   Updated: 2026/03/19 10:52:00 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float aBEdge;
	float bCEdge;
	float cAEdge;

	aBEdge = (b.getX().toFloat() - a.getX().toFloat()) * (point.getY().toFloat() - a.getY().toFloat())
		- (b.getY().toFloat() - a.getY().toFloat()) * (point.getX().toFloat() - a.getX().toFloat());
	bCEdge = (c.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - b.getY().toFloat())
		- (c.getY().toFloat() - b.getY().toFloat()) * (point.getX().toFloat() - b.getX().toFloat());
	cAEdge = (a.getX().toFloat() - c.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat())
		- (a.getY().toFloat() - c.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat());
	return ((aBEdge > 0 && bCEdge > 0 && cAEdge > 0) ||
			(aBEdge < 0 && bCEdge < 0 && cAEdge < 0));
}
