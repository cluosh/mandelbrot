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
#include <SDL2/SDL_image.h>
#include "Display.hxx"

/**
 * Initialize SDL Systems
 *
 * @param width Screen width
 * @param height Screen height
 */
Display::Display(int width, int height) {
  this->w = width;
  this->h = height;
}

/**
 * Draw a map of color values
 */
void Display::saveMap(ColorVals* cvals, const char* file) {
  // Convert pixels to SDL-Surface
  SDL_Surface* s = SDL_CreateRGBSurfaceFrom(cvals,
					    this->w,this->h,
					    24,3*this->w,
					    0x0000ff,
					    0x00ff00,
					    0xff0000,
					    0x000000);
  IMG_SavePNG(s,file);
}
