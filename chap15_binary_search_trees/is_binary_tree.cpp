#include "binary_search_tree.hpp"


bool is_binary_tree(const std::unique_ptr<Node> & root, int & last_visited){
  if(root->left == nullptr && root->right == nullptr){
    if(root->value > last_visited){
      last_visited = root->value;
      return true;
    }
    return false;
  }
  bool bleft, bright;
  if(root->left){
    bleft = is_binary_tree(root->left, last_visited);
    if(bleft == false)
      return false;
  }
  if(root->value > last_visited){
    last_visited = root->value;
  }
  else
    return false;
  if(root->right){
    bright = is_binary_tree(root->right, last_visited);
    if(bright==false)
      return false;
  }
  return true;
}

int main(){
  std::unique_ptr<Node> root;
  insert_element(root, 19);
  insert_element(root, 7);
  insert_element(root, 43);
  insert_element(root, 3);
  insert_element(root, 11);
  insert_element(root, 23);
  insert_element(root, 47);
  insert_element(root, 2);
  insert_element(root, 5);
  insert_element(root, 17);
  insert_element(root, 37);
  insert_element(root, 53);
  insert_element(root, 13);
  insert_element(root, 29);
  insert_element(root, 41);
  insert_element(root, 31);

  
  Node * a = search(root, 31);
  if(a){
    std::cout << a->value << std::endl;
    a->value = 32;
    std::cout << a->value << std::endl;
  }
  
  in_order_traversal(root);
  std::cout << std::endl;
  int v = std::numeric_limits<int>::min();
  bool isb = is_binary_tree(root, v);
  if(isb)
    std::cout << "Is binary" << std::endl;
  else
    std::cout << "Not binary tree" << std::endl;

  return 0;
}

