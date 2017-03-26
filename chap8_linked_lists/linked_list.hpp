#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <iostream>

#include "node.hpp"


template <typename T>
class LinkedList{
  private:
    std::shared_ptr<Node<T>> ptr;

  public:
    LinkedList();
    void insertNode(T value);
    
    std::shared_ptr<Node<T>> search(T value) const;

    void modify_first_occurrence(T a, T b);

    void delete_first_ocurrence(T value);

    void printList() const;

    std::shared_ptr<Node<T>> getPtr();

    void setPtr(std::shared_ptr<Node<T>> & ptr);
};


template <typename T>
LinkedList<T>::LinkedList(){}

template <typename T>
void LinkedList<T>::insertNode(T value){
  if (ptr == nullptr){
    std::shared_ptr<Node<T>> node(new Node<T>(value));
    ptr=node;
  } else{
    std::shared_ptr<Node<T>> new_node(new Node<T>(value));
    new_node->setNext(ptr);
    ptr = new_node;
  }
}


template <typename T>
std::shared_ptr<Node<T>> LinkedList<T>::search(T value) const{
  std::shared_ptr<Node<T>> aux = ptr;
  while (aux != nullptr){
    if (aux->getValue() == value)
      return aux;
    aux = aux->getNext();
  }
  return nullptr;
}

template <typename T>
void LinkedList<T>::modify_first_occurrence(T a, T b){
  std::shared_ptr<Node<T>> aux = search(a);
  if (aux != nullptr)
    aux->setValue(b);
}

template <typename T>
void LinkedList<T>::delete_first_ocurrence(T value){
  if (ptr != nullptr){ // list not empty
      std::shared_ptr<Node<T>> aux1 = ptr->getNext();
      std::shared_ptr<Node<T>> aux2 = ptr;
      while (aux1 != nullptr && aux1->getValue() != value){
        aux2 = aux1;
        aux1 = aux1->getNext();
      } 
      if(aux1 != nullptr){ // value was found
        aux2->setNext( aux1->getNext());
        std::cout << "Before delete: " << aux1->getValue() << std::endl;
        aux1.reset();
      }
  }
}

template <typename T>
void LinkedList<T>::printList() const{
  std::shared_ptr<Node<T>> aux = ptr;
  while (aux != nullptr){
    std::cout << aux->getValue() << " ";
    aux = aux->getNext();
  }
  std::cout << std::endl;
}

template <typename T>
std::shared_ptr<Node<T>> LinkedList<T>::getPtr(){
  return this->ptr;
}


template <typename T>
void LinkedList<T>::setPtr(std::shared_ptr<Node<T>> & tr){
  this->ptr = ptr;
}

#endif
