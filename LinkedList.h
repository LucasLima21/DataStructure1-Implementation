#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include "Node.h"
using namespace std;
template<typename Type>
class LinkedList{
private:
  Node<Type> * first, * last;
public:
  LinkedList();

  Node<Type> * getFirst(){
    return first;
  }
  void setFirst(Node<Type> * first){
    this->first = first;
  }
  Node<Type> * getLast(){
    return last;
  }
  void setLast(Node<Type> * last){
    this->last = last;
  }

  void insert(Type);
  Node<Type> * previous(Node<Type>*);
  bool empty();
  Node<Type> * search(Type);
  void remove(Node<Type>*);
  void print();

};
template <typename Type>
LinkedList<Type>::LinkedList() {
    first = new Node<Type>();
    first->next = NULL;
    last = first;

}


template <typename Type>
void LinkedList<Type>::insert(Type x){
  last->next = new Node<Type>();
  last = last->next;
  last->next = NULL;
  last->item = x;

}

template<typename Type>
Node<Type> * LinkedList<Type>::previous(Node<Type> * r){
    Node<Type>* p = first;
    while (p->next != r) p = p->next;
    return p;
}

template<typename Type>
bool LinkedList<Type>::empty(){
  return first == last;
}

template<typename Type>
Node<Type> * LinkedList<Type>::search(Type x){
  Node<Type> * p = first->next;
  while(p != NULL && p->item != x) p = p->next;

  return p;
}

template<typename Type>
void LinkedList<Type>::remove(Node<Type> * r){
  if(empty() || r == NULL || r == first)  cout << "Can not remove item" << endl;
  else{
    Node<Type> * p = previous(r);
    p->next = r->next;
    if(p->next == NULL) last = p;
    delete r;

  }
}

template<typename Type>
void LinkedList<Type>::print(){
  Node<Type> * p = first->next;
  cout << "[ ";
  while(p!=NULL){
    cout << p->item << " ";
    p = p->next;
  }
  cout << "]" << endl;
}

#endif
