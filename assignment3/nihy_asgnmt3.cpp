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

  ChainedHashTable<int> table;
  table.SetLocalFactor(3.75);
  table.TestHash(400);
  cout << endl;
  cout << "Longest DLList: " << table.GetLongestList() << endl;

  LinearHashTable<int> table2(-1, -2);
  table2.PrintTable(50);
  for (int i = 0; i < 25; i++) {
    int random = (unsigned) rand() % 100;
    if (table2.find(random) != table2.getNull())
      table2.remove(random);
  }


  return 0;

}
