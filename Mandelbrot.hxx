/*
 * Mandelbrot fractal generator
 * Copyright (C) 2015 Michael Pucher(@cluosh)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _MANDELBROT_H
#define _MANDELBROT_H

#include <vector>
#include "common.hxx"

class Mandelbrot {
  /**
   * Creating/saving a Mandelbrot set
   */
private:
  std::vector<ValueSet> values; //!< Container for iteration values
  int width;                    //!< Screen width
  int height;                   //!< Screen height
  double max_squared;           //!< Maximum squared magnitude
  int total_iterations;         //!< Number of total iterations
public:
  Mandelbrot(int width,int height,double max_squared);
  Complex complexFromPixel(int x,int y);
  void iterate(int num);
  ColorVals* getColorMap();
};

#endif // _MANDELBROT_H
