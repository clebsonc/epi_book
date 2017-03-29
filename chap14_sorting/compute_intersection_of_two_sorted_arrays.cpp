#include <iostream>
#include <vector>
#include <unordered_set>

std::unordered_set<int> find_intersection (std::vector<int> v1, std::vector<int> v2){
  std::unordered_set<int> uns;
  while (!v1.empty() && !v2.empty()){
    if (v1.back() == v2.back()){
      uns.emplace(v1.back());
      v1.pop_back();
      v2.pop_back();
    }
    else if (v1.back() > v2.back())
      v1.pop_back();
    else
      v2.pop_back();
  }
  return uns;
}


int main(){
  std::vector<int> v1 = {2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
  std::vector<int> v2 = {5, 5, 6, 8, 8, 9, 10, 10};
  std::unordered_set<int> set = find_intersection(v1, v2);
  for (const auto & v : set)
    std::cout << v << " ";
  std::cout << std::endl;

  return 0; 
}

