#ifndef HashTable_h
#define HashTable_h
#include<iostream>
#include "AVLTree.h"
using namespace std;
template<typename Type>
class HashTable{
private:
  unsigned long int EXTENT;
  AVLTree<Type> * collisionTree;

public:
  unsigned long int getEXTENT(){
    return EXTENT;
  }
  void setEXTENT(unsigned long int EXTENT){
    this->EXTENT = EXTENT;
  }
  Type * getCollisionTree(){
    return collisionTree;
  }
  void setCollisionTree(Type * collisionTree){
    this->collisionTree = collisionTree;
  }

  HashTable(int);
  void insertTable(Type);
  void searchTable(Type);
  void removeTable(Type);
  void showTable();
  unsigned long int potency(int, int);
  unsigned long int hashingCode(Type);
};

template<typename Type>
HashTable<Type>::HashTable(int EXTENT){
  this->EXTENT = EXTENT;
  collisionTree = new AVLTree<Type>[EXTENT];
}

template<typename Type>
unsigned long int HashTable<Type>::potency(int base, int exponent){
  unsigned long int sumPotency = 1;
  for(int i = 0; i < exponent; i ++){
    sumPotency *= base;
    sumPotency %= getEXTENT();
  }
  return sumPotency;

}

template<typename Type>
unsigned long int HashTable<Type>::hashingCode(Type word){
  int wordExtent, exponent;
  unsigned long int save_asc_value = 0;
  wordExtent = (int)(word.size());
  exponent = wordExtent - 1;
  for(int i = 0; i < wordExtent; i++){
    save_asc_value += ((int)(tolower(word[i])) * potency(31,exponent))%getEXTENT();
    exponent--;
  }
  return save_asc_value%getEXTENT();

}
template<typename Type>
void HashTable<Type>::insertTable(Type word){
  unsigned long int position;
  position = hashingCode(word);
  collisionTree[position].insert(word);
}

template<typename Type>
void HashTable<Type>::searchTable(Type word){
  unsigned long int position;
  position = hashingCode(word);
  collisionTree[position].search(word);
}

template<typename Type>
void HashTable<Type>::removeTable(Type word){
  unsigned long int position;
  position = hashingCode(word);
  collisionTree[position].remove(word);
}

template<typename Type>
void HashTable<Type>::showTable(){
    cout << "TABLE" << endl;
    for (unsigned long int i = 0; i < EXTENT; i ++){
      cout << "word " << i << endl;
      collisionTree[i].inOrderTreeWalk();
      cout << endl;
    }
}


#endif
