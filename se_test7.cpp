#include <iostream>
#include <vector>

#include "SysEq.h"

using namespace std;

static const Num ONE = {1, 1};
int main()
{
  SysEq sysEq7(3, 3, {{ONE, ONE, ONE}, {ONE, ONE, ONE}, {ONE, ONE, ONE}});
  sysEq7.printSwapStatement(1, 2);
  cout << endl;
  sysEq7.printScaleStatement(1, {2, 1}, false);
  sysEq7.printScaleStatement(1, {2, 1}, true);
  sysEq7.printScaleStatement(1, {1, 2}, false);
  sysEq7.printScaleStatement(1, {1, 2}, true);
  cout << endl;
  sysEq7.printAddStatement(2, {-2, 3}, false);
  sysEq7.printAddStatement(2, {-2, 3}, true);
  sysEq7.printAddStatement(2, {2, 3}, false);
  sysEq7.printAddStatement(2, {2, 3}, true);
  sysEq7.printAddStatement(2, {-2, 1}, false);
  sysEq7.printAddStatement(2, {-2, 1}, true);

  return 0;
}