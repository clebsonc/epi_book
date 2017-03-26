#include <iostream>

#include "linked_list.hpp"
#include "merge_two_sorted_lists.cpp"

int main(){
  LinkedList<int> l1;
  LinkedList<int> l2;

  l1.insertNode(10);
  l1.insertNode(8);
  l1.insertNode(7);
  l1.insertNode(5);
  l1.insertNode(2);
  l1.insertNode(1);
  l1.printList();

  l2.insertNode(11);
  l2.insertNode(12);
  l2.insertNode(9);
  l2.insertNode(6);
  l2.insertNode(4);
  l2.insertNode(3);
  l2.printList();

  merge_list<int>(l1, l2);

  l1.printList();

  return 0;
}

