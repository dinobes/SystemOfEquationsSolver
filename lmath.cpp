#include "lmath.h"

using namespace std;

// https://www.tutorialspoint.com/cplusplus-program-to-find-lcm
int lcm(int d1, int d2) {
  int lcmult = (d1 > d2) ? d1 : d2;
  while (1) {
    if (lcmult % d1 == 0 && lcmult % d2 == 0) {
      return lcmult;
    }
    ++lcmult;
  }
}

Num addNums(Num n1, Num n2) {
  Num sum = n1;
  if (n1.denominator == n2.denominator) {
    // Add numerator values together to get sum numerator value
    sum.numerator += n2.numerator;

    // Check if simplification is necessary
    sum.reduce(sum.numerator, sum.denominator);
  } else {
    // Find least common multiple of denominators
    int lcmult = lcm(n1.denominator, n2.denominator);

    // Find multiplier values for each numerator and denominator
    int diff1 = lcmult / n1.denominator;
    int diff2 = lcmult / n2.denominator;

    // Multiply the numerator and denominators of n1 and n2 by multiplier values
    n1.numerator *= diff1;
    n1.denominator *= diff1;

    n2.numerator *= diff2;
    n2.denominator *= diff2;

    // Add numerator values together to get sum numerator
    sum.numerator = n1.numerator + n2.numerator;

    // Update sum denominator with new n1 denominator
    sum.denominator = n1.denominator;

    // Check if simplification is necessary
    sum.reduce(sum.numerator, sum.denominator);
  }
  return sum;
}

Num multiplyNums(Num n, Num mult) {
  Num multi = n;
  multi.numerator *= mult.numerator;
  multi.denominator *= mult.denominator;
  multi.reduce(multi.numerator, multi.denominator);
  return multi;
}