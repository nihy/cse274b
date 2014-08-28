/*
 * rectangle.cpp
 *
 *  Created on: Aug 28, 2014
 *      Author: nihy
 */

#include "rectangle.h"

int Rectangle::area() {
	return width*height;
}

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}


