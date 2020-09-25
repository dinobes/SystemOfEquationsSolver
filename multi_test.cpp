#include <iostream>
#include <vector>
using namespace std;

#include "lmath.h"

int main()
{
  Num n1(2);
  Num n2(1, 2);

  Num product = multiplyNums(n1, n2);
  cout << "2/1 * 1/2 = " << product.numerator << "/" << product.denominator << endl;

  vector<Num> row = { Num(2), Num(1), Num(1), Num(8) };
  Num multiple = Num(1, 2);

  for (size_t i = 0; i < row.size(); ++i) {
    cout << "[" << i << "] = " << row[i].numerator << "/" << row[i].denominator << endl;
  }
  cout << endl;

  for (size_t i = 0; i < row.size(); ++i) {
    row[i] = multiplyNums(row[i], multiple);
    cout << "[" << i << "] = " << row[i].numerator << "/" << row[i].denominator << endl;
  }
  return 0;
}