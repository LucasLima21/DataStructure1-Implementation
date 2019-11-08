#ifndef DynamicStack_h
#define DynamicStack_h
#include<iostream>
#include "Node.h"
using namespace std;
template<typename Type>
class DynamicStack{
private:
  Node<Type> * top , * bottom;
public:
  DynamicStack();

  Node<Type> * getTop(){
    return top;
  }
  void setTop(Node<Type> * top){
    this->top = top;
  }
  Node<Type> * getBottom(){
    return bottom;
  }
  void setBottom(Node<Type> * bottom){
    this->bottom = bottom;
  }
  
  void stackUp(Type);
  void unstack();
  void showStack();
  bool emptyStack();

};
template<typename Type>
bool DynamicStack<Type>::emptyStack(){
  return ((top == bottom)? 1 : 0);
}
template<typename Type>
DynamicStack<Type>::DynamicStack(){
  bottom = new Node<Type>();
  bottom->setNext(NULL);
  top = bottom;
}

template<typename Type>
void DynamicStack<Type>::stackUp(Type x){
  Node<Type> * aux = new Node<Type>();
  top->setItem(x);
  aux->setNext(top);
  top = aux;
}

template<typename Type>
void DynamicStack<Type>::unstack(){
  if(!emptyStack()){
    Node<Type> * aux = new Node<Type>();
    aux = top;
    top = top->getNext();
    delete aux;
  }
  else  cout << "Empty Stack" << endl;
}

template<typename Type>
void DynamicStack<Type>::showStack(){
  Node<Type> * i = top->getNext();
  
  while(i!= NULL){
    cout << "[ " << i->getItem()  << " ]" << endl;
    i = i->getNext();
  }
}

#endif
