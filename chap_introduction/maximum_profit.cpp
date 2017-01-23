#include <iostream>
#include <vector>
#include <climits>


template <typename T>
void read_values(std::vector<T> & array, const int length){
  T v;
  for(int i = 0; i<length; i++){
    std::cin >> v;
    array.push_back(v);
  }
}


template <typename T>
void print_values(const std::vector<T> & array){
  for(T a : array){
    std::cout << a << " ";
  }
  std::cout << std::endl;
}


template<typename T>
T naive_maximum_profit(const std::vector<T> & array){
  T profit = 0.0;
  for(int i = 0; i < array.size()-1; i++){
    for(int j = i+1; j < array.size(); j++){
      int diff = array.at(j) - array.at(i);
      if(diff > profit){
        profit = diff;
      }
    }
  }
  return profit;
}


template <typename T>
T max(T a, T b, T c){
  if(a >= b && a >= c)
    return a;
  if(b >= a && b >= c)
    return b;
  if(c >= a && c >= b)
    return c;
}


template <typename T>
void copy_values(std::vector<T> & array1, const int li, 
                 const int ri, std::vector<T> & array2){
  for(int i = li, k = 0; i <= ri; i++, k++){
    array2.at(k) = array1.at(i);
  }
}

template <typename T>
T combine(std::vector<T> & prices, const int li, const int k, const int ri){
  int nl = k - li + 1;
  int nr = ri - k;
  std::vector <T> left(nl);
  std::vector <T> right(nr);
  copy_values(prices, li, k, left);
  copy_values(prices, k+1, ri, right);
  int i = 0;  // index for the left subarray
  int j = 0;  // index for the right subarray
  int iorig = li; // index for the array prices
  T profit;
  while(iorig < prices.size()){
    if(i == nl || j == nr){
      break;
    }

    profit = right.back() - left.front();
    if(left.at(i) < right.at(j)){
      prices.at(iorig) = left.at(i);
      i++;
      iorig++;
    } else {
      prices.at(iorig) = right.at(j);
      iorig++;
      j++;
    }
  } // end while

  //copy left elements in the subarrays left and right
  while(i < nl){
    prices.at(iorig) = left.at(i);
    i++;
    iorig++;
  }
  while(j < nr){
    prices.at(iorig) = right.at(j);
    j++;
    iorig++;
  }
  return profit;
}

template <typename T>
T maximum_profit(std::vector<T> & prices, const int li, const int ri){
  T profit = 0;
  if(li < ri){
    int middle = (li + ri)/2;
    T a = maximum_profit(prices, li, middle);
    T b = maximum_profit(prices, middle+1, ri);
    T c = combine(prices, li, middle, ri);
    profit = max(a, b, c);
  }
  return profit;
}




int main(){
  std::vector<float> dprices;
  int length = 0;
  std::cin >> length;
  read_values<float>(dprices, length);

  float max_profit = maximum_profit<float>(dprices, 0, dprices.size()-1);
  //float max_profit = naive_maximum_profit<float>(dprices);
  std::cout << "Maximum profit: " << max_profit << std::endl;

  return 0;
}

