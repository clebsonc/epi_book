#include <iostream>
#include <memory>
#include <limits>

struct Node{
  int value;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
};

void insert_element(std::unique_ptr<Node> & root, int value){
  if (root == nullptr){
    root = std::unique_ptr<Node>(new Node);
    root->value = value;
  }
  else if (value <= root->value){
    insert_element(root->left, value);
  }
  else{
    insert_element(root->right, value);
  }
}

void in_order_traversal(const std::unique_ptr<Node> & root){
  if (root){
    in_order_traversal(root->left);
    std::cout << root->value << " ";
    in_order_traversal(root->right);
  }
}

Node * search(std::unique_ptr<Node> & root, int k){
  if (root == nullptr)
    return nullptr;
  if (k == root->value)
    return root.get();
  if (k < root->value)
    search(root->left, k);
  else
    search(root->right, k);
}

