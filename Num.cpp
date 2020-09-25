#include "Num.h"
#include <iostream>
using namespace std;

Num::Num() {
  numerator = 0;
  denominator = 1;
}

Num::Num(int n) {
  numerator = n;
  denominator = 1;
}

Num::Num(int n, int d) {
  if (d == 0) {
    cerr << "Error: denominator is inappropriate" << endl;
    exit(EXIT_FAILURE);
  }
  if (d < 0) {
    n *= -1;
    d *= -1;
  }
  if (d > 1) {
    reduce(n, d);
  } else {
    numerator = n;
    denominator = d;
  }
}

Num::Num(const Num& other) {
  numerator = other.numerator;
  denominator = other.denominator;
}

Num& Num::operator=(const Num& other) {
  numerator = other.numerator;
  denominator = other.denominator;
  return *this;
}

int Num::gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, abs(a) % b);
}

void Num::reduce(int a, int b) {
  int gcdenom = gcd(a, b);
  if (gcdenom != 1) {
    a /= gcdenom;
    b /= gcdenom;
  }
  numerator = a;
  denominator = b;
}