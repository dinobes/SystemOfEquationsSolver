#include "Num.h"
#include <iostream>
using namespace std;

int main() {
  
  // n1 through n6 are supposed to pass
  Num n1;
  cout << n1.numerator << "/" << n1.denominator << endl;

  Num n2(2);
  cout << n2.numerator << "/" << n2.denominator << endl;

  Num n3(3, 2);
  cout << n3.numerator << "/" << n3.denominator << endl;

  Num n4(4, 2);
  cout << n4.numerator << "/" << n4.denominator << endl;

  Num n5(6, 4);
  cout << n5.numerator << "/" << n5.denominator << endl;

  Num n6(-1);
  cout << n6.numerator << "/" << n6.denominator << endl;

  // Copy constructor
  Num n7(n3);
  cout << n7.numerator << "/" << n7.denominator << endl;

  // Assignment operator
  Num n8 = n3;
  cout << n8.numerator << "/" << n8.denominator << endl;

  return 0;
}