#include <iostream>
#include <vector>
#include <algorithm>

bool has_three_sum(std::vector<int> & v, int target){
  std::sort(v.rbegin(), v.rend());
  for (int i = 0; i <= v.size(); i++){
    for (int j = i; j < v.size(); j++){
      if(v.at(i) + v.at(j) > target) continue;
      for (int k = j; k < v.size(); k++){
        if (v.at(i) + v.at(j) + v.at(k) == target)
          return true;
      }
    }
  }
}


int main(){
  /**
  * Test cases
  */
  std::vector<int> values{11,2,5,7,3};
  bool t = has_three_sum(values, 34);
  if (t)
    std::cout << "Has three sum" << std::endl;
  else
    std::cout << "Do not have three sum" << std::endl;


  return 0;
}

