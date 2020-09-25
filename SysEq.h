#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "lmath.h"

class SysEq {
  public:
    vector<vector<Num>> eqSys;
    int numRows;
    int numCols;
    int workingRow = 0;
    int workingCol = 0;
    int numZeroRows = 0;

    SysEq(int, int);
    SysEq(int, int, ifstream&);
    SysEq(int, int, vector<vector<Num>>); // Should be made to pass by reference

    void swap(int r1, int r2);
    void add(int r1, int r2);
    void multiply(int r, Num scalar);
    Num getInverse(int r, int c);
    Num getScalarFromSelf(int r, int workCol);
    Num getScalarFromRow(int r1, int r2, int workCol);
    void incrementWorkingRow();
    void setLeadingRow();
    void printState(bool);
    void setWorkingColumn();
    void checkZeroRows();
    void handleZeroRows();
    bool leadingOneRowCheck(int);
    bool leadingOneColumnCheck(int);
    void printSwapStatement(int, int);
    void printScaleStatement(int, Num, bool);
    void printAddStatement(int, Num, bool);
};