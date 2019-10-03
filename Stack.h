#ifndef Stack_h
#define Stack_h
#include <iostream>
using namespace std;

template<typename Type>
class Stack{
private:
  Type * item; 
  int extent;
  int top, bottom;

public:
  Stack();
  Stack(int extent);
  void stackUp(Type);
  void unstack();
  void showStack();

};
template<typename Type>
Stack<Type>::Stack(){
  bottom = 0;
  top = bottom;
}

template<typename Type>
Stack<Type>::Stack(int extent){
  this->extent = extent+1;
  item = new Type[extent];
  bottom = 0;
  top = bottom;
}

template<typename Type>
void Stack<Type>::stackUp(Type x){
  if(top == extent) cout << "Full Stack!" << endl;
  else{
    top++;
    item[top] = x;
    }
}

template<typename Type>
void Stack<Type>::unstack(){
  if (top == bottom)  cout << "Empty Stack!" << endl;
  else{
    top--;
  }
}

template<typename Type>
void Stack<Type>::showStack(){
  cout << "[ " << item[top+1] << " ]" << " <- top"<< endl;
  for(int i = top; i > bottom+1; i--){
      cout << "[ " << item[i] << " ]" << endl;
  }
  cout << "[ " << item[bottom+1] << " ]" << " <- bottom" << endl;
}
#endif
