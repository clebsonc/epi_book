#include <iostream>
#include <string>
#include <algorithm>
#include <vector>





/**
* Find the longest subsequence using a matrix to cache computed subsequences.
*/
int computeLongestSubsequence(const std::string & s1, int a, 
                              const std::string & s2, int b,
                              std::vector<std::vector<int>> & msubsequence){
  if(a == s1.size() || b == s2.size())
    return 0;
  if(s1.at(a) == s2.at(b)){
    msubsequence.at(a).at(b) = 1 + computeLongestSubsequence(s1, a+1, s2, b+1, msubsequence);
  }
  else if(msubsequence.at(a).at(b) == -1){
    int decreaseA = computeLongestSubsequence(s1, a + 1, s2, b, msubsequence);
    int decreaseB = computeLongestSubsequence(s1, a, s2, b+1, msubsequence);
    msubsequence.at(a).at(b) = std::max(decreaseA, decreaseB);
  }
  return msubsequence.at(a).at(b);
}

void printMatrix(const std::string & s1, const std::string & s2,
                 const std::vector<std::vector<int>> & msubsequence){
  for (int i = 0; i < s2.size(); i++){
    std::cout << "\t" << s2.at(i);
  }
  std::cout << std::endl;
  for (int i = 0; i < s1.size(); i++){
    std::cout << s1.at(i) << "\t";
    for (int j = 0; j < s2.size(); j++){
      std::cout << msubsequence.at(i).at(j) << "\t";
    }
    std::cout << "\n";
  }
}

int longestSubsequence(const std::string & s1, const std::string & s2){
  std::vector<std::vector<int>> msubsequence(s1.size(), 
      std::vector<int>(s2.size(), -1));
  int cls = computeLongestSubsequence(s1, 0, s2, 0, msubsequence);
  printMatrix(s1, s2, msubsequence);
  return cls;
}




int main(){
  int ls = longestSubsequence("paralelepipedo", "paralelograma");
  std::cout << "longest subsequence: " << ls << std::endl;
  return 0;
}
