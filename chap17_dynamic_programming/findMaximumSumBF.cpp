#include <iostream>
#include <vector>
#include <utility>

/**
* Find the subarray containing the maximum sum of elements of a given array.
* Prints out the maximum value of the subarray and return the pair container 
* with the member first and second having the start and end index of the 
* subarrays.
*/
std::pair<int, int> findMaximumSubArrayBruteForce(const std::vector<int> & v){
  int max = v.at(0);
  std::pair<int, int> index(0,0);
  for(int i = 0; i < v.size(); i++){
    int sum = 0;
    for(int j = i; j<v.size(); j++){
      sum += v.at(j);
      if(sum > max){
        index.first = i;
        index.second = j;
        max = sum;
      } // end if
    } // end for
  } // end for
  
  std::cout << "Max: " << max << std::endl;
  return index;
}

int main(){
  std::vector<int> v = {-904, 40, 523, 12, -335, -385, -124, 481, -31};
  std::pair<int, int> p = findMaximumSubArrayBruteForce(v);
  std::cout << "Subarray: ["<< p.first << ", " << p.second << "]" << std::endl;

  return 0;
}

