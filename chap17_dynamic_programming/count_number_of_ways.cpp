#include <iostream>
#include <vector>

void printMatrix(const std::vector<std::vector<int>> & matrix){
  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix.at(i).size(); j++){
      std::cout << matrix.at(i).at(j) << "\t";
    }
    std::cout << std::endl;
  }
}


int computeWays(int r, int c, std::vector<std::vector<int>> & matrix){
  if (r == 0 || c == 0){
    matrix.at(r).at(c) = 1;
  }
  else if (matrix.at(r).at(c) == 0){
    int up = computeWays(r-1, c, matrix);
    int left = computeWays(r, c-1, matrix);
    matrix.at(r).at(c) = up + left;
  }
  return matrix.at(r).at(c);
}


int numberOfWaysTravelMatrix(int n, int m){
  std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));
  int possibilitities = computeWays(n-1, m-1, matrix);
  printMatrix(matrix);
  return possibilitities;
}


int main(){
  int nm = numberOfWaysTravelMatrix(1,1);
  std::cout << "Possible Ways: " << nm << std::endl;

  return 0;
}

