//============================================================================
// Name        : nihy_asgnmt4.cpp
// Author      : Henry Ni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "nihy_BinaryTree.h"
#include "nihy_BinarySearchTree.h"
#include "DLList.h"

using namespace std;
using namespace ods;

int main() {
  BinarySearchTree<BSTNode1<int>, int> tree;
   tree.add(15);
   tree.add(10);
   tree.add(14);
   tree.add(17);
   tree.add(20);
   tree.add(16);
   tree.add(19);
   tree.add(26);
   tree.add(7);
   tree.add(9);
   tree.add(5);

  return 0;
}
