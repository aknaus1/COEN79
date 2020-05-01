#include <iostream>
#include <cassert>
#include <cmath>

#include "poly.h"

using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4 {
  // HELPER MEMBER FUNCTIONS for the polynomial class
  void polynomial::update_current_degree() {

  }
  //     POSTCONDITION: The current degree is set to the highest exponent
  //      with a non-zero coefficient.


  // CONSTRUCTOR for the polynomial class
  polynomial::polynomial(double c, unsigned int exponent) {
    assert(exponent <= MAXIMUM_DEGREE);
    for (int i = 0; i < CAPACITY; i++) {
      data[i] = 0;
    }
    data[exponent] = c;
  }
  //     PRECONDITION: exponent <= MAXIMUM_DEGREE
  //     POSTCONDITION: This polynomial has been created with all zero
  //     coefficients, except for coefficient c for the specified exponent.
  //     When used as a default constructor (using default values for
  //     both arguments), the result is a polynomial with all zero
  //     coefficients.


  // MODIFICATION MEMBER FUNCTIONS for the polynomial class
  void polynomial::assign_coef(double coefficient, unsigned int exponent) {
    assert(exponent <= MAXIMUM_DEGREE);
    data[exponent] = coefficient;
  }
  //     PRECONDITION: exponent <= MAXIMUM_DEGREE.
  //     POSTCONDITION: Sets the coefficient for the specified exponent.

  void polynomial::add_to_coef(double amount, unsigned int exponent) {
    assert(exponent <= MAXIMUM_DEGREE);
    data[exponent] += amount;
  }
  //     PRECONDITION: exponent <= MAXIMUM_DEGREE.
  //     POSTCONDITION: Adds the given amount to the coefficient of the
  //     specified exponent.

  void polynomial::clear( ){
    for (int i = 0; i < CAPACITY; i++) {
      data[i] = 0;
    }
  }
  //     POSTCONDITION: All coefficients of this polynomial are set to zero.


  // CONSTANT MEMBER FUNCTIONS for the polynomial class
  polynomial polynomial::antiderivative( ) const {
    assert(degree() < MAXIMUM_DEGREE);
    polynomial result(0,0);
    for (int i = 0; i < CAPACITY; i++) {
      result.data[i+1] = data[i] / (i + 1);
    }
    return result;
  }
  //     PRECONDITION: degree( ) < MAXIMUM_DEGREE
  //     POSTCONDITION: The return value is the antiderivative (indefinite integral)
  //     of this polynomial.
  //     NOTE: The return polynomial always has a constant term of zero.

  double polynomial::coefficient(unsigned int exponent) const {
    return data[exponent];
  }
  //     POSTCONDITION: Returns coefficient at specified exponent of this
  //     polynomial.
  //     NOTE: For exponents > MAXIMUM_DEGREE, the return value is always zero.

  double polynomial::definite_integral(double x0, double x1) const {
    polynomial result = antiderivative();
    double upper = 0.0, lower = 0.0;
    for (int i = 0; i < CAPACITY; i++) {
      upper += result.data[i] * pow(x0,i);
      upper += result.data[i] * pow(x1,i);
    }
    return upper - lower;
  }
  //     POSTCONDITION: Returns the value of the definite integral computed from
  //     x0 to x1.  The answer is computed analytically.

  unsigned int polynomial::degree( ) const {
    for (int i = MAXIMUM_DEGREE; i >= 0; i--) {
      if (data[i] != 0) {
        return i;
      }
    }
    return 0;
  }
  //     POSTCONDITION: The function returns the value of the largest exponent
  //     with a non-zero coefficient.
  //     If all coefficients are zero, then the function returns zero (even
  //     though, technically, this polynomial does not have a degree).

  polynomial polynomial::derivative( ) const {
    polynomial result;
    for (int i = 1; i < CAPACITY; i++) {
      result.data[i-1] = (data[i]*i);
    }
    return result;
  }
  //     POSTCONDITION: The return value is the first derivative of this
  //     polynomial.

  double polynomial::eval(double x) const {
    for (int i = 0; i < CAPACITY; i++) {
      if (data[i] == x) {
        return data[i];
      }
    }
    return '\0';
  }
  //     POSTCONDITION: The return value is the value of this polynomial with the
  //     given value for the variable x.

  bool polynomial::is_zero( ) const {
    for (int i = 0; i < CAPACITY; i++) {
      if (data[i] != 0) {
        return false;
      }
    }
    return true;
  }
  //     POSTCONDITION: The return value is true if and only if the polynomial
  //     is the zero polynomial.

  unsigned int polynomial::next_term(unsigned int e) const {
    for (int i = e+1; i < CAPACITY; i++) {
      if(data[i] != 0) {
        return i;
      }
    }
    return 0;
  }
  //     POSTCONDITION: The return value is the next exponent n which is LARGER
  //     than e such that coefficient(n) != 0.
  //     If there is no such term, then the return value is zero.

  unsigned int polynomial::previous_term(unsigned int e) const {
    for(int i = e-1; i >= 0; i--) {
      if(data[i] != 0) {
        return i;
      }
    }
    return 0;
  }
  //     POSTCONDITION: The return value is the next exponent n which is SMALLER
  //     than e such that coefficient(n) != 0.
  //     If there is no such term, then the return value is UINT_MAX
  //     from <climits>.


  // CONSTANT OPERATORS for the polynomial class
  double polynomial::operator( ) (double x) const {
    return eval(x);
  }
  //     Same as the eval member function.


  // NON-MEMBER BINARY OPERATORS for the polynomial Class
  polynomial operator +(const polynomial& p1, const polynomial& p2) {
    polynomial result;
    for(int i = 0; i < polynomial::CAPACITY; i++) {
      result.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
    }
    return result;
  }
  //     POSTCONDITION: return-value is a polynomial with each coefficient
  //     equal to the sum of the coefficients of p1 & p2 for any given
  //     exponent.

  polynomial operator -(const polynomial& p1, const polynomial& p2) {
    polynomial result;
    for(int i = 0; i < polynomial::CAPACITY; i++) {
      result.assign_coef(p1.coefficient(i) - p2.coefficient(i), i);
    }
    return result;
  }
  //     POSTCONDITION: return-value is a polynomial with each coefficient
  //     equal to the difference of the coefficients of p1 & p2 for any given
  //     exponent.

  polynomial operator *(const polynomial& p1, const polynomial& p2) {
    assert(p1.degree( ) + p2.degree( ) <= polynomial::MAXIMUM_DEGREE);
    polynomial result;
    for (int i = 0; i <= p1.degree(); i++) {
      for (int j = 0; j <= p2.degree(); j++) {
        result.add_to_coef(p1.coefficient(i) * p2.coefficient(j), i+j);
      }
    }
    return result;
  }
  //     PRECONDITION: p1.degree( ) + p2.degree( ) <= MAXIMUM_DEGREE.
  //     POSTCONDITION: Each term of p1 has been multiplied by each term of p2,
  //     and the answer is the sum of all these term-by-term products.
  //     For example, if p1 is 2x^2 + 3x + 4 and p2 is 5x^2 - 1x + 7, then the
  //     return value is 10x^4 + 13x^3 + 31x^2 + 17x + 28.


  // NON-MEMBER OUTPUT FUNCTIONS for the polynomial Class
  std::ostream& operator << (std::ostream& out, const polynomial& p) {
    for (int i = p.degree(); i >= 0; i--) {
      if (p.coefficient(i) != 0) {
        if (i == p.degree()) {
          out << p.coefficient(i) << "x^" << i << " ";
        } else {
          if(p.coefficient(i) < 0) {
            out << "- ";
          } else {
            out << "+ ";
          }
          if (i > 1) {
            out << fabs(p.coefficient(i)) << "x^" << i << " ";
          } else if (i == 1) {
            out << fabs(p.coefficient(i)) << "x ";
          } else {
            out << fabs(p.coefficient(i));
          }
        }
      }
    }
    return out;
  }
  //     POSTCONDITION: The polynomial has been printed to ostream out, which,
  //     in turn, has been returned to the calling function.
  //     The format of the polynomial when printed should be as follows:
  //              -2.5x^2 - 4x + 5.9
  //     1) There should be exactly 1 space between the numbers and the operators.
  //     2) The constant coefficient should be printed by itself: 5.3, not 5.3x^0
  //     3) The first coefficient chould be followed by a plain x: 4x, not 4x^1
  //     4) The highest degree's coefficient should have a sign: -2.5x^2, but the
  //          following values should all be separated by appropriate operators
  //          and then printed unsigned: -2.5x^2 - 4x...
  //     5) If you manipulate any settings of the outstream inside of this,
  //          such as the precision, they should be restored to what they were
  //          at the start of the function before returning.
}
