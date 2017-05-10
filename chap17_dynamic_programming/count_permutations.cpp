#include <iostream>
#include <vector>

int fillMemoTable(std::vector<int> & memo, 
                  const std::vector<int> value, int n){
  if (n < 0) return 0;
  else if (memo.at(n) == -1){
    int sum = 0;
    for (int i = 0; i < value.size(); i++){
      sum += fillMemoTable(memo, value, n-value.at(i));
    }
    memo.at(n) = sum;
  }
  return memo.at(n);
}

int getPermutation(int n, const std::vector<int> & values){
  std::vector<int> memo(n+1, -1);
  memo.at(0) = 1;
  return fillMemoTable(memo, values, n);
}

int main(){
  std::vector<int> values({1, 2, 3});
  std::cout << getPermutation(4, values) << std::endl;

  return 0;
}

