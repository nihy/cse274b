/*
 * nihy_ChainedHashTable.h
 *
 *  Created on: Oct 13, 2014
 *      Author: Henry
 */

#ifndef NIHY_CHAINEDHASHTABLE_H_
#define NIHY_CHAINEDHASHTABLE_H_

#include <climits>
#include <ctime>
#include "utils.h"
#include "array.h"
#include "DLList.h"

using namespace std;
namespace ods {

template<class T>
class ChainedHashTable {
protected:
  typedef DLList<T> List;
  T null;
  array<List> t;
  int n;
  int d;
  int z;
  float f;
  static const int w = 32; // sizeof(int)*8;
  void allocTable(int m);
  void resize();
  int hash(T x) {
    return (unsigned) (z * x) % (1 << d);
  }
  ;

public:
  ChainedHashTable();
  virtual ~ChainedHashTable();
  bool add(T x);
  T remove(T x);
  T find(T x);
  int size() {
    return n;
  }
  void clear();
  void SetLocalFactor(float param) {
    f = param;
  }
  ;
  void TestHash(int add_amt);
  int GetLongestList();
};

template<class T>
void ChainedHashTable<T>::TestHash(int add_amt) {
  for (int i = 0; i < add_amt; i++)
    add(rand() % 128);

  for (int i = 0; i < t.length; i++) {
    std::cout << "Bucket " << i << ": " << t[i].size() << " items" << endl;
  }
}

/**
 * FIXME:  A copy-constructor for arrays would be useful here
 */
template<class T>
void ChainedHashTable<T>::resize() {
  d = 1;
  while (1 << d <= n / f)
    d++;
  n = 0;
  array<List> newTable(1 << d);
  for (int i = 0; i < t.length; i++) {
    for (int j = 0; j < t[i].size(); j++) {
      T x = t[i].get(j);
      newTable[hash(x)].add(x);
      n++;
    }
  }
  t = newTable;
}

template<class T>
ChainedHashTable<T>::ChainedHashTable() :
    t(2) { // Objects must be initialized first (in "initializer list")
  srand(time(0));
  n = 0;
  d = 1; // starting dimension of size 2^d = 2^1
  null = INT_MIN;
  z = rand() | 1;     // is a random odd integer
  f = 1; // local factor set to 1
}

template<class T>
ChainedHashTable<T>::~ChainedHashTable() {
}

template<class T>
bool ChainedHashTable<T>::add(T x) {
  if (find(x) != null)
    return false;
  if (n + 1 > (t.length * f))
    resize();
  t[hash(x)].add(x);
  n++;
  return true;
}

template<class T>
T ChainedHashTable<T>::remove(T x) {
  int j = hash(x);
  for (int i = 0; i < t[j].size(); i++) {
    T y = t[j].get(i);
    if (x == y) {
      t[j].remove(i);
      n--;
      return y;
    }
  }
  return null;
}

template<class T>
T ChainedHashTable<T>::find(T x) {
  int j = hash(x);
  for (int i = 0; i < t[j].size(); i++)
    if (x == t[j].get(i))
      return t[j].get(i);
  return null;
}

template<class T>
void ChainedHashTable<T>::clear() {
  n = 0;
  d = 1;
  array<List> b(2);
  t = b;
}

template<class T>
int ChainedHashTable<T>::GetLongestList() {
  int largest_bucket = 0;

  for (int i = 0; i < t.length; i++) {
    if (t[i].size() > t[largest_bucket].size())
      largest_bucket = i;
  }

  return t[largest_bucket].size();
}

} /* namespace ods */

#endif /* NIHY_CHAINEDHASHTABLE_H_ */
