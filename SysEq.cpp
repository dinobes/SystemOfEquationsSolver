#include <iostream>
#include <vector>

#include "SysEq.h"

static const Num ONE = Num(1);
static const Num NEG_ONE = Num(-1);

SysEq::SysEq(int _numRows, int _numCols) : numRows(_numRows), numCols(_numCols)
{
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      eqSys[i][j] = 0;
    }
  }
}

SysEq::SysEq(int _numRows, int _numCols, ifstream& openFile) : numRows(_numRows), numCols(_numCols)
{
  for (int i = 0; i < numRows; ++i) {
    vector<Num> equation;
    for (int j = 0; j < numCols; ++j) {
      int numIn;
      openFile >> numIn;
      Num numPush(numIn);
      equation.push_back(numPush);
    }
    eqSys.push_back(equation);
  }
}

SysEq::SysEq(int _numRows, int _numCols, vector<vector<Num>> eqSysIn) : numRows(_numRows), numCols(_numCols)
{
  for (int i = 0; i < numRows; ++i) {
    vector<Num> equation;
    for (int j = 0; j < numCols; ++j) {
      equation.push_back(eqSysIn[i][j]);
      // TODO: Pass by reference or potentially double reference (&&) so that address of eqSysIn[i][j] is used instead of just a copy of that value
    }
    eqSys.push_back(equation);
  }
}

void SysEq::swap(int r1, int r2)
{
  vector<Num> tempRow;
  for (int i = 0; i < numCols; ++i) {
    tempRow.push_back(eqSys[r1][i]);
  }

  for (int i = 0; i < numCols; ++i) {
    eqSys[r1][i] = eqSys[r2][i];
  }

  for (int i = 0; i < numCols; ++i) {
    eqSys[r2][i] = tempRow[i];
  }
}

void SysEq::add(int r1, int r2)
{
  Num scalar = getScalarFromRow(r1, r2, workingCol);
  for (int i = 0; i < numCols; ++i) {
    Num scaledElement = multiplyNums(eqSys[r2][i], multiplyNums(NEG_ONE, scalar));
    eqSys[r1][i] = addNums(eqSys[r1][i], scaledElement);
  }
}

void SysEq::multiply(int r, Num scalar)
{
  for (int i = 0; i < numCols; ++i) {
    eqSys[r][i] = multiplyNums(eqSys[r][i], scalar);
  }
}

Num SysEq::getInverse(int r, int c)
{
  Num inverse(eqSys[r][c].denominator, eqSys[r][c].numerator);
  return inverse;
}

Num SysEq::getScalarFromSelf(int r, int workCol)
{
  Num scalar = multiplyNums(NEG_ONE, eqSys[r][workCol]);
  return scalar;
}

Num SysEq::getScalarFromRow(int r1, int r2, int workCol)
{
  // TODO MAYBE: r2 = workingRow
  Num scalar = multiplyNums(eqSys[r1][workCol], getInverse(r2, workCol));
  return scalar;
}

void SysEq::incrementWorkingRow()
{
  ++workingRow;
}

void SysEq::setLeadingRow()
{
  // TODO: Take care of edge case where workingRow has '0' in the workingCol
  bool rowFound = false;
  for (int i = workingRow; i < numRows; ++i) {
    // TODO: Make '==' operator for Num class
    if (eqSys[i][workingCol].numerator == 1
        && eqSys[i][workingCol].denominator == 1)
    {
      rowFound = true;
      if (i != workingRow) {
        swap(workingRow, i);
        break;
      }
    }
  }
  if (!rowFound) {
    multiply(workingRow, {1, eqSys[workingRow][workingCol].numerator});
  }
}

void SysEq::printState(bool isTest)
{
  for (size_t i = 0; i < eqSys.size(); ++i)
  {
    for (size_t j = 0; j < eqSys[i].size(); ++j)
    {
      if (isTest || eqSys[i][j].denominator != 1) {
        cout << eqSys[i][j].numerator << "/" << eqSys[i][j].denominator << " ";
      } else {
        cout << eqSys[i][j].numerator << " ";
      }
    }
    cout << endl;
  }
}

void SysEq::setWorkingColumn()
{
  // Start col at one after the working column, check each column to see if nonzero values exist until you get to the end of the row
  int col = workingCol + 1;

  bool workingColFound = false;
  while (col < (int)eqSys[0].size() && !workingColFound)
  {
    for (int i = 0; i < numRows; ++i)
    {
      if (i != workingRow) {
        if (eqSys[i][col].numerator != 0) {
          workingCol = col;
          workingColFound = true;
          break;
        }
      }
    }
    col++;
  }
}

void SysEq::checkZeroRows()
{
  
}

void SysEq::handleZeroRows()
{
  // TODO: Optimize so that it performs no operations on zero rows already at the bottom of the system of equations
  vector<int> zeroRowIndices;
  // Find rows that contain all zeros, if they exist
  for (int i = 0; i < (int)eqSys.size(); ++i) {
    bool isNonzeroRow = false;
    for (int j = 0; j < (int)eqSys[i].size() && !isNonzeroRow; ++j) {
      if (eqSys[i][j].numerator != 0) {
        isNonzeroRow = true;
      }
    }
    if (!isNonzeroRow) {
      zeroRowIndices.push_back(i);
    }
  }
  // Swap rows to the bottom
  for (int i = (int)zeroRowIndices.size() - 1; i >= 0; --i) {
    swap(zeroRowIndices[i], (int)eqSys.size() - numZeroRows - 1);
    ++numZeroRows;
  }
}

bool SysEq::leadingOneRowCheck(int row)
{
  for (int i = 0; i < (int)eqSys[row].size(); ++i) {
    if (eqSys[row][i].numerator != 0) {
      if (eqSys[row][i].numerator == 1) {
        return true;
      } else {
        return false;
      }
    }
  }
  return true; // This is a zero row
}

bool SysEq::leadingOneColumnCheck(int col)
{
  bool oneFound = false;
  for (int i = 0; i < (int)eqSys.size(); ++i) {
    if (eqSys[i][col].numerator != 0) {
      if (eqSys[i][col].numerator == 1 && !oneFound) {
        oneFound = true;
      } else {
        return false;
      }
    }
  }
  return true;
}