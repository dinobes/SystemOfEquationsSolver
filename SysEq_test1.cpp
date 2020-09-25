#include <iostream>
#include <vector>
using namespace std;

// #include "lmath.h"
#include "SysEq.h"

int main()
{
  vector<vector<Num>> example;
  vector<Num> line1, line2, line3;
  line1.push_back({-7, 1});
  line1.push_back({-6, 1});
  line1.push_back({-12, 1});
  line1.push_back({-33, 1});
  line2.push_back({5, 1});
  line2.push_back({5, 1});
  line2.push_back({7, 1});
  line2.push_back({24, 1});
  line3.push_back({1, 1});
  line3.push_back({0, 1});
  line3.push_back({4, 1});
  line3.push_back({5, 1});
  example.push_back(line1);
  example.push_back(line2);
  example.push_back(line3);
  SysEq sysEq(3, 4, example);

  sysEq.printState(true);
  cout << endl;
  sysEq.setLeadingRow();
  sysEq.printState(true);
}