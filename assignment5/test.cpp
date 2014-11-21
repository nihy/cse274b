//============================================================================
// Name        : nihy_asgnmt5.cpp
// Author      : Henry Ni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "List.h"

using namespace std;
using namespace ods;

void testCHash(DataStructureTester<ChainedHashTable<int> > &chashtest) {
  int seq_add = 0, seq_rem = 0, seq_fnd = 0, rnd_add = 0, rnd_rem = 0, rnd_fnd = 0;

  for (int i = 0; i < 20; i++) {
    seq_add += chashtest.DoSequentialAdd(0, 50000, 1);
    seq_fnd += chashtest.DoSequentialFind(0, 50000, 1);
    seq_rem += chashtest.DoSequentialRemove(0, 50000, 1);
    srand(0);
    rnd_add += chashtest.DoRandomAdd(50000);
    srand(0);
    rnd_fnd += chashtest.DoRandomFind(50000);
    srand(0);
    rnd_rem += chashtest.DoRandomRemove(50000);
  }

  cout << "Average C. Hash operation run times: " << endl;
  cout << "Seq. ADD:      " << seq_add/20 << " milliseconds" << endl;
  cout << "Seq. FIND:     " << seq_fnd/20 << " milliseconds" << endl;
  cout << "Seq. REMOVE:   " << seq_rem/20 << " milliseconds" << endl;
  cout << "Random ADD:    " << rnd_add/20 << " milliseconds" << endl;
  cout << "Random FIND:   " << rnd_fnd/20 << " milliseconds" << endl;
  cout << "Random REMOVE: " << rnd_rem/20 << " milliseconds\n" << endl;

}

void testLHash(DataStructureTester<LinearHashTable<int> > &lhashtest) {
  int seq_add = 0, seq_rem = 0, seq_fnd = 0, rnd_add = 0, rnd_rem = 0, rnd_fnd = 0;

  for (int i = 0; i < 20; i++) {
    seq_add += lhashtest.DoSequentialAdd(0, 50000, 1);
    seq_fnd += lhashtest.DoSequentialFind(0, 50000, 1);
    seq_rem += lhashtest.DoSequentialRemove(0, 50000, 1);
    srand(0);
    rnd_add += lhashtest.DoRandomAdd(50000);
    srand(0);
    rnd_fnd += lhashtest.DoRandomFind(50000);
    srand(0);
    rnd_rem += lhashtest.DoRandomRemove(50000);
  }

  cout << "Average L. Hash operation run times: " << endl;
  cout << "Seq. ADD:      " << seq_add/20 << " milliseconds" << endl;
  cout << "Seq. FIND:     " << seq_fnd/20 << " milliseconds" << endl;
  cout << "Seq. REMOVE:   " << seq_rem/20 << " milliseconds" << endl;
  cout << "Random ADD:    " << rnd_add/20 << " milliseconds" << endl;
  cout << "Random FIND:   " << rnd_fnd/20 << " milliseconds" << endl;
  cout << "Random REMOVE: " << rnd_rem/20 << " milliseconds\n" << endl;

}

void testBSTree(DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > &bstest) {
  int seq_add = 0, seq_rem = 0, seq_fnd = 0, rnd_add = 0, rnd_rem = 0, rnd_fnd = 0;

  for (int i = 0; i < 20; i++) {
    seq_add += bstest.DoSequentialAdd(0, 50000, 1);
    seq_fnd += bstest.DoSequentialFind(0, 50000, 1);
    seq_rem += bstest.DoSequentialRemove(0, 50000, 1);
    srand(0);
    rnd_add += bstest.DoRandomAdd(50000);
    srand(0);
    rnd_fnd += bstest.DoRandomFind(50000);
    srand(0);
    rnd_rem += bstest.DoRandomRemove(50000);
  }

  cout << "Average B.S. Tree operation run times: " << endl;
  cout << "Seq. ADD:      " << seq_add/20 << " milliseconds" << endl;
  cout << "Seq. FIND:     " << seq_fnd/20 << " milliseconds" << endl;
  cout << "Seq. REMOVE:   " << seq_rem/20 << " milliseconds" << endl;
  cout << "Random ADD:    " << rnd_add/20 << " milliseconds" << endl;
  cout << "Random FIND:   " << rnd_fnd/20 << " milliseconds" << endl;
  cout << "Random REMOVE: " << rnd_rem/20 << " milliseconds\n" << endl;

}

void testRBTree(DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > &rbtest) {
  int seq_add = 0, seq_rem = 0, seq_fnd = 0, rnd_add = 0, rnd_rem = 0, rnd_fnd = 0;

  for (int i = 0; i < 20; i++) {
    seq_add += rbtest.DoSequentialAdd(0, 50000, 1);
    seq_fnd += rbtest.DoSequentialFind(0, 50000, 1);
    seq_rem += rbtest.DoSequentialRemove(0, 50000, 1);

    rnd_add += rbtest.DoRandomAdd(50000);
    rnd_fnd += rbtest.DoRandomFind(50000);
    rnd_rem += rbtest.DoRandomRemove(50000);
  }

  cout << "Average Red/Black Tree operation run times: " << endl;
  cout << "Seq. ADD:      " << seq_add/20 << " milliseconds" << endl;
  cout << "Seq. FIND:     " << seq_fnd/20 << " milliseconds" << endl;
  cout << "Seq. REMOVE:   " << seq_rem/20 << " milliseconds" << endl;
  cout << "Random ADD:    " << rnd_add/20 << " milliseconds" << endl;
  cout << "Random FIND:   " << rnd_fnd/20 << " milliseconds" << endl;
  cout << "Random REMOVE: " << rnd_rem/20 << " milliseconds\n" << endl;

}

int main() {

  DataStructureTester<ChainedHashTable<int> > chashtest;
  DataStructureTester<LinearHashTable<int> > lhashtest;
  DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > bstest;
  DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > rbtest;

  testCHash(chashtest);
  testLHash(lhashtest);
  testBSTree(bstest);
  testRBTree(rbtest);

  return 0;
}
