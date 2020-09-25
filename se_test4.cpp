/*
This test case tests the correctness of SysEq::handleZeroRows()
*/

#include <iostream>
#include <vector>

#include "SysEq.h"

using namespace std;

static const Num ONE = {1, 1};
static const Num ZERO = {0, 1};
int main()
{
  SysEq sysEqZeroTest(5, 5, {{ONE, ONE, ONE, ONE, ONE},
                              {ZERO, ZERO, ZERO, ZERO, ZERO},
                              {ZERO, ZERO, ZERO, ZERO, ZERO},
                              {ONE, ONE, ONE, ONE, ONE},
                              {ONE, ONE, ONE, ONE, ONE}});
  
  sysEqZeroTest.printState(true);
  sysEqZeroTest.handleZeroRows();
  cout << endl;
  sysEqZeroTest.printState(true);
}