#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Num.h"
#include "lmath.h"

using namespace std;

void printState(vector<vector<Num>>& sysEq);

int main() {
  int numRows, numCols;
  vector<vector<Num>> sysEq;

  // Open file
  ifstream inFile;
  inFile.open("arca.txt");

  // Check if file opened properly

  // Read in rows and columns from file
  inFile >> numRows;
  inFile >> numCols;

  cout << "Number of rows:    " << numRows << endl;
  cout << "Number of columns: " << numCols << endl;

  // Read in variables
  for (int i = 0; i < numRows; ++i) {
    vector<Num> equation;
    for (int j = 0; j < numCols; ++j) {
      int numIn;
      inFile >> numIn;
      Num numPush(numIn);
      equation.push_back(numPush);
    }
    sysEq.push_back(equation);
  }

  printState(sysEq);

  return 0;
}

void printState(vector<vector<Num>>& sysEq) {
  for (size_t i = 0; i < sysEq.size(); ++i) {
    for (size_t j = 0; j < sysEq[i].size(); ++j) {
      if (sysEq[i][j].denominator != 1) {
        cout << sysEq[i][j].numerator << "/" << sysEq[i][j].denominator << " ";
      } else {
        cout << sysEq[i][j].numerator << " ";
      }
    }
    cout << endl;
  }
}