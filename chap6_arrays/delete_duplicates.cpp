#include <iostream>
#include <vector>


int deleteDuplicates(std::vector<int> & v){
  if(v.empty()){
    return -1;
  }
  int i = 1;
  int j = 0;
  if(v.size() > 1){
    while(i < v.size()){
      if(v.at(i) != v.at(j)){
        j++;
        if( j!= i)
          v.at(j) = v.at(i);
        i++;
      }
      else{
        while(i < v.size() && v.at(i) == v.at(j)){
          i++;
        }
      }
    }
  }
  return j;
}


int main(){
  std::vector<int> elem = {2,2,2,2,2,2,4,4,4,5,6,6,6,6,6};
  int d = deleteDuplicates(elem);

  for(int i = 0; i <= d; i++){
    std::cout << elem.at(i) << " ";
  }
  std::cout << std::endl;

  return 0;
}
