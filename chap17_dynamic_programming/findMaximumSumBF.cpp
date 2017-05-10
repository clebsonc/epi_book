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
std::pair<int, int> findMaximumSubArrayBruteForce(const std::vector<int> & v, 
                                                  int & max){
  max = v.at(0);
  std::pair<int, int> index(0,0);
  for(int i = 0; i < static_cast<int>(v.size()); i++){
    int sum = 0;
    for(int j = i; j < static_cast<int>(v.size()); j++){
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


std::pair<int, int> maximumValueMemoDP(std::vector<std::vector<int>> & memo,
                                       int & max){
  std::pair<int, int> index(0, 0);
  for (int i = 0; i < static_cast<int>(memo.size())-1; i++){
    for (int j = i+1; j < static_cast<int>(memo.size()); j++){
      memo.at(i).at(j) = memo.at(i).at(j-1) + memo.at(j).at(j);
      if (memo.at(i).at(j) > max){
        max = memo.at(i).at(j);
        index.first = i;
        index.second = j;
      }
    }
  }
  return index;
}


std::pair<int, int> findMaximumSubArrayMemoization(const std::vector<int> & v, 
                                                  int & val){
  std::vector<std::vector<int>> memo(v.size(), std::vector<int>(v.size(), 0));
  // initialize memo table
  for (int i = 0; i < static_cast<int>(v.size()); i++){
    memo.at(i).at(i) = v.at(i);
  }
  return maximumValueMemoDP(memo, val);
}


std::pair<int, int> findMaximumSubArrayDynamicProgramming(std::vector<int> v, 
                                                          int & val){
  int m = std::numeric_limits<int>::min()/2;
  int s = 0;
  int e = 0;
  for (int i = 0; i < static_cast<int>(v.size()); i++){
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
  std::vector<int> v = {904, 40, 523, 12, -335, -385, -124, 481, -31};
  //std::vector<int> v = {-20, 10, -1, 13};
  //std::vector<int> v = {-904, 40, 523, 12, -335};
  int max = 0;
  std::pair<int, int> p = findMaximumSubArrayBruteForce(v, max);
  std::cout << "Sub array: ["<< p.first << ", " << p.second << "] -- " << max << std::endl;
  max = 0;
  std::pair<int, int> t = findMaximumSubArrayDynamicProgramming(v, max);
  std::cout << "Sub array: ["<< t.first << ", " << t.second << "] -- " << max << std::endl;

  max = 0;
  std::pair<int, int> r = findMaximumSubArrayMemoization(v, max);
  std::cout << "Sub array: ["<< r.first << ", " << r.second << "] -- " << max << std::endl;
  


  return 0;
}

