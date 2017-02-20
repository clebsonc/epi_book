#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <cmath>

/**
* Find the subarray containing the maximum sum of elements of a given array.
* Return the maximum subarray value indexes in the container pair
* with the member first and second having the start and end index of the 
* subarrays.
*/
std::pair<int, int> findMaximumSubArrayBruteForce(const std::vector<int> & v, int & max){
  max = v.at(0);
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
  
  return index;
}

std::pair<int, int> findMaximumSubArrayDynamicProgramming(std::vector<int> v, int & val){
  int m = std::numeric_limits<int>::min()/2;
  int s = 0;
  int e = 0;
  for (int i = 0; i < v.size(); i++){
    if(m+v.at(i) > v.at(i)){
      m = m+v.at(i);
      e = i;
    } 
    else{
      m = v.at(i);
      s = i;
      e = i;
    }
  }
  val = m;
  std::pair<int, int> p(s, e);
  return p;
}

int main(){
  //std::vector<int> v = {-904, 40, 523, 12, -335, -385, -124, 481, -31};
  std::vector<int> v = {-20, 10, -1, 13};
  //std::vector<int> v = {-904, 40, 523, 12, -335};
  int max = 0;
  std::pair<int, int> p = findMaximumSubArrayBruteForce(v, max);
  std::cout << "Subarray: ["<< p.first << ", " << p.second << "] -- " << max << std::endl;
  max = 0;
  std::pair<int, int> t = findMaximumSubArrayDynamicProgramming(v, max);
  std::cout << "Subarray: ["<< t.first << ", " << t.second << "] -- " << max << std::endl;

  return 0;
}

