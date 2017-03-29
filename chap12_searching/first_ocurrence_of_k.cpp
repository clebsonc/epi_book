#include <iostream>
#include <vector>

/**
* Return the index of the first ocurrence of the searched element.
*/
int binary_search (const std::vector<int> & vector, 
                   int k, int lindex, int rindex){
  if (lindex == rindex && vector.at(lindex) != k){
    return -1;  // value not found;
  }
  int mid = lindex + (rindex - lindex) / 2;
  if (vector.at(mid) == k){
    if(lindex != mid){
      int found = binary_search(vector, k, lindex, mid-1);
      return (found != -1 ? found : mid);
    }
    return mid;
  }
  else if (k < vector.at(mid)){
    return binary_search(vector, k, lindex, mid-1);
  }
  else
    return binary_search(vector, k, mid+1, rindex);
}



int main(){
  std::vector<int> values = {-14, 108, 108, 108, 108, 243, 285, 285, 401};
  int found =  binary_search(values, 108, 0, values.size()-1);
  std::cout << found << std::endl;

  return 0;
}

