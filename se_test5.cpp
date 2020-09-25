#include <iostream>
#include <vector>

#include "SysEq.h"

using namespace std;

static const Num ONE = {1, 1};
static const Num ZERO = {0, 1};
static const Num TWO = {2, 1};
int main() {
  SysEq sysEqRowCheck(3, 3, {{ONE, ZERO, ZERO}, {ZERO, TWO, ZERO}, {ZERO, ZERO, ONE}});
  sysEqRowCheck.printState(true);
  cout << endl;
  cout << boolalpha << "Row 1 passes the test: " << sysEqRowCheck.leadingOneRowCheck(0) << endl;
  cout << boolalpha << "Row 2 passes the test: " << sysEqRowCheck.leadingOneRowCheck(1) << endl;
  cout << boolalpha << "Row 3 passes the test: " << sysEqRowCheck.leadingOneRowCheck(2) << endl;

  return 0;
}