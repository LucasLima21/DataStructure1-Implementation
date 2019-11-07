#ifndef Queue_h
#define Queue_h
#include <iostream>
using namespace std;
template <typename Type>
class Queue{
private:
  int front, back;
  Type *item;
  int extent;
  bool fullQueue();
  bool emptyQueue();

public:
  Queue();
  Queue(int extent);
  void enqueue(Type);
  void dequeue();
  void showQueue();
};

template<typename Type>
Queue<Type>::Queue(){
  front = 0;
  back = front;
}

template<typename Type>
Queue<Type>::Queue(int extent){
  this->extent = extent+1;
  item = new Type[extent];
  front = 0;
  back = front;
}

template<typename Type>
bool Queue<Type>::fullQueue(){
  return (back+1)%extent == front;
}

template<typename Type>
bool Queue<Type>::emptyQueue(){
  return back == front;
}

template<typename Type>
void Queue<Type>::enqueue(Type x){
  if (fullQueue()){
    cout << "Full queue" << endl;
  }else{
    item[back] = x;
    back = (back+1)%extent;

  }
}

template<typename Type>
void Queue<Type>::dequeue(){

  if(emptyQueue()){
    cout <<"Empty queue" << endl;
  }
  else{

    front = (front+1)%extent;
  }
}


template<typename Type>
void Queue<Type>::showQueue(){
  cout << "[ ";
  for(int i = front; i < back; i++) cout << item[i] << " ";
  cout << "]" << endl; 
}

#endif
