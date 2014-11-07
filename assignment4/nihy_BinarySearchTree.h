/*
 * nihy_BinarySearchTree.h
 *
 *  Created on: Oct 28, 2014
 *      Author: Henry
 */

#ifndef NIHY_BINARYSEARCHTREE_H_
#define NIHY_BINARYSEARCHTREE_H_
#include <climits>
#include <cmath>
#include "nihy_BinaryTree.h"
#include "utils.h"
#include "DLList.h"

namespace ods {

template<class Node, class T>
class BSTNode : public BTNode<Node> {
public:
  T x;
  int pre_order;
  int in_order;
  int pst_order;
};

/**
 * A binary search tree class.  The Node parameter should be a subclass
 * of BSTNode<T> (or match it's interface)
 */
template<class Node, class T>
class BinarySearchTree : public BinaryTree<Node> {

protected:
  using BinaryTree<Node>::r;
  using BinaryTree<Node>::nil;
  int n;
  T null;
  bool keepChecking;
  int order_number;
  virtual Node *findLast(T x);
  virtual bool addChild(Node *p, Node *u);
  virtual void splice(Node *u);
  virtual void remove(Node *u);
  virtual void rotateRight(Node *u);
  virtual void rotateLeft(Node *u);
  virtual bool add(Node *u);
public:
  BinarySearchTree();
  BinarySearchTree(T null);
  virtual ~BinarySearchTree();
  virtual bool add(T x);
  virtual bool remove(T x);
  virtual T find(T x);
  Node* getNode(T x);
  virtual T findEQ(T x);
  virtual int size();
  virtual void clear();
  void preOrderNumber();
  void preOrderNumber(Node* u);
  void inOrderNumber();
  void inOrderNumber(Node* u);
  void postOrderNumbers();
  void postOrderNumbers(Node* u);
  DLList<T> getLE(T comp);
  void getLE(Node* u, DLList<T>* list, T comp);
};

template<class T>
class BSTNode1 : public BSTNode<BSTNode1<T>, T> { };

template<class T>
class BinarySearchTree1 : public BinarySearchTree<BSTNode1<T>, T> {
public:
  BinarySearchTree1();
};


/*
 * FIXME: Why doesn't this work?
template<class Node>
BinarySearchTree<Node,int>::BinarySearchTree()  {
  this->null = INT_MIN;
  n = 0;
}
*/

template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree() {
  this->null = (T)NULL;  // won't work for non-primitive types
  n = 0;
}


template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree(T null) {
  this->null = null;
  n = 0;
}

template<class Node, class T>
Node* BinarySearchTree<Node,T>::findLast(T x) {
  Node *w = r, *prev = nil;
  while (w != nil) {
    prev = w;
    int comp = compare(x, w->x);
    if (comp < 0) {
      w = w->left;
    } else if (comp > 0) {
      w = w->right;
    } else {
      return w;
    }
  }
  return prev;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::findEQ(T x) {
  Node *w = r;
  while (w != nil) {
    int comp = compare(x, w->x);
    if (comp < 0) {
      w = w->left;
    } else if (comp > 0) {
      w = w->right;
    } else {
      return w->x;
    }
  }
  return null;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::find(T x) {
  Node *w = r, *z = nil;
  while (w != nil) {
    int comp = compare(x, w->x);
    if (comp < 0) {
      z = w;
      w = w->left;
    } else if (comp > 0) {
      w = w->right;
    } else {
      return w->x;
    }
  }
  return z == nil ? null : z->x;
}

template<class Node, class T>
Node* BinarySearchTree<Node, T>::getNode(T x) {
  Node *w = r, *z = nil;
   while (w != nil) {
     int comp = compare(x, w->x);
     if (comp < 0) {
       z = w;
       w = w->left;
     } else if (comp > 0) {
       w = w->right;
     } else {
       return w;
     }
   }
   return nil;
}

template<class Node, class T>
BinarySearchTree<Node,T>::~BinarySearchTree() {
  // nothing to do - BinaryTree destructor does cleanup
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::addChild(Node *p, Node *u) {
    if (p == nil) {
      r = u;              // inserting into empty tree
    } else {
      int comp = compare(u->x, p->x);
      if (comp < 0) {
        p->left = u;
      } else if (comp > 0) {
        p->right = u;
      } else {
        return false;   // u.x is already in the tree
      }
      u->parent = p;
    }
    n++;
    return true;
  }

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(T x) {
  Node *p = findLast(x);
  Node *u = new Node;
  u->x = x;
  return addChild(p, u);
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(Node *u) {
  Node *p = findLast(u->x);
  return addChild(p, u);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::splice(Node *u) {
  Node *s, *p;
  if (u->left != nil) {
    s = u->left;
  } else {
    s = u->right;
  }
  if (u == r) {
    r = s;
    p = nil;
  } else {
    p = u->parent;
    if (p->left == u) {
      p->left = s;
    } else {
      p->right = s;
    }
  }
  if (s != nil) {
    s->parent = p;
  }
  n--;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::remove(Node *u) {
  if (u->left == nil || u->right == nil) {
    splice(u);
    delete u;
  } else {
    Node *w = u->right;
    while (w->left != nil)
      w = w->left;
    u->x = w->x;
    splice(w);
    delete w;
  }
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::remove(T x) {
  Node *u = findLast(x);
  if (u != nil && compare(x, u->x) == 0) {
    remove(u);
    return true;
  }
  return false;
}

template<class Node, class T> inline
int BinarySearchTree<Node, T>::size() {
  return n;
}

template<class Node, class T> inline
void BinarySearchTree<Node, T>::clear() {
  BinaryTree<Node>::clear();
  n = 0;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateLeft(Node *u) {
  Node *w = u->right;
  w->parent = u->parent;
  if (w->parent != nil) {
    if (w->parent->left == u) {
      w->parent->left = w;
    } else {
      w->parent->right = w;
    }
  }
  u->right = w->left;
  if (u->right != nil) {
    u->right->parent = u;
  }
  u->parent = w;
  w->left = u;
  if (u == r) { r = w; r->parent = nil; }
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateRight(Node *u) {
  Node *w = u->left;
  w->parent = u->parent;
  if (w->parent != nil) {
    if (w->parent->left == u) {
      w->parent->left = w;
    } else {
      w->parent->right = w;
    }
  }
  u->left = w->right;
  if (u->left != nil) {
    u->left->parent = u;
  }
  u->parent = w;
  w->right = u;
  if (u == r) { r = w; r->parent = nil; }
}

template<class Node, class T>
void BinarySearchTree<Node, T>::preOrderNumber() {
  order_number = 0;
  preOrderNumber(r);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::preOrderNumber(Node* u) {
  if (u == nil)
    return;

  order_number++;

  u->pre_order = order_number;
  preOrderNumber(u->left);
  preOrderNumber(u->right);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::inOrderNumber() {
  inOrderNumber(r);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::inOrderNumber(Node* u) {
  if (u == nil)
    return;

  order_number++;

  inOrderNumber(u->left);
  u->in_order = order_number;
  ineOrderNumber(u->right);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::postOrderNumbers() {
  order_number = 0;
  postOrderNumbers(r);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::postOrderNumbers(Node* u) {
  if (u == nil)
    return;

  order_number++;

  postOrderNumbers(u->left);
  postOrderNumbers(u->right);
  u->pst_order = order_number;
}


template<class Node, class T>
DLList<T> BinarySearchTree<Node, T>::getLE(T comp) {
  DLList<T> ret;
  keepChecking = true;
  getLE(r, &ret, comp);
  return ret;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::getLE(Node* u, DLList<T>* list, T comp) {
  if (u == nil)
    return;
  if (!keepChecking)
    return;

  getLE(u->left, list, comp);

  if (compare(u->x, comp) <= 0)
      list->add(u->x);

  getLE(u->right, list, comp);
}
/*
template<class T>
BinarySearchTree1<T*>::BinarySearchTree1() : BinarySearchTree<BSTNode1<T*>, T*>(NULL) {
}
*/

template<class T>
BinarySearchTree1<T>::BinarySearchTree1()  {
}


} /* namespace ods */




#endif /* NIHY_BINARYSEARCHTREE_H_ */
