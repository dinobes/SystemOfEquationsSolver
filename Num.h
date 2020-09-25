#include <iostream>
#include <cmath>
using namespace std;

class Num {
  public:
    int numerator;
    int denominator;
    Num();
    Num(int n);
    Num(int n, int d);
    Num(const Num& other);
    Num &operator=(const Num& other);
    int gcd(int a, int b);
    void reduce(int a, int b);
};