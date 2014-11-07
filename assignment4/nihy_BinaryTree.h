/*
 * nihy_BinaryTree.h
 *
 *  Created on: Oct 27, 2014
 *      Author: Henry
 */

#ifndef NIHY_BINARYTREE_H_
#define NIHY_BINARYTREE_H_
#include <cstdlib>
#include <cmath>

#include "ArrayDeque.h"

using namespace std;
namespace ods {

template<class N>
class BTNode {
public:
  N *left;
  N *right;
  N *parent;
  BTNode() {
    left = right = parent = NULL;
  }
};

template<class Node>
class BinaryTree {
protected:
  Node *r;    // root node
  Node *nil;  // null-like node
  virtual int size(Node *u);
  virtual int height(Node *u);
  virtual void traverse(Node *u);
public:
  virtual ~BinaryTree();
  BinaryTree();
  BinaryTree(Node *nil);
  virtual void clear();
  virtual int depth(Node *u);
  virtual int size();
  virtual int size2();
  virtual int height();
  virtual void traverse();
  virtual void traverse2();
  virtual void bfTraverse();
  virtual int Height2(Node* u);
  bool isBalanced();
  int isBalanced(Node *u);
};

class BTNode1: public BTNode<BTNode1> {
};

template<class Node>
BinaryTree<Node>::~BinaryTree() {
  clear();
}

template<class Node>
void BinaryTree<Node>::clear() {
  Node *u = r, *prev = nil, *next;
  while (u != nil) {
    if (prev == u->parent) {
      if (u->left != nil)
        next = u->left;
      else if (u->right != nil)
        next = u->right;
      else
        next = u->parent;
    } else if (prev == u->left) {
      if (u->right != nil)
        next = u->right;
      else
        next = u->parent;
    } else {
      next = u->parent;
    }
    prev = u;
    if (next == u->parent)
      delete u;
    u = next;
  }
  r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree(Node *nil) {
  this->nil = nil;
  r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree() {
  nil = NULL;
  r = nil;
}

template<class Node>
int BinaryTree<Node>::depth(Node *u) {
  int d = 0;
  while (u != r) {
    u = u->parent;
    d++;
  }
  return d;
}

template<class Node>
int BinaryTree<Node>::size() {
  return size(r);
}

template<class Node>
int BinaryTree<Node>::size(Node *u) {
  if (u == nil)
    return 0;
  return 1 + size(u->left) + size(u->right);
}

template<class Node>
int BinaryTree<Node>::size2() {
  Node *u = r, *prev = nil, *next;
  int n = 0;
  while (u != nil) {
    if (prev == u->parent) {
      n++;
      if (u->left != nil)
        next = u->left;
      else if (u->right != nil)
        next = u->right;
      else
        next = u->parent;
    } else if (prev == u->left) {
      if (u->right != nil)
        next = u->right;
      else
        next = u->parent;
    } else {
      next = u->parent;
    }
    prev = u;
    u = next;
  }
  return n;
}

template<class Node>
int BinaryTree<Node>::Height2(Node* u) {
  Node *prev = nil, *next;
  int down = 1, up = 0;
   while (u != nil) {
     if (prev == u->parent) {
       if (u->left != nil)
         next = u->left;
       else if (u->right != nil)
         next = u->right;
       else
         next = u->parent;
     } else if (prev == u->left) {
       if (u->right != nil)
         next = u->right;
       else
         next = u->parent;
     } else {
       next = u->parent;
     }
     prev = u;
     u = next;

     if (up == 0) {
       if (u != prev->parent) // u must have traveled down to left or right
         down++;
       else // u traveled back up to parent
         up--;
     }
     else if (up > 0)  // u has traveled up before
       up--;
   }
   return up + down;
}

template<class Node>
int BinaryTree<Node>::height() {
  return Height2(r);
}

template<class Node>
int BinaryTree<Node>::height(Node *u) {
  if (u == nil)
    return -1;
  return 1 + max(height(u->left), height(u->right));
}

template<class Node>
void BinaryTree<Node>::traverse() {
  traverse(r);
}

template<class Node>
void BinaryTree<Node>::traverse(Node *u) {
  if (u == nil)
    return;
  traverse(u->left);
  traverse(u->right);
}

template<class Node>
void BinaryTree<Node>::traverse2() {
  Node *u = r, *prev = nil, *next;
  while (u != nil) {
    if (prev == u->parent) {
      if (u->left != nil)
        next = u->left;
      else if (u->right != nil)
        next = u->right;
      else
        next = u->parent;
    } else if (prev == u->left) {
      if (u->right != nil)
        next = u->right;
      else
        next = u->parent;
    } else {
      next = u->parent;
    }
    prev = u;
    u = next;
  }
}

template<class Node>
void BinaryTree<Node>::bfTraverse() {
  ArrayDeque<Node*> q;
  if (r != nil)
    q.add(q.size(), r);
  while (q.size() > 0) {
    Node *u = q.remove(q.size() - 1);
    if (u->left != nil)
      q.add(q.size(), u->left);
    if (u->right != nil)
      q.add(q.size(), u->right);
  }
}

template<class Node>
bool BinaryTree<Node>::isBalanced() {
  if (isBalanced(r) < 2)
    return true;
  return false;
}

template<class Node>
int BinaryTree<Node>::isBalanced(Node *u) {
  if (u == nil)
    return 0;
  int sizeLeft = isBalanced(u->left);
  int sizeRght = isBalanced(u->right);

  if (sizeLeft == -1 || sizeRght == -1)
    return 1+sizeLeft+sizeRght;

  if (u->left == nil || u->right == nil)
    return -1;
}


} /* namespace ods */

#endif /* NIHY_BINARYTREE_H_ */
