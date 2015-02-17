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
#ifndef _COMPLEX_H
#define _COMPLEX_H

class Complex {
  /**
   * Basic arithmetic operations for
   * complex numbers
   */
private:
  double a; //!< Real part
  double b; //!< Imaginary part
public:
  Complex(double a,double b);
  Complex square() const;
  double smagnitude() const;

  bool operator == (const Complex &c) const;
  Complex operator + (const Complex &c) const;
  Complex operator * (const Complex &c) const;
  Complex operator-() const;

  double getReal();
  double getImg();
};

#endif // _COMPLEX_H
