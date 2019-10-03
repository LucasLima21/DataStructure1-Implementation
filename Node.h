#ifndef Node_h
#define Node_h
template <typename Type>
class Node{
public:
  Type item;
  Node<Type> * next, * left , * right;
  int balanceFactor, counter;
  Node();
  Node(Type);
  Node<Type> * getNext(){
    return next;
  }
  void setNext(Node<Type> * next){
    this->next = next;
  }
  Type getItem(){
    return item;
  }
  void setItem(Type item){
    this->item = item;
  }
  Node<Type> *& getLeft(){
    return left;
  }
  void setLeft(Node<Type> * left){
    this->left = left;
  }
  Node<Type> *& getRight(){
    return right;
  }
  void setRight(Node<Type> * right){
    this->right = right;
  }
  int getBalanceFactor(){
    return balanceFactor;
  }
  void setBalanceFactor(int balanceFactor){
    this->balanceFactor = balanceFactor;
  }
  int getCounter(){
    return counter;
  }
  void setCounter(int counter){
    this->counter = counter;
  }

};

template<typename Type>
Node<Type>::Node(){
  next = NULL;
  this->left = this->right = NULL;
}

template<typename Type>
Node<Type>::Node(Type item){
  this->item = item;
  next = NULL;
  this->left = this->right = NULL;
}

#endif