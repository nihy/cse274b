/*
 * nihy_dllist.h
 *
 *  Created on: Sep 25, 2014
 *      Author: Henry
 *
 * DLList.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef NIHY_DLLIST_H_
#define NIHY_DLLIST_H_

namespace ods {

template<class T>
class DLList {
protected:
  struct Node {
    T x;
    Node *prev, *next;
  };
  Node dummy;
  int n;
  void remove(Node *w);
  Node* addBefore(Node *w, T x);
  Node* getNode(int i);
public:
  DLList();
  virtual ~DLList();
  int size() { return n; }
  T get(int i);
  T set(int i, T x);
  virtual void add(int i, T x);
  virtual void add(T x) { add(size(), x); }
  virtual T remove(int i);
  virtual void clear();
  bool IsPalindrome();
  void Rotate(int r);
  void Absorb(DLList<T>& l2);
  DLList<T> Deal(DLList<T>& orig);
};


template<class T>
DLList<T>::DLList() {
  dummy.next = &dummy;
  dummy.prev = &dummy;
  n = 0;
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
  Node *u = new Node;
  u->x = x;
  u->prev = w->prev;
  u->next = w;
  u->next->prev = u;
  u->prev->next = u;
  n++;
  return u;
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
  Node* p;
  if (i < n / 2) {
    p = dummy.next;
    for (int j = 0; j < i; j++)
      p = p->next;
  } else {
    p = &dummy;
    for (int j = n; j > i; j--)
      p = p->prev;
  }
  return (p);
}


template<class T>
DLList<T>::~DLList() {
  clear();
}

template<class T>
void DLList<T>::clear() {
  Node *u = dummy.next;
  while (u != &dummy) {
    Node *w = u->next;
    delete u;
    u = w;
  }
  n = 0;
}



template<class T>
void DLList<T>::remove(Node *w) {
  w->prev->next = w->next;
  w->next->prev = w->prev;
  delete w;
  n--;
}


template<class T>
T DLList<T>::get(int i) {
  return getNode(i)->x;
}

template<class T>
T DLList<T>::set(int i, T x) {
  Node* u = getNode(i);
  T y = u->x;
  u->x = x;
  return y;
}

template<class T>
void DLList<T>::add(int i, T x) {
  addBefore(getNode(i), x);
}

template<class T>
T DLList<T>::remove(int i) {
  Node *w = getNode(i);
  T x = w->x;
  remove(w);
  return x;
}

template<class T>
bool DLList<T>::IsPalindrome() {
  Node *checkFront = dummy.next;
  Node *checkBack = dummy.prev;

  for (int i = 0; i < size()/2; i++) {
    if (checkFront->x != checkBack->x)
      return false;
    checkFront = checkFront->next;
    checkBack = checkBack->prev;
  }
  return true;
}

template<class T>
void DLList<T>::Rotate(int r) {
  Node* tmp = getNode(r%n); //getNode(n -(r%n) - 1);

  if (r%n > 0) {
    dummy.next->prev = dummy.prev;
    dummy.prev->next = dummy.next;

    dummy.next = tmp->next;
    dummy.prev = tmp;

    tmp->next->prev = &dummy;
    tmp->next = &dummy;
  }
}

template<class T>
void DLList<T>::Absorb(DLList<T>& l2) {
  Node* l1_last = getNode(size()-1);
  Node* l2_first = /*l2.getNode(0);*/l2.dummy.next;

  l1_last->next = l2_first;
  l2_first->prev = l1_last;
  l2.getNode(l2.size()-1)->next = &dummy;

  dummy.prev = l2.dummy.prev;
  l2.dummy.next = &dummy;
  l2.dummy.prev = &dummy;

  n += l2.n;
  l2.n = 0;

}

template<class T>
DLList<T> DLList<T>::Deal(DLList<T>& orig) {
  DLList<T> ret_list;
  Node* current = orig.getNode(1);
  Node* front;
  Node* back;

  for (int i = 0; i < orig.size(); i+=2) {
    if (current->next == &dummy)
      break;


    front = current->next->next;
    current->next->prev = current->prev;
    current->prev->next = current->next;

    current->next = &ret_list.dummy;
    ret_list.dummy.prev = current;

    if (i == 0) {
      ret_list.dummy.next = current;
      current->prev = &ret_list.dummy;
      n--;
    } else {
      back->next = current;
      current->prev = back;
      n--;
    }

    ret_list.n++;
    back = current;
    current = front;
  }

  return ret_list;
}
} /* namespace ods */

#endif /* NIHY_DLLIST_H_ */
