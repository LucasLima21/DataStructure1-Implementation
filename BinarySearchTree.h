#ifndef BinarySearchTree_h
#define BinarSearchTree_h
#include "Node.h"
#include <iostream>
using namespace std;
template<typename Type>
class BinarySearchTree{
private:
  Node<Type> * root;
  void insert(Type &, Node<Type> *&);
  void remove(Type &, Node<Type> *&);
  void removeAux(Node<Type> *&, Node<Type> *&);
  void search(Type &, Node<Type> *&);
  void preOrderTreeWalk(Node<Type> *&);
  void inOrderTreeWalk(Node<Type> *&);
  void postOrderTreeWalk(Node<Type> *&);
public:
  BinarySearchTree(){
    root = NULL;
  }
  void insert(Type);
  void remove(Type);
  void search(Type);
  void preOrderTreeWalk();
  void inOrderTreeWalk();
  void postOrderTreeWalk();
  bool emptyTree();
};

template<typename Type>
bool BinarySearchTree<Type>::emptyTree(){
  return root == NULL;
}

template<typename Type>
void BinarySearchTree<Type>::search(Type item){
  search(item,root);
}

template<typename Type>
void BinarySearchTree<Type>::search(Type & item, Node<Type> *& pointer){
  if(pointer == NULL){
    cout << "Error: item not found " << endl;
  }
  else if(item > pointer->getItem()){
    search(item, pointer->getRight());
  }
  else if(item < pointer->getItem()){
    search(item, pointer->getLeft());
  }
  else{
    cout << "Item found: " << pointer->getItem() << endl;
  }
}

template<typename Type>
void BinarySearchTree<Type>::preOrderTreeWalk(){
  cout << "Pre Order Tree Walk = [ ";
  preOrderTreeWalk(root);
  cout << "]" << endl;
}


template<typename Type>
void BinarySearchTree<Type>::preOrderTreeWalk(Node<Type> *& pointer){
  if(pointer != NULL){
    cout << pointer->getItem() << " ";
    preOrderTreeWalk(pointer->getLeft());
    preOrderTreeWalk(pointer->getRight());
  }
}

template<typename Type>
void BinarySearchTree<Type>::inOrderTreeWalk(){
  cout << "In Order Tree Walk = [ ";
  inOrderTreeWalk(root);
  cout << "]" << endl;
}


template<typename Type>
void BinarySearchTree<Type>::inOrderTreeWalk(Node<Type> *& pointer){
  if(pointer != NULL){
    inOrderTreeWalk(pointer->getLeft());
    cout << pointer->getItem() << " ";
    inOrderTreeWalk(pointer->getRight());
  }
}

template<typename Type>
void BinarySearchTree<Type>::postOrderTreeWalk(){
  cout << "Post Order Tree Walk = [ ";
  postOrderTreeWalk(root);
  cout << "]" << endl;
}

template<typename Type>
void BinarySearchTree<Type>::postOrderTreeWalk(Node<Type> *& pointer){
  if(pointer != NULL){
    postOrderTreeWalk(pointer->getLeft());
    postOrderTreeWalk(pointer->getRight());
    cout << pointer->getItem() << " ";
  }
}

template<typename Type>
void BinarySearchTree<Type>::insert(Type item){
  insert(item, root);
}

template<typename Type>
void BinarySearchTree<Type>::insert(Type & item, Node<Type> *& pointer){
  if(pointer == NULL){
    pointer = new Node<Type>(item);
  }
  else if(item > pointer->getItem()){
    insert(item, pointer->getRight());
  }
  else if(item < pointer->getItem()){
    insert(item, pointer->getLeft());
  }
  else{
    cout << "Error: there is the same item in binary search tree !" << endl;
  }
}
template<typename Type>
void BinarySearchTree<Type>::remove(Type item){
  remove(item, root);
}

template<typename Type>
void BinarySearchTree<Type>::remove(Type & item, Node<Type> *& pointer){
  Node<Type> * aux = pointer;
  if(pointer == NULL){
    cout << "Error: item aren't in tree !" << endl;
  }
  else if(item < pointer->getItem()){
    remove(item, pointer->getLeft());
  }
  else if(item > pointer->getItem()){
    remove(item, pointer->getRight());
  }
  else if(pointer->getRight() == NULL){
    pointer = pointer->getLeft();
    delete aux;
  }
  else if(pointer->getLeft() == NULL){
    pointer = pointer->getRight();
    delete aux;
  }
  else{
    removeAux(pointer, pointer->getLeft());
  }
}

template<typename Type>
void BinarySearchTree<Type>::removeAux(Node<Type> *& q, Node<Type> *& r){
  if(r->getRight() != NULL){
    removeAux(q, r->getRight());
  }
  else if(r->getLeft() != NULL){
    removeAux(q, r->getLeft());
  }
  else{
    q->setItem(r->getItem());
    // q = r;
    r = r->getLeft();
    // delete q;
  }
}


#endif
