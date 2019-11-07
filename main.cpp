#include<iostream>
#include "List.h" 
#include "LinkedList.h"
#include "Stack.h"
#include "DynamicStack.h"
#include "Queue.h"
#include "DynamicQueue.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "HashTable.h"

using namespace std;
int main (){
    List<int> list1(4);
    list1.insert(3);
    list1.insert(-3);
    list1.insert(-3);
    list1.insert(3);
    cout << "Static List = ";
    list1.print();
    //////////////////////////////////////////////////////////////
    
    
    LinkedList<int> list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(33);
    list2.insert(666);
    cout << "\nLinked List = ";
    list2.print();
    cout << "------------"<< endl;
    Node<int> * r = list2.search(2);
    Node<int> * q = list2.search(1);
    list2.remove(r);
    list2.remove(q);
    cout << "\nLinked List = ";
    list2.print();
    ////////////////////////////////////////////////////////////
    
    Stack<float> p1(3);
    p1.stackUp(12.5);
    p1.stackUp(33.2);
    p1.stackUp(55.3);
    p1.unstack();
    cout << "\nStatic Stack = \n";
    p1.showStack();
    //////////////////////////////////////////////////////////////

    DynamicStack<string> p2;
    p2.stackUp("JOOOOOOOOOOOOOJ");
    p2.stackUp("IRINEU");
    p2.stackUp("IRINEU");
    p2.unstack();
    cout << "\nDynamic Stack = \n";
    p2.showStack();
    ///////////////////////////////////////////////////////////////

    Queue<float> f1(3);
    f1.enqueue(23123);
    f1.enqueue(333.321);
    f1.enqueue(666.213213);
    f1.dequeue();
    cout << "\nStaticQueue = ";
    f1.showQueue();

    ////////////////////////////////////////////////////////////////
    DynamicQueue<char> f2;
    f2.enqueue('a');
    f2.enqueue('n');
    f2.dequeue();
    f2.enqueue('e');
    f2.enqueue('w');
    f2.enqueue('b');
    cout << "\nDynamic Queue = ";
    f2.showQueue();

    /////////////////////////////////////////////////////////////////
    BinarySearchTree<int> treeOfNumbers;
    treeOfNumbers.insert(15);
    treeOfNumbers.insert(40);
    treeOfNumbers.insert(9);
    treeOfNumbers.insert(35);
    treeOfNumbers.insert(45);
    treeOfNumbers.insert(-1);
    treeOfNumbers.insert(0);
    treeOfNumbers.remove(40);
    cout << "\nBynary Search Tree = \n";
    treeOfNumbers.search(45);
    treeOfNumbers.preOrderTreeWalk();
    treeOfNumbers.inOrderTreeWalk();
    treeOfNumbers.postOrderTreeWalk();
    
    
    //////////////////////////////////////////////////////////////////
    AVLTree<int> avl;
    avl.insert(56);
    avl.insert(62);
    avl.insert(103);
    avl.insert(24);
    avl.insert(16);
    avl.insert(50);
    avl.insert(84);
    cout << "\nAVL Tree = \n";
    cout << avl.getRoot()->getRight()->getBalanceFactor() << endl;
    avl.preOrderTreeWalk();
    cout << endl;
    
    ////////////////////////////////////////////////////////////////

    HashTable<string> table(10);
    // in this table, type o table it's has to be string
    table.insertTable("aaaaa");
    table.insertTable("abbbba");
    table.insertTable("acccaa");
    table.insertTable("addddaa");
    table.insertTable("adeddeeeeaa");
    table.insertTable("aaffffaa");
    table.insertTable("ggggg");
    table.insertTable("hhhhh");
    table.insertTable("iiii");
    table.insertTable("jjjj");
    table.insertTable("kkkka");
    table.insertTable("llllla");
    table.insertTable("ammmmaa");
    table.insertTable("annnnna");
    cout << "HashTable = \n";
    table.showTable();
    cout << endl;
    table.searchTable("aaaaa");
    cout << endl;
    table.removeTable("aaaaa");
    cout << "After remove item" << endl;
    table.showTable();
    return 0;
}