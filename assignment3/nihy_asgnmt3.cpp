//============================================================================
// Name        : nihy_asgnmt3.cpp
// Author      : Henry Ni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include "nihy_ChainedHashTable.h"
#include "nihy_LinearHashTable.h"

using namespace std;
using namespace ods;

int main() {
  srand(time(0));

  /* ChainedHashTable<int> table;
  table.SetLocalFactor(8);
  table.TestHash(1000);

  cout << endl;

  cout << "Longest DLList: " << table.GetLongestList() << endl;
   */

  LinearHashTable<int> table2(-1, -2);
  /*
  cout << table2.add(7) << endl;
  cout << "FIND: " << table2.find(7) << endl;
  cout << table2.add(5) << endl;
  cout << "FIND: " << table2.find(5) << endl;
*/
  table2.PrintTable(50);
  table2.EvenlyLoaded();

  return 0;

}
