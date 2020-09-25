#include <iostream>
using namespace std;

#include "lmath.h"

int main()
{
  Num n1(3, 2);
  Num n2(5, 2);
  Num n3(4, 2);

  // TODO: Add operator '<<' functionality for Num class
  Num sum1 = addNums(n1, n2);
  cout << "3/2 + 5/2 = " << sum1.numerator << "/" << sum1.denominator << endl;

  Num sum2 = addNums(n1, n3);
  cout << "3/2 + 4/2 = " << sum2.numerator << "/" << sum2.denominator << endl;

  Num sum3 = addNums(sum1, n3);
  cout << "3/2 + 5/2 + 4/2 = " << sum3.numerator << "/" << sum3.denominator << endl;

  Num n4(5, 3);
  Num sum4 = addNums(n1, n4);
  cout << "3/2 + 5/3 = " << sum4.numerator << "/" << sum4.denominator << endl;

  return 0;
}