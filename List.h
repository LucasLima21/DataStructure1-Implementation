#ifndef List_h
#define List_h
#include <iostream>
using namespace std;
template <typename Type>
class List{
private:
Type * item;
  int extent, initialPosition;
  bool validPosition(int);
  bool empty();

public:
  List (int extent) {
    initialPosition = 0;
    this->extent = extent;
    item = new Type[extent];
  }
  void insert(Type);
  void print();
  Type * search(Type);
  void remove(int, Type&);
  void printObject();
};


template <typename Type>
void List<Type>::insert(Type x){
  if(initialPosition < extent){
    item[initialPosition] = x;
    initialPosition++;
  }
  else  cout << "Full List! " << endl;
}

template <typename Type>
void List<Type>::print(){ 
  cout << "[ ";
  for(int i = 0; i < initialPosition-1; i++){
    cout << item[i] << " ";
  }
  cout << item[initialPosition-1];
  cout << " ]" << endl;
}

template <typename Type>
void List<Type>::printObject(){
  for (int i = 0; i < initialPosition-1 ; i++){
    item[i].print();
    cout << endl;
  }
  item[initialPosition-1].print();
  

}

template <typename Type>
Type * List<Type>::search(Type x){
  x = item[0];
  int i = initialPosition;
  while(x != item[i]) initialPosition--;
  if(i>0) return &item[i];
  else  return NULL;
}

template <typename Type>
bool List<Type>::validPosition(int pos){
  return 1 <= pos && pos <= initialPosition;
}

template <typename Type>
bool List<Type>::empty(){
  return initialPosition == 0;
}

template <typename Type>
void List<Type>::remove(int pos, Type &t){
  if(!empty() && validPosition(pos)){
    t = item[pos];
    for (int i = 0; i < initialPosition; i ++){
      item[i] = item[i+1];
    }
    initialPosition--;
  }else{
    cout << "Empty List or Invalid Position" << endl;
  }
}

#endif
