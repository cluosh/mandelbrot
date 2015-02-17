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
#include <iostream>
#include <sstream>
#include "Display.hxx"
#include "Mandelbrot.hxx"

int main(int argc, char* argv[]) {
  // Check if arguments are valid
  if(argc != 5) {
    std::cout <<
      "Usage: ./mandelbrot width height iterations file\n";
  }

  // Convert arguments
  int width = 640, height = 480, iterations = 10;
  std::istringstream is(argv[1]);
  is >> width;
  is.clear();
  is.str(argv[2]);
  is >> height;
  is.clear();
  is.str(argv[3]);
  is >> iterations;
  
  // Create display manager
  Display d(width,height);
  
  // Create and draw mandelbrot set
  Mandelbrot m(width,height,4);
  m.iterate(iterations);
  auto cm = m.getColorMap();
  d.saveMap(cm,argv[4]);

  std::cout << "Mandelbrot generated: " << argv[4] << "\n";
  return 0;
}
