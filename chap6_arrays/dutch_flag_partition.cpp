#include <iostream>
#include <vector>


void swap(std::vector<int> & array, int i, int j){
  int temp = array.at(i);
  array.at(i) = array.at(j);
  array.at(j) = temp;
}

void dutchFlagPartition(std::vector<int> & array, const int pivot){
  int smaller = 0;
  for(int i = 0; i < array.size(); i++){
    if(array.at(i) < pivot){
      swap(array, i, smaller);
      smaller++;
    }
  }
  int greater = array.size()-1;
  for(int i = greater; i >=0; i--){
    if(array.at(i) > pivot){
      swap(array, i, greater);
      greater--;
    }
  }
}


int main(){
  std::vector<int> elements = {10, 4, 2, 8, 1 , 5, 3, 2, 5, 3, 2, 4, 6, 1};
  dutchFlagPartition(elements, 3);
  for(int v : elements)
    std::cout << v << " ";
  std::cout << "\n";

  return 0;
}
