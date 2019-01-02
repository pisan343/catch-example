/**
 * @brief Operations on Rational numbers
 * @file rational.cpp
 *
 * Based on Deitel & Detitel but modified significantly
 * a Rational object holds one Rational number, one fraction
 *
 * Rational numbers:  defined as ratios of whole number, otherwise known as
 * fractions (can be proper or improper), all follow the laws of arithmetic
 * such as commutative law, associative law, distributive law, etc.
 * Examples include  2/3 , -7/8 , 20/9
 *
 * Implementation and assumptions:
 * -- Rationals are stored as integer numerators and denominators
 * -- if the rational number is negative, the numerator is the negative
 * -- all stored rationals are reduced to lowest terms
 * -- all arithmetic operators return Rationals reduced to lowest terms
 * -- Dividing by zero returns zero
 *
 * @author Yusuf Pisan
 * @date 7 Dec 2018
 */


// TIP: Must have file guards not #pragma is Windows specific
#ifndef CATCH_EXAMPLE_RATIONAL_H
#define CATCH_EXAMPLE_RATIONAL_H

#include <iostream>

using namespace std;

class Rational {
  // TIP: friends classes and functions come before private/public
  // TIP: variable names in function declarations is optional, but useful
  // TIP: CLion will generate the comments when you enter /** and press RETURN
  // TIP: @param and @return not required, but useful for doxygen
  // TIP: Do not exceed 80 lines in code or comments
  // TIP: Always use const for functions when possible
  // TIP: Always use pass by const reference when possible
  // TIP: Pass strings by const reference, return them by const reference

  // * prints whole numbers without denominator (as ints), otherwise uses '/'
  friend ostream &operator<<(ostream &os, const Rational &rat);

  /**
   * overloaded >>
   * takes 2 ints as numerator and denominator, no error checking,
   * standard C casting between floats, char, etc occurs
   */
  friend istream &operator>>(istream &is, Rational &rat);

 public:
  // TIP: Mark constructors that can take one parameter explicit
  // TIP: default values can be set in function declaration but not both
  // TIP: default values can be set in variable declaration but not both

  // Default constructor with default values for parameters
  explicit Rational(int numerator = 0, int denominator = 1);

  // get numerator
  int getNumerator() const;

  // get denominator
  int getDenominator() const;

  // TIP: Avoid implicit conversions mark conversion operators explicit
  // for more info on explicit, see
  // https://clang.llvm.org/extra/clang-tidy/checks/google-explicit-constructor.html

  // Conversion function, explicitly convert Rational to an int
  explicit operator int() const;

  // Add
  Rational operator+(const Rational &) const;

  // Subtract
  Rational operator-(const Rational &) const;

  // Multiply
  Rational operator*(const Rational &) const;

  // Divide
  Rational operator/(const Rational &) const;

  // Compare >
  bool operator>(const Rational &) const;

  // Compare <
  bool operator<(const Rational &) const;

  // Compare >=
  bool operator>=(const Rational &) const;

  // Compare <=
  bool operator<=(const Rational &) const;

  // Compare ==
  bool operator==(const Rational &) const;

  // Compare !=
  bool operator!=(const Rational &) const;

  // Modify add +=
  Rational &operator+=(const Rational &);

  // Modify subtract -=
  Rational &operator-=(const Rational &);

  // Modify multiply *=
  Rational &operator*=(const Rational &);

  // Modify divide /=
  Rational &operator/=(const Rational &);

 private:
  // Numerator of fraction
  int numerator;

  // Denominator of fraction
  int denominator;

  // Reduce fraction to lowest terms
  void reduce();
};

#endif  // CATCH_EXAMPLE_RATIONAL_H
