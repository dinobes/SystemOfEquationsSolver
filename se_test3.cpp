#include <iostream>
#include <fstream>
#include <vector>

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

  sysEqC.add(1, 0);
  sysEqC.add(2, 0);

  cout << endl;

  sysEqC.printState(true);

  sysEqC.setWorkingColumn();
  cout << "Working column is: " << sysEqC.workingCol << endl;
  
  sysEqC.incrementWorkingRow();
  cout << "Working row is: " << sysEqC.workingRow << endl;

  sysEqC.setLeadingRow();
  sysEqC.printState(true);

  sysEqC.add(0, 1);
  sysEqC.add(2, 1);

  cout << endl;

  sysEqC.printState(true);

  sysEqC.setWorkingColumn();
  cout << "Working column is: " << sysEqC.workingCol << endl;

  sysEqC.incrementWorkingRow();
  cout << "Working row is: " << sysEqC.workingRow << endl;

  sysEqC.setLeadingRow();
  sysEqC.printState(true);

  sysEqC.add(0, 2);
  sysEqC.add(1, 2);

  cout << endl;

  sysEqC.printState(true);
}