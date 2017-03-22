// Exercise 6.6 -- Buy and sell stock once

#include <iostream>
#include <vector>

template <class T>
T maximumProfit(const std::vector<T> & v){
  T smaller = v.at(0);
  T profit = 0;
  for (int i = 0; i < v.size(); i++){
    if (v.at(i) < smaller){
      smaller = v.at(i);
    }
    else if ((v.at(i) - smaller) > profit){
      profit = v.at(i) - smaller;
    }
  }
  return profit;
}

int main(){
  std::vector<float> v = {310, 315, 275, 295, 260, 269, 290, 230, 255, 250.22};
  std::cout << maximumProfit(v) << std::endl;

  return 0;
}

