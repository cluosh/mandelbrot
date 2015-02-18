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
#include "Mandelbrot.hxx"

/**
 * Constructor
 *
 * @param width screen width
 * @param height screen height
 * @param max_squared maximum squared magnitude
 */
Mandelbrot::Mandelbrot(int width, int height,
		       double max_squared) {
  this->width = width;
  this->height = height;
  this->max_squared = max_squared;
  this->total_iterations = 0;

  // Convert pixels to complex numbers
  for(int y = 0; y < this->height; y++) {
    for(int x = 0; x < this->width; x++) {
      this->values.push_back({0,Complex(0,0),
	    complexFromPixel(x,y)});
    }
  }
}

/**
 * Get the complex number for a pixel
 *
 * @param x x-coordinate
 * @param y y-coordinate
 * @return complex number
 */
Complex Mandelbrot::complexFromPixel(int x,int y) {
  double real = (x/(double) this->width) * 3 - 2;
  double img = (y/(double) this->height) * 2.5 - 1.25;
  Complex c(real,img);
  return c;
}

/**
 * Calculate one iteration of the
 * 
 * @param n number of iterations
 */
void Mandelbrot::iterate(int n) {
  #pragma omp parallel for
  for(auto it = this->values.begin();
      it < this->values.end(); it++) {
    // Only proceed if number isn't out of
    // the set yet
    if(it->iterations == this->total_iterations) {
      // Iterate n times
      for(int i = 0; i < n &&
	    it->current.smagnitude() <= max_squared; i++) {
	// f(z) = z^2 + c
	it->current = it->current.square() + it->initial;
	it->iterations++;
      }
    }
  }
  total_iterations += n;
}

/**
 * Return coloured iteration values
 *
 * @return vector with color values
 */
ColorVals* Mandelbrot::getColorMap() {
  ColorVals *r = new ColorVals[this->values.size()];
  int counter = 0;
  #pragma omp parallel for
  for(auto it = this->values.begin();
      it < this->values.end(); it++) {
    if(it->iterations == this->total_iterations) {
      // pixel is in set
      r[counter] = {0,0,0};
    } else {
      // pixel is not in set, calculate color
      double rel = it->iterations/
	(double) this->total_iterations;
      r[counter] = {150,(uint8_t) (255*rel),0};
    }
    counter++;
  }
  return r;
}
