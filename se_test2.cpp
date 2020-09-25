#include <iostream>
#include <vector>
#include <fstream>

#include "SysEq.h"

using namespace std;

int main()
{
  int numRows, numCols;
  ifstream cfile;
  cfile.open("arcc.txt");

  cfile >> numRows;
  cfile >> numCols;

  SysEq sysEqC(numRows, numCols, cfile);

  sysEqC.printState(true);

  cout << endl;
  sysEqC.setLeadingRow();

  sysEqC.printState(true);

  return 0;
}