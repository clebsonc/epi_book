#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


int compMinDeletionsToPalindrome(const std::string & s, int a, int b,
      std::vector<std::vector<int>> & mDeletions){
  if (a == b){
    return 0;
  }
  if (s.at(a) == s.at(b)){
    mDeletions.at(a).at(b) = compMinDeletionsToPalindrome(s, a+1, b-1, mDeletions);
  }
  else if (mDeletions.at(a).at(b) == -1){
    int removePrefix = 1 + compMinDeletionsToPalindrome(s, a+1, b, mDeletions);
    int removeSuffix = 1 + compMinDeletionsToPalindrome(s, a, b-1, mDeletions);
    mDeletions.at(a).at(b) = std::min(removePrefix, removeSuffix);
  }
  return mDeletions.at(a).at(b);
}


void printMatrix(const std::vector<std::vector<int>> & mDeletions, const std::string & s){
  for(char c : s)
    std::cout << "\t" << c;
  std::cout << std::endl;
  for(int i = 0; i < s.size(); i++){
    std::cout << s.at(i) << "\t";
    for(int j = 0; j < s.size(); j++){
      if (mDeletions.at(i).at(j) == -1)
        std::cout << "  \t";
      else
        std::cout << mDeletions.at(i).at(j) << "\t";
    }
    std::cout << std::endl;
  }
}

int minDeletionsToPalindrome(std::string s){
  std::vector<std::vector<int>> mDeletions(s.size(), std::vector<int>(s.size(), -1));
  int cmdp = compMinDeletionsToPalindrome(s, 0, s.size()-1, mDeletions);
  printMatrix(mDeletions, s);
  return cmdp;
}


int main(){
  std::string s = "paralelogramaparalelepipedo";
  int mdp = minDeletionsToPalindrome(s);
  std::cout << "min deletions: " << mdp << std::endl;

  return 0;
}
