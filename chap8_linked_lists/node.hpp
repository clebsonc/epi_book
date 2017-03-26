#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include <memory>

template <typename T>
class Node{
  private:
    T value;
    std::shared_ptr<Node> next;

  public:
    Node();
    Node(T value);
    
    T getValue() const;
    void setValue(const T & value);

    std::shared_ptr<Node<T>> getNext() const;
    void setNext(std::shared_ptr<Node<T>> next);
};

template <typename T>
Node<T>::Node(){}

template <typename T>
Node<T>::Node(T value){
  this->value = value;
}

template <typename T>
T Node<T>::getValue() const{
  return this->value;
}

template <typename T>
void Node<T>::setValue(const T & value){
  this->value = value;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getNext() const{
  return this->next;
}

template <typename T>
void Node<T>::setNext(std::shared_ptr<Node<T>> next){
  this->next = next;
}

#endif

