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
    this->front = front;
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
  front->setNext(NULL);
  back = front;
}

template<typename Type>
void DynamicQueue <Type>::enqueue(Type x){
  back->setNext(new Node<Type>());
  back = back->getNext();
  back->setItem(x);
  back->setNext(NULL);
}

template<typename Type>
void DynamicQueue <Type>::dequeue(){
  Node<Type> * aux  = front;
  if(!emptyQueue()){
    front = front->getNext();
    delete aux;
  }else cout << "Empty Queue" << endl;
}

template<typename Type>
void DynamicQueue <Type>::showQueue(){
  Node<Type> * i  =  front->getNext();
  cout << "[ ";
  while(i!=NULL){
    cout << i->getItem() << " ";
    i = i->getNext();
  }
  cout << "]" << endl;
}

#endif
