/**
 * @brief Operations on Rational numbers
 * @file rational.cpp
 *
 * Based on Deitel & Detitel but modified significantly
 * a Rational object holds one Rational number, one fraction
 *
 * Serves as an example of how to document code
 *
 * TIP: All files must have file documentation
 * TIP: All functions must have function documentation in .h and .cpp
 * TIP: All files must have your name. It is your work
 * TIP: All file names are lowercase (for compatibility)
 * TIP: All class names start with a Capital letter
 * @author Yusuf Pisan
 * @date 7 Dec 2018
 */


// TIP: System libraries before user written ones
#include <iostream>
#include "rational.h"


// TIP: Use initialization list for constructors when possible
// TIP: If parameter name is same as class variable, use classname::variable

/**
 * Default constructor
 * Parameters are numerator and denominator respectively.
 * Takes zero, one, two parameters. Parameters have default values of 0, 1.
 * @param numerator
 * @param denominator
 */
Rational::Rational(int numerator, int denominator) {
  cout << "Creating rational with " << numerator
       << " and " << denominator << endl;
  Rational::numerator = denominator < 0 ? -numerator : numerator;
  Rational::denominator = denominator < 0 ? -denominator : denominator;
  reduce();
}

// get numerator
int Rational::getNumerator() const {
  return numerator;
}

// get denominator
int Rational::getDenominator() const {
  return denominator;
}

// Conversion function, explicitly convert Rational to an int
Rational::operator int() const {
  cout << "Inside int() with numerator = " << numerator
       << " and denom = " << denominator << endl;
  return numerator / denominator;
}

// TIP: Use list initialization for variables when possible
// https://stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives

// overloaded +: addition of 2 Rationals, current object and parameter
Rational Rational::operator+(const Rational &rat) const {
  Rational sum{rat.numerator * denominator + rat.denominator * numerator,
               rat.denominator * denominator};
  return sum;
}

// TIP: Similar functions should use similar parameter names

// overloaded -: subtraction of 2 Rationals, current object and parameter
Rational Rational::operator-(const Rational &rat) const {
  Rational sub{rat.denominator * numerator - denominator * rat.numerator,
               rat.denominator * denominator};
  return sub;
}

// overloaded *: multiplication of 2 Rationals, current object and parameter
Rational Rational::operator*(const Rational &rat) const {
  Rational mult{rat.numerator * numerator,
                rat.denominator * denominator};
  return mult;
}

// overloaded /: division of 2 Rationals, current object and parameter,
Rational Rational::operator/(const Rational &rat) const {
  Rational div{rat.denominator * numerator,
               denominator * rat.numerator};
  return div;
}

// overloaded >: true if current object is > parameter, otherwise false
bool Rational::operator>(const Rational &rat) const {
  return static_cast<float>(numerator) / denominator >
      static_cast<float>(rat.numerator) / rat.denominator;
}

// overloaded <: true if current object is < parameter, otherwise false
bool Rational::operator<(const Rational &rat) const {
  return static_cast<float>(numerator) / denominator <
      static_cast<float>(rat.numerator) / rat.denominator;
}

// overloaded >=: true if current object is >= parameter, otherwise false
bool Rational::operator>=(const Rational &r) const {
  return *this == r || *this > r;
}

// overloaded <=: true if current object is <= parameter, otherwise false
bool Rational::operator<=(const Rational &r) const {
  return *this == r || *this < r;
}

// overloaded ==: true if current object is == parameter, otherwise false
bool Rational::operator==(const Rational &r) const {
  return (numerator == r.numerator && denominator == r.denominator);
}

// overloaded !=: true if current object is != parameter, otherwise false
bool Rational::operator!=(const Rational &r) const {
  return !(*this == r);
}

// overloaded +=: current object = current object + parameter
Rational &Rational::operator+=(const Rational &a) {
  numerator = a.numerator * denominator + a.denominator * numerator;
  denominator = a.denominator * denominator;

  // The following would be less efficient because of extra new/deletes
  // *this = *this + a;

  reduce();
  return *this;
}

// overloaded -=: current object = current object - parameter
Rational &Rational::operator-=(const Rational &a) {
  numerator = numerator * a.denominator - denominator * a.numerator;
  denominator = a.denominator * denominator;
  reduce();
  return *this;
}

// overloaded *=: current object = current object * parameter
Rational &Rational::operator*=(const Rational &a) {
  numerator = a.numerator * numerator;
  denominator = a.denominator * denominator;
  reduce();
  return *this;
}

// overloaded /=: current object = current object + parameter
Rational &Rational::operator/=(const Rational &a) {
  numerator = numerator * a.denominator;
  denominator = denominator * a.numerator;
  reduce();
  return *this;
}

/**
 *
 * overloaded <<: prints "DIVIDE BY ZERO ERROR!!!" if denominator is zero,
 *   prints whole numbers without denominator (as ints), otherwise uses '/'
 */
ostream &operator<<(ostream &output, const Rational &rat) {
  if (rat.denominator == 0)
    output << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
  else if (rat.numerator == 0)                              // zero rational
    output << 0;
  else if (rat.denominator == 1)                            // whole number
    output << rat.numerator;
  else
    output << rat.numerator << "/" << rat.denominator;

  return output;
}

/**
 *
 * overloaded >>: takes 2 ints as numerator and denominator, does no
 *    error checking, standard C casting between floats, char, etc occurs
 */
istream &operator>>(istream &input, Rational &rat) {
  input >> rat.numerator >> rat.denominator;
  rat.reduce();

  return input;
}


// reduce fraction to lowest terms
void Rational::reduce() {
  int n = numerator < 0 ? -numerator : numerator;  // make numerator positive
  int d = denominator;
  int largest = n > d ? n : d;           // larger of numerator and denom

  int gcd = 0;                           // greatest common divisor

  // find largest value that divides both numerator and denominator evenly
  for (int loop = largest; loop >= 2; loop--)
    if (numerator % loop == 0 && denominator % loop == 0) {
      gcd = loop;
      break;
    }

  // alter numerator, denominator if originally not reduced to lowest terms
  if (gcd != 0) {
    numerator /= gcd;
    denominator /= gcd;
  }
}

