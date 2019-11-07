#ifndef AVLTree_h
#define AVLTree_h
#include "Node.h"
#include <iostream>
using namespace std;
template<typename Type>
class AVLTree{
private:
  Node<Type> * root;
  bool height;
  void insert(Type &, Node<Type> *&, bool);
  void remove(Type &, Node<Type> *&);
  void removeAux(Node<Type> *&, Node<Type> *&);
  void search(Type &, Node<Type> *&);
  void preOrderTreeWalk(Node<Type> *&);
  void inOrderTreeWalk(Node<Type> *&);
  void postOrderTreeWalk(Node<Type> *&);
  void rightrightRotation(Node<Type> *&,Node<Type> *&);
  void leftleftRotation(Node<Type> *&,Node<Type> *&);
  void doubleRightLeftRotation(Node<Type> *&,Node<Type> *&,Node<Type> *&);
  void doubleLeftRightRotation(Node<Type> *&,Node<Type> *&,Node<Type> *&);
public:
  AVLTree(){
    root = NULL;
  }
  Node<Type> *& getRoot(){
    return root;
  }
  void setRoot(Node<Type> * root){
    this->root = root;
  }
  void insert(Type);
  void remove(Type);
  void search(Type);
  void preOrderTreeWalk();
  void inOrderTreeWalk();
  void postOrderTreeWalk();
  bool emptyTree();
  Type rootItem();
};

template<typename Type>
Type AVLTree<Type>::rootItem(){
  return getRoot()->getItem();
}

template<typename Type>
bool AVLTree<Type>::emptyTree(){
  return root == NULL;
}

template<typename Type>
void AVLTree<Type>::search(Type item){
  search(item,root);
}

template<typename Type>
void AVLTree<Type>::search(Type & item, Node<Type> *& pointer){
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
void AVLTree<Type>::preOrderTreeWalk(){
  cout << "Pre Order Tree Walk = [ ";
  preOrderTreeWalk(root);
  cout << "]" << endl;
}


template<typename Type>
void AVLTree<Type>::preOrderTreeWalk(Node<Type> *& pointer){
  if(pointer != NULL){
    cout << pointer->getItem() << " ";
    preOrderTreeWalk(pointer->getLeft());
    preOrderTreeWalk(pointer->getRight());
  }
}

template<typename Type>
void AVLTree<Type>::inOrderTreeWalk(){
  cout << "In Order Tree Walk = [ ";
  inOrderTreeWalk(root);
  cout << "]" << endl;
}


template<typename Type>
void AVLTree<Type>::inOrderTreeWalk(Node<Type> *& pointer){
  if(pointer != NULL){
    inOrderTreeWalk(pointer->getLeft());
    cout << pointer->getItem() << " ";
    inOrderTreeWalk(pointer->getRight());
  }
}

template<typename Type>
void AVLTree<Type>::postOrderTreeWalk(){
  cout << "Post Order Tree Walk = [ ";
  postOrderTreeWalk(root);
  cout << "]" << endl;
}

template<typename Type>
void AVLTree<Type>::postOrderTreeWalk(Node<Type> *& pointer){
  if(pointer != NULL){
    postOrderTreeWalk(pointer->getLeft());
    postOrderTreeWalk(pointer->getRight());
    cout << pointer->getItem() << " ";
  }
}

template<typename Type>
void AVLTree<Type>::insert(Type item){
  insert(item, root, height);
}

template<typename Type>
void AVLTree<Type>::insert(Type & item, Node<Type> *& pointer, bool height){
  Node<Type> * pointer1, * pointer2;
  if(pointer == NULL){
    pointer = new Node<Type>(item);
    height = true;
    pointer->setBalanceFactor(0);
    pointer->setCounter(1);
  }
  else if(pointer->getItem() > item){
    insert(item,pointer->getLeft(),height);
    if(height){
      if(pointer->getBalanceFactor() == 1){
        pointer->setBalanceFactor(0);
        height = false;
      }
      else if(pointer->getBalanceFactor() == 0){
        pointer->setBalanceFactor(-1);
      }
      else{
        pointer1 = pointer->getLeft();
        if(pointer1->getBalanceFactor() == -1){
          leftleftRotation(pointer,pointer1);
        }
        else{
          pointer2 = pointer1->getRight();
          doubleLeftRightRotation(pointer,pointer1,pointer2);
        }
        pointer->setBalanceFactor(0);
        height = false;
      }
    }
  }
  else if(pointer->getItem() < item){
    insert(item,pointer->getRight(),height);
    if(height){
      if(pointer->getBalanceFactor() == -1){
        pointer->setBalanceFactor(0);
        height = false;
      }
      else if(pointer->getBalanceFactor() == 0){
        pointer->setBalanceFactor(1);
      }
      else{
        pointer1 = pointer->getRight();
        if(pointer1->getBalanceFactor() == 1){
          rightrightRotation(pointer,pointer1);
        }
        else{
          pointer2 = pointer1->getLeft();
          doubleRightLeftRotation(pointer,pointer1,pointer2);
        }
        pointer->setBalanceFactor(0);
        height = false;
      }
    }
  }
  else{
    pointer->setCounter(pointer->getCounter() + 1);
    cout << "Error: there is the same item in binary search tree !" << endl;
  }
}

template<typename Type>
void AVLTree<Type>::remove(Type item){
  remove(item, root);
}

template<typename Type>
void AVLTree<Type>::remove(Type & item, Node<Type> *& pointer){
  Node<Type> * aux = pointer;
  if(pointer == NULL){
    cout << "Error: item isn't in tree !" << endl;
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
void AVLTree<Type>::removeAux(Node<Type> *& pointer, Node<Type> *& pointerLeft){
  if(pointerLeft->getRight() != NULL){
    removeAux(pointer, pointerLeft->getRight());
  }
  else{
    pointer->setItem(pointerLeft->getItem());
    pointerLeft = pointerLeft->getLeft();
  }
}


template<typename Type>
void AVLTree<Type>::leftleftRotation(Node<Type> *& pointer, Node<Type> *& pointer1){
  pointer->setLeft(pointer1->getRight());
  pointer1->setRight(pointer);
  pointer->setBalanceFactor(0);
  pointer = pointer1;
}
template<typename Type>
void AVLTree<Type>::rightrightRotation(Node<Type> *& pointer, Node<Type> *& pointer1){
  pointer->setRight(pointer1->getLeft());
  pointer1->setLeft(pointer);
  pointer->setBalanceFactor(0);
  pointer = pointer1;
}

template<typename Type>
void AVLTree<Type>::doubleLeftRightRotation(Node<Type> *& pointer, Node<Type> *& pointer1 , Node<Type> *& pointer2){
  pointer1->setRight(pointer2->getLeft());
  pointer2->setLeft(pointer1);
  pointer->setLeft(pointer2->getRight());
  pointer2->setRight(pointer);
  if(pointer2->getBalanceFactor() == -1){
    pointer->setBalanceFactor(1);
  }
  else{
    pointer->setBalanceFactor(0);
  }
  if(pointer2->getBalanceFactor() == 1){
    pointer1->setBalanceFactor(-1);
  }
  else{
    pointer1->setBalanceFactor(0);
  }
  pointer = pointer2;
}
template<typename Type>
void AVLTree<Type>::doubleRightLeftRotation(Node<Type> *& pointer, Node<Type> *& pointer1, Node<Type> *& pointer2){
  pointer1->setLeft(pointer2->getRight());
  pointer2->setRight(pointer1);
  pointer->setRight(pointer2->getLeft());
  pointer2->setLeft(pointer);
  if(pointer2->getBalanceFactor() == 1){
    pointer->setBalanceFactor(-1);
  }
  else{
    pointer->setBalanceFactor(0);
  }
  if(pointer2->getBalanceFactor() == -1){
    pointer1->setBalanceFactor(1);
  }
  else{
    pointer1->setBalanceFactor(0);
  }
  pointer = pointer2;
}
#endif
