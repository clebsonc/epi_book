#include <iostream>
#include <queue>
#include <vector>


struct min_comparator{
  bool operator()(const int & a, const int & b){
    return a > b;
  }
};

std::vector<int> merge_set(const std::vector<std::vector<int>> & sorted_sets){
  std::priority_queue<int, std::vector<int>, min_comparator> pq;
  std::vector<int> mlist;
  for (std::vector<int> values : sorted_sets){
    for (auto v : values){
      pq.emplace(v);
    }
  }
  while (!pq.empty()){
    mlist.emplace_back(pq.top());
    pq.pop();
  }
  return mlist;
}



int main(){
  std::vector<int> a = {3, 5, 7};
  std::vector<int> b = {0, 6};
  std::vector<int> c = {0, 6, 28};
  std::vector<std::vector<int>> subset = {a, b, c};
  std::vector<int> list = merge_set(subset);
  for (auto v : list){
    std::cout << v << " ";
  }
  std::cout << std::endl;


  return 0;
}

