#include <iostream>
#include <vector>


void printLine(const std::vector<std::vector<int>> & matrix,
               const int begin, const int end, const int line, bool reverse){
  if (!reverse){
    for (int i = begin; i <= end; i++){
      std::cout << matrix.at(line).at(i) << " ";
    }
  } 
  else {
    for (int i = end; i >= begin; i--){
      std::cout << matrix.at(line).at(i) << " ";
    }
  }
}

void printColumn(const std::vector<std::vector<int>> & matrix,
               const int begin, const int end, const int column, bool reverse){
  if (!reverse){
    for (int i = begin; i <= end; i++){
      std::cout << matrix.at(i).at(column) << " ";
    }
  } 
  else {
    for (int i = end; i >= begin; i--){
      std::cout << matrix.at(i).at(column) << " ";
    }
  }
}

void aspiralPrint(const std::vector<std::vector<int>> & matrix, 
                  const int begin, const int end){
  if (begin > end){
    return;
  }
  else if (begin == end){
    std::cout << matrix.at(begin).at(end);
    return;
  }
  else {
    printLine(matrix, begin, end, begin, false);
    printColumn(matrix, begin+1, end, end, false);
    printLine(matrix, begin, end-1, end, true);
    printColumn(matrix, begin+1, end-1, begin, true);

    aspiralPrint(matrix, begin+1, end-1);
  }
  std::cout << std::endl;
}


void printMatrix(const std::vector<std::vector<int>> & matrix){
  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix.at(i).size(); j++){
      std::cout << matrix.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}

int main(){
  std::vector<std::vector<int>> matrix(5, std::vector<int>({1, 2, 3, 4, 5}));
  printMatrix(matrix);
  aspiralPrint(matrix, 0, matrix.size()-1);
    

  return 0;
}

