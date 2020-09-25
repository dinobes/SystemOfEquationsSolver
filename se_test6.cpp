#include <iostream>
#include <vector>

#include "SysEq.h"

using namespace std;

static const Num ONE = {1, 1};
static const Num ZERO = {0, 1};
static const Num TWO = {2, 1};
int main() {
  SysEq sysEqColCheck(4, 3, {{ONE, ZERO, ZERO}, {ZERO, TWO, ZERO}, {ZERO, ZERO, ONE}, {ONE, ZERO, ZERO}});
  sysEqColCheck.printState(true);
  cout << endl;
  cout << boolalpha << "Column 1 passes the test: " << sysEqColCheck.leadingOneColumnCheck(0) << endl;
  cout << boolalpha << "Column 2 passes the test: " << sysEqColCheck.leadingOneColumnCheck(1) << endl;
  cout << boolalpha << "Column 3 passes the test: " << sysEqColCheck.leadingOneColumnCheck(2) << endl;

  return 0;
}