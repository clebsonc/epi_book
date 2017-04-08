#include <iostream>
#include <vector>
#include <random>

void swap(std::vector<int> & values, int i, int j){
  int tmp = values.at(i);
  values.at(i) = values.at(j);
  values.at(j) = tmp;
}



/** Rearrange k subset of values in the kth first positions*/
void RandomSampling(std::vector<int> & values, const int k){
  std::default_random_engine seed((std::random_device())());
  for (int i = 0; i < k; i++){
    int rnd = std::uniform_int_distribution<int>{i, 
      static_cast<int>(values.size()-1)}(seed);
    swap(values, i, rnd);
  }
}

int main(){
  std::vector<int> values({5, 3, 4, 7, 8 , 9, 0});
  RandomSampling(values, 3);
  
  for ( auto v : values)
    std::cout << " " << v;
  std::cout << std::endl;

  return 0;
}
