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
#include "Complex.hxx"

/**
 * Constructor
 * 
 * @param a real part
 * @param b imaginary part
 */
Complex::Complex(double a,double b) {
  this->a = a;
  this->b = b;
}

/**
 * Square a complex number
 * 
 * @return squared complex number
 */
Complex Complex::square() const {
  return (*this)*(*this);
}

/**
 * Squared magnitude of a complex number
 *
 * @return magintude squared
 */
double Complex::smagnitude() const {
  return this->a*this->a+this->b*this->b;
}

/**
 * Equals-operator
 *
 * @param c complex number
 * @return true, if complex numbers are equal
 */
bool Complex::operator == (const Complex &c) const {
  return (c.a == this->a && c.b == this->b);
}

/**
 * Addition-operator
 *
 * @param c complex number
 * @return sum of current number and parameter
 */
Complex Complex::operator + (const Complex &c) const {
  return Complex(this->a+c.a,this->b+c.b);
}

/**
 * Multiplication-operator
 *
 * @param c complex number
 * @return complex number multiplied with parameter
 */
Complex Complex::operator * (const Complex &c) const {
  return Complex(this->a*c.a-this->b*c.b,
		 this->a*c.b+this->b*c.a);
}

/**
 * Unary minus operator
 *
 * @param c complex number
 * @return negated complex number
 */
Complex Complex::operator - () const {
  return Complex(-this->a,-this->b);
}

/**
 * Real part
 *
 * @return real part of complex number
 */
double Complex::getReal() {
  return a;
}

/**
 * Imaginary part
 * 
 * @return imaginary part of complex number
 */
double Complex::getImg() {
  return b;
}
