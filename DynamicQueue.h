#ifndef DynamicQueue_h
#define DynamicQueue_h
#include "Node.h"
#include <iostream>
using namespace std;
template<typename Type>
class DynamicQueue{
private:
  Node<Type> * front, * back;
public:
  DynamicQueue();

  Node<Type> * getFront(){
    return front;
  }
  void setFront(Node<Type> * front){
    this->frete = front;
  }
  Node<Type> * getBack(){
    return back;
  }
  void setBack(Node<Type> * back){
    this->back = back;
  }
  bool emptyQueue();
  void enqueue(Type);
  void dequeue();
  void showQueue();
};

template<typename Type>
bool DynamicQueue<Type>::emptyQueue(){
  return ((front == back)? 1 : 0);
}
template<typename Type>
DynamicQueue<Type>::DynamicQueue(){
  front = new Node<Type>();
  front->next = NULL;
  back = front;
}

template<typename Type>
void DynamicQueue <Type>::enqueue(Type x){
  back->next = new Node<Type>();
  back = back->next;
  back->item = x;
  back->next = NULL;
}

template<typename Type>
void DynamicQueue <Type>::dequeue(){
  Node<Type> * aux  = front;
  Type x;
  if(front!=back){
    front = front->next;
    x = front->item;
    delete aux;
  }else cout << "Empty Queue" << endl;
}

template<typename Type>
void DynamicQueue <Type>::showQueue(){
  Node<Type> * i  =  front->next;
  cout << "[ ";
  while(i!=NULL){
    cout << i->item << " ";
    i = i->next;
  }
  cout << "]" << endl;
}

#endif
