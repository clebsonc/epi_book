#include <iostream>
#include <vector>

/**
* Exercise 17.1
*/


void print2DVector(const std::vector<std::vector<int>> & map){
  std::cout << "size: " << map.size() << " " << map.at(0).size() << std::endl;
  for(int r = 0; r < map.size(); r++){
    for(int c = 0; c < map.begin()->size(); c++){
      std::cout << r << "|" << map.at(r).at(c) << "\t";
    }
    std::cout << std::endl;
  }
}




int compute_score(const int score, std::vector<std::vector<int>> & map, int index){
  if(score < 0){
    return 0;
  } else if (map.at(score).at(index) != -1){
    return map.at(score).at(index);
  } else {
    map.at(score).at(0) = compute_score(score-2, map, 0);
    map.at(score).at(1) = compute_score(score-3, map, 1) + map.at(score).at(0);
    map.at(score).at(2) = compute_score(score-7, map, 2) + map.at(score).at(1);
  }
  return map.at(score).at(index);
}



int numCombinationFinalScore(const int score){
  std::vector<std::vector<int>> map(score+1, std::vector<int>(3, -1));
  map.at(0).at(0) = 1;
  map.at(0).at(1) = 1;
  map.at(0).at(2) = 1;
  compute_score(score, map, 2);
  print2DVector(map);

  return map.at(score).at(2);
}


int main(){
  std::cout << "Computed: [n, " << numCombinationFinalScore(50) << "]" <<std::endl;


  return 0;
}

