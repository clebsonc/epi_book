#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int compDistance(const std::string & s1, int a, const std::string & s2, int b,
    std::vector<std::vector<int>> & distancePrefixes){
  if (a == 0){ // chars of B is inserted
    return b;
  } else if (b == 0){ // chars of A is inserted
    return a;
  }
  if (s1.at(a-1) == s2.at(b-1)){ // last char of A equals last char of B
    return compDistance(s1, a-1, s2, b-1, distancePrefixes);
  }
  if(distancePrefixes.at(a-1).at(b-1) == -1){
    int subLastS1LastS2 = compDistance(s1, a-1, s2, b-1, distancePrefixes);
    int addLastOfS1inS2 = compDistance(s1, a, s2, b-1, distancePrefixes);
    int delLastCharOfS1 = compDistance(s1, a-1, s2, b, distancePrefixes);
    distancePrefixes.at(a-1).at(b-1) = 1 + std::min(delLastCharOfS1, 
      std::min(subLastS1LastS2, addLastOfS1inS2));
  }
  return distancePrefixes.at(a-1).at(b-1);
}


void printMatrix(const std::vector<std::vector<int>> & matrix){
  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix.at(0).size(); j++){
      std::cout << matrix.at(i).at(j) << "\t";
    }
    std::cout << "\n";
  }
}


int computeLevenshteinDistance(const std::string & s1, const std::string & s2){
  std::vector<std::vector<int>> distancePrefixes(s1.size(),
      std::vector<int>(s2.size(), -1));
  int d = compDistance(s1, s1.size(), s2, s2.size(), distancePrefixes);
  printMatrix(distancePrefixes);
  return d;
}


int main(){
  int a = computeLevenshteinDistance("orchestra", "carthorse");
  std::cout << "distance: " << a << std::endl;
  return 0;
}
