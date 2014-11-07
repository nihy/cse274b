//============================================================================
// Name        : test.cpp
// Author      : Henry Ni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "nihy_BinaryTree.h"
#include "nihy_BinarySearchTree.h"
#include "DLList.h"
#include "time.h"

using namespace std;
using namespace ods;

bool TestPartOne() {
  srand(time(0));
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

  return (tree.height() == tree.Height2()) ? true : false;
}

bool TestPartTwo() {
  BinarySearchTree<BSTNode1<int>, int> tree;
  tree.add(50);
  tree.add(25);
  tree.add(75);

  bool isTrue = tree.isBalanced();

  tree.add(10);
  tree.add(4);
  tree.add(1);

  bool isFalse = tree.isBalanced();

  return isTrue && !isFalse;
}

bool TestPartThree() {
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

  tree.preOrderNumber();
  tree.inOrderNumber();
  tree.postOrderNumbers();

  bool testPreOrder, testInOrder, testPostOrder;
  if ((tree.getNode(15)->pre_order == 1) && (tree.getNode(5)->pre_order == 4)
      && (tree.getNode(26)->pre_order == 11))
    testPreOrder = true;
  if ((tree.getNode(15)->in_order == 6) && (tree.getNode(5)->in_order == 1)
        && (tree.getNode(26)->in_order == 11))
      testInOrder = true;
  if ((tree.getNode(15)->pst_order == 11) && (tree.getNode(5)->pst_order == 1)
        && (tree.getNode(26)->pst_order == 8))
      testPostOrder = true;

  return testPreOrder && testInOrder && testPostOrder;
}

bool TestPartFour() {
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

    DLList<int> list1 = tree.getLE(17);
    DLList<int> list2 = tree.getLE(9);

    return ((list1.size() == 8 && list2.size() == 3)) ? true : false;
}

int main() {
  cout << "Part One: 1 = true; 0 = false \n" << TestPartOne() << endl;
  cout << "Part Two: 1 = true; 0 = false \n" << TestPartTwo() << endl;
  cout << "Part Three: 1 = true; 0 = false \n" << TestPartThree() << endl;
  cout << "Part Four: 1 = true; 0 = false \n" << TestPartFour() << endl;
  return 0;
}
