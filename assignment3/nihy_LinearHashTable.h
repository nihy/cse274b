/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef NIHY_LINEARHASHTABLE_H_
#define NIHY_LINEARHASHTABLE_H_
#include <climits>
#include <iostream>
#include <time.h>
using namespace std;
#include "array.h"

namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

  static const int w = 32;
  static const int r = 8;
  array<T> t; // "first" array
  array<T> s; // "second" array
  int n;   // number of values in T
  int q;   // number of non-null entries in T
  int d;   // t.length = 2^d
  int z;   // random odd number
  T null, del;
  void resize();
  int hash(T x) {
    return (unsigned) ((z * x) % ((2) * 1 << d));
  }
  int hash2(T x) {
    return 1 + (hash(x) % (((2) * 1 << d) - 1));
  }

public:
  LinearHashTable();
  LinearHashTable(T null, T del);
  virtual ~LinearHashTable();
  bool add(T x);
  bool addSlow(T x);
  T remove(T x);
  T find(T x);
  int size() {
    return n;
  }
  void clear();

  void setNull(T null) {
    this->null = null;
    t.fill(null);
  }
  void setDel(T del) {
    this->del = del;
  }
  void PrintTable(int add_amt);
  void EvenlyLoaded();
};

template<class T>
LinearHashTable<T>::LinearHashTable() :
    t(2), s(2) {
  this->null = null;
  this->del = del;
  srand(time(0));
  n = 0;
  q = 0;
  d = 1;
  z = rand() | 1;
}

template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) :
    t(2, null), s(2, null) {
  srand(time(0));
  this->null = null;
  this->del = del;
  n = 0;
  q = 0;
  d = 1;
  z = rand() | 1;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
  d = 1;
  while ((1 << d) < 3 * n)
    d++;
  T insert = null; // the value to be inserted, default is null
  int updated_size = (1 << d) / 2;
  int both_len = t.length + s.length;
  int probe; // to be used in search function later
  array<T> new_s(updated_size, null);
  array<T> new_t(updated_size, null);
  q = n;

  for (int c = 0; c < both_len; c++) {
    if (c < t.length)
      insert = t[c];
    else
      insert = s[c - t.length];

    // if insert is a data value from smaller array:
    if (insert != null && insert != del) {
      int i = 0;
      probe = ((hash(insert) + i * hash2(insert)) % (both_len));

      // begin re-insertion with standard dual-array search conditions
      while ((probe < new_t.length && new_t[probe] != null)
          || (probe >= new_s.length && new_s[probe - new_t.length] != null)) {
        i = (i == both_len - 1) ? 0 : i + 1;
        probe = ((hash(insert) + i * hash2(insert)) % (both_len));
      }
      if (probe < new_t.length)
        new_t[probe] = insert;
      else
        new_s[probe] = insert;
    }
  }
  t = new_t;
  s = new_s;
}

template<class T>
void LinearHashTable<T>::clear() {
  n = 0;
  q = 0;
  d = 1;
  array<T> new_t(2, null);
  array<T> new_s(2, null);
  t = new_t;
  s = new_s;
}

/**
 * TODO: convert methods to accommodate left, right arrays
 */
template<class T>
bool LinearHashTable<T>::add(T x) {
  int both_len = t.length + s.length;
  if (find(x) != null)
    return false;
  if (2 * (q + 1) > both_len)
    resize();   // max 50% occupancy
  int i = 0;
  int probe = (hash(x) + (i * hash2(x))) % both_len;
  while ((probe < t.length && t[probe] != null && t[probe] != del)
      || (probe >= t.length && s[probe - t.length] != null
          && s[probe - t.length] != del)) {

    i = (i == both_len - 1) ? 0 : i + 1; // increment i
    probe = ((hash(x) + i * hash2(x)) % (both_len));
  }

  if (probe >= t.length) {
    if (s[probe - t.length] == null)
      q++;
    s[probe - t.length] = x;
  }
  if (probe < t.length) {
    if (t[probe] == null)
      q++;
    t[probe] = x;
  }
  n++;
  return true;
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
  int both_len = t.length + s.length;
  int insert = null;
  if (2 * (q + 1) > t.length)
    resize();   // max 50% occupancy
  int i = 0;
  int probe = (hash(x) + (i * hash2(x))) % both_len;

  if (probe < t.length)
    insert = t[probe];
  else
    insert = s[probe - t.length];

  while (insert != null) {
    if (insert == x && insert != del) // does insert already exist in table?
      return false;
    if (probe < t.length)
      insert = t[probe];
    else
      insert = s[probe - t.length];

    i = (i == both_len - 1) ? 0 : i + 1; // increment i
    probe = (hash(x) + (i * hash2(x))) % both_len;
  } // probe has value that is non-null, non-del in SOME table

  if (probe < t.length)
    t[probe] = x;
  else if (probe >= t.length)
    s[probe - t.length] = x;
  n++;
  q++;
  return true;
}

template<class T>
T LinearHashTable<T>::find(T x) {
  int both_len = t.length + s.length;
  int i = 0;
  int probe = (hash(x) + (i * hash2(x))) % (both_len);

  while ((probe < t.length && t[probe] != null)
      || (probe >= t.length && s[probe - t.length] != null)) {
    if (probe < t.length && t[probe] != del && t[probe] == x)
      return t[probe];
    if (probe > t.length && s[probe - t.length != del]
        && s[probe - t.length] == x)
      return s[probe - t.length];
    {
      i = (i == both_len - 1) ? 0 : i + 1; // increment i
      probe = (hash(x) + (i * hash2(x))) % (both_len);
    }
  }

  return null;

}

template<class T>
T LinearHashTable<T>::remove(T x) {
  int both_len = t.length + s.length;
  T remove = null;
  int i = 0;
  int probe = (hash(x) + (i * hash2(x))) % (1 << d);
  if (probe < t.length)
    remove = t[probe];
  else
    remove = s[probe - t.length];
  while (remove != null) {
    T y = remove;
    if (x == y && y != del) {
      if (probe >= t.length)
        s[probe - t.length] = del;
      if (probe < t.length)
        t[probe] = del;

      n--;

      if (8 * n < t.length)
        resize(); // min 12.5% occupancy
      return y;
    }
    i = (i == t.length - 1) ? 0 : i + 1;  // increment i
    probe = ((hash(x) + i * hash2(x)) % (both_len));

    if (probe < t.length)
      remove = t[probe];
    else
      remove = s[probe - t.length];
  }
  return null;
}

template<class T>
void LinearHashTable<T>::PrintTable(int add_amt) {
  for (int i = 0; i < add_amt; i++) {
    int added = (unsigned) rand() % 100;
    add(added);
  }
  for (int i = 0; i < t.length; i++)
    cout << "t[" << i << "] = " << t[i] << endl;

  for (int i = 0; i < s.length; i++)
    cout << "s[" << i << "] = " << s[i] << endl;
}

template<class T>
void LinearHashTable<T>::EvenlyLoaded() {
  int null_t = 0;
  int values_t = 0;
  int null_u = 0;
  int values_u = 0;
  for (int i = 0; i < t.length; i++) {
    if (t[i] == null)
      null_t++;
    if (t[i] != null && t[i] != del)
      values_t++;
  }

  for (int i = 0; i < s.length; i++) {
    if (s[i] == null)
      null_u++;
    if (s[i] != null && s[i] != del)
      values_u++;
  }

  cout << "voids in list t: " << null_t << endl;
  cout << "voids in list s: " << null_u << endl;
  cout << "values in list t: " << values_t << endl;
  cout << "values in list s: " << values_u << endl;
}
}

#endif NIHY_LINEARHASHTABLE_H_

