#ifndef List_h
#define List_h
#include <iostream>
using namespace std;
template <typename Type>
class List{
private:
Type * item;
  int extent, n;
  bool validPosition(int);
  bool empty();

public:
  List (int extent) {
    n = 0;
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
  if(n < extent){
    item[n] = x;
    n++;
  }
  else  cout << "Full List! " << endl;
}

template <typename Type>
void List<Type>::print(){ 
  cout << "[ ";
  for(int i = 0; i < n-1; i++){
    cout << item[i] << " ";
  }
  cout << item[n-1];
  cout << " ]" << endl;
}

template <typename Type>
void List<Type>::printObject(){
  for (int i = 0; i < n-1 ; i++){
    item[i].print();
    cout << endl;
  }
  item[n-1].print();
  

}

template <typename Type>
Type * List<Type>::search(Type x){
  x = item[0];
  int i = n;
  while(x != item[i]) n--;
  if(i>0) return &item[i];
  else  return NULL;
}

template <typename Type>
bool List<Type>::validPosition(int pos){
  return 1 <= pos && pos <= n;
}

template <typename Type>
bool List<Type>::empty(){
  return n = 0;
}

template <typename Type>
void List<Type>::remove(int pos, Type &t){
  if(!empty() && validPosition(pos)){
    t = item[pos];
    for (int i = 0; i < n; i ++){
      item[i] = item[i+1];
    }
    n--;
  }else{
    cout << "Empty List or Invalid Position" << endl;
  }
}

#endif
