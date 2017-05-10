#include <iostream>
#include <vector>

void print2DVector(const std::vector<std::vector<int>> & map){
  std::cout << "size: " << map.size() << " " << map.at(0).size() << std::endl;
  for(int r = 0; r < map.size(); r++){
    for(int c = 0; c < map.begin()->size(); c++){
      std::cout << r << "|" << map.at(r).at(c) << "\t";
    }
    std::cout << std::endl;
  }
}

int compute_score(const int score, std::vector<std::vector<int>> & map, 
    int index, const std::vector<int> & values){
  if(score < 0){
    return 0;
  } else if (map.at(score).at(index) != -1){
    return map.at(score).at(index);
  } else {
    for(int i = 0; i < values.size(); i++){
      if (i == 0){
        map.at(score).at(i) = compute_score(score-values.at(i), map, i, values);
      } else {
        map.at(score).at(i) = compute_score(score-values.at(i), map, i, values) + map.at(score).at(i-1);
      }
    }
  }
  return map.at(score).at(index);
}

int DPMemoMaximumScore(std::vector<std::vector<int>> & memo, int n, 
                        const std::vector<int> & values, int index){
  if (n < 0) return 0;
  else if (memo.at(n).at(index) == -1){
    int biggerValue = DPMemoMaximumScore(memo, n-values.at(index), values, index);
    if (index == 0){
      memo.at(n).at(index) = biggerValue;
    } else {
      int smallerValue = DPMemoMaximumScore(memo, n, values, index-1);
      memo.at(n).at(index) = biggerValue + smallerValue;
    }
  }
  return memo.at(n).at(index);
}


int numCombinationFinalScore(const int score, const std::vector<int> & values){
  std::vector<std::vector<int>> map(score+1, std::vector<int>(values.size(), -1));
  for(int i = 0; i < values.size(); i++){
    map.at(0).at(i) = 1;
  }
  compute_score(score, map, values.size()-1, values);
  print2DVector(map);

  return map.at(score).at(values.size()-1);
}

int numCombinationFinalScore1(const int score, const std::vector<int> & values){
  std::vector<std::vector<int>> memo(score+1, std::vector<int>(values.size(), -1));
  for(int i = 0; i < values.size(); i++){
    memo.at(0).at(i) = 1;
  }
  DPMemoMaximumScore(memo, score, values, values.size()-1);
  print2DVector(memo);

  return memo.at(score).at(values.size()-1);
}

int main(){
  std::cout << "Computed: [n, " << numCombinationFinalScore(4, std::vector<int>{1, 2, 3}) << "]" <<std::endl;
  std::cout << "Second Approach" << std::endl;
  std::cout << "Computed: [n, " << numCombinationFinalScore1(4, std::vector<int>{1, 2, 3}) << "]" <<std::endl;


  return 0;
}

