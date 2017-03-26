#include "linked_list.hpp"

template <typename T>
void merge_list(LinkedList<T> & l1, LinkedList<T> & l2){
  std::shared_ptr<Node<T>> ptr1 = l1.getPtr();
  std::shared_ptr<Node<T>> ptr2 = l2.getPtr();

  std::shared_ptr<Node<T>> aux1;
  std::shared_ptr<Node<T>> aux2;
  std::shared_ptr<Node<T>> head;
  
  bool rl1 = ptr1->getValue() < ptr2->getValue() ? true : false;
  if (rl1)
    head = ptr1;
  else
    head = ptr2;

  while (ptr1 != nullptr && ptr2 != nullptr){
    rl1 = ptr1->getValue() < ptr2->getValue() ? true : false;
    if (rl1){
      aux1 = ptr1;
      while ( aux1 != nullptr && aux1->getValue() < ptr2->getValue()){
        aux2 = aux1;
        aux1 = aux1->getNext();
      }
      aux2->setNext(ptr2);
      ptr2 = ptr2->getNext();
    } 
    else {
      aux1 = ptr2;
      while ( aux1 != nullptr && aux1->getValue() < ptr1->getValue()){
        aux2 = aux1;
        aux1 = aux1->getNext();
      }
      aux2->setNext(ptr1);
      ptr1 = ptr1->getNext();
    }
    aux2 = aux2->getNext();
    aux2->setNext(aux1);
  }
  l1.setPtr(head);
}


