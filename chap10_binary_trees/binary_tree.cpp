#include <iostream>
#include <memory>
#include <cmath>

/**
* Binary search tree definition
*/
struct binary_search_tree{
  int value;
  std::unique_ptr<binary_search_tree> left;
  std::unique_ptr<binary_search_tree> right;
};


/**
* Performs a in order traversal:
* 1) visit left
* 2) visit root
* 3) visit right
*/ 
void in_order_traversal (const std::unique_ptr<binary_search_tree> & root){
  if (root){
    in_order_traversal(root->left);
    std::cout << root->value << std::endl;
    in_order_traversal(root->right);
  }
}


/**
* Insert values into the binary search tree maintaining the property that
* values smaller than the root lies on the left subtree and values greater 
* than the root lies on the right subtree.
*/
void insert_element(std::unique_ptr<binary_search_tree> & root, int value){
  if (!root){ // tree is empty
    root = std::unique_ptr<binary_search_tree>(new binary_search_tree);
    root->value = value;
  } else { // tree is not empty
    if (value <= root->value){
      insert_element(root->left, value);
    } else {
      insert_element(root->right, value);
    }
  }
}


/**
* Return the depth of the tree
*/
int get_tree_depth(const std::unique_ptr<binary_search_tree> & root){
  if(root){ // root not empty
    int left = 1 + get_tree_depth(root->left);
    int right = 1 + get_tree_depth(root->right);
    return std::max(left, right);
  }
  return 0;
}


/**
* Verify is the tree is height balanced
*/
bool is_height_balanced(const std::unique_ptr<binary_search_tree> & root){
  if(root){  // if tree is not empty
    int left = get_tree_depth(root->left);
    int right = get_tree_depth(root->right);
    int diff = std::abs(left - right);
    return ((diff == 0 || diff == 1) ? true : false);
  }
  return true;  // if the tree is empty, then it is balanced
}


int main(){
  std::unique_ptr<binary_search_tree> root;
  insert_element(root, 10);
  insert_element(root, 8);
  insert_element(root, 6);
  insert_element(root, 9);

  in_order_traversal(root);

  bool balanced = is_height_balanced(root);
  if(balanced)
    std::cout << "Balanced Tree" << std::endl;
  else
    std::cout << "Not Balanced Tree" << std::endl;

  return 0;
}
