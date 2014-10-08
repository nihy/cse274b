//============================================================================
// Name        : nihy_asgnmt2.cpp
// Author      : Henry Ni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "nihy_dllist.h"

using namespace std;
using namespace ods;




template<class T>
void TestRotate(DLList<T>& list) {

  cout << "Before rotation: " << endl;
  for (int i = 0; i < list.size(); i++)
    cout << list.get(i) << endl;

  list.Rotate(6);

  cout << "After rotation: " << endl;
  for (int i = 0; i < list.size(); i++)
    cout << list.get(i) << endl;
}

template<class T>
void TestPalindrome(DLList<T>& list) {
  if (list.IsPalindrome())
    cout << "Is a palindrome" << endl;
  else
    cout << "Not a palindrome" << endl;
}

template<class T>
void TestAbsorb(DLList<T>& list1, DLList<T>& list2) {
  for (int i = 0; i < list1.size(); i++)
      cout << list1.get(i) << endl;

  cout << "END LIST 1, BEGIN LIST 2" << endl;

  for (int i = 0; i < list2.size(); i++)
      cout << list2.get(i) << endl;

  cout << "TEST ABSORB" << endl;

  list1.Absorb(list2);

  for (int i = 0; i < list1.size(); i++)
        cout << list1.get(i) << endl;

    cout << "END LIST 1, BEGIN LIST 2" << endl;

    for (int i = 0; i < list2.size(); i++)
        cout << list2.get(i) << endl;
}

template<class T>
void TestDeal(DLList<T>& list) {
  DLList<int> retList = list.Deal(list);

  for (int i = 0; i < retList.size(); i++)
    cout << retList.get(i) << endl;

  cout << "BREAK" << endl;

  for (int i = 0; i < list.size() / 2; i++) {
    cout << list.get(i) << endl;
  }

}

int main() {
  DLList<int>* list1 = new DLList<int>();
  DLList<int>* list2 = new DLList<int>();
  int size1 = 10, size2 = 5;

  for (int i = 0; i < size1; i++) {
    list1->add(i);
  }

  for (int i = 5; i < 5+size2; i++) {
    list2->add(i);
  }

  TestRotate(*list1);
  TestPalindrome(*list1);
  TestAbsorb(*list1, *list2);
  TestDeal(*list1);


return 0;
}

