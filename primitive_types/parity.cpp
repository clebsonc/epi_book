#include <iostream>

short count_bits(unsigned long int n){
  short count = 0;
  while(n){
    count ++;
    int y = n & ~(n-1);
    n = n^y;
  }
  return count;
}

short parity(unsigned long int n){
  short qt_bits = count_bits(n);
  short p = qt_bits % 2 == 0 ? 0 : 1;
  return p;
}

int main(){
  unsigned long int n;
  std::cin >> n;
  std::cout << "Parity: " << parity(n) << std::endl;

  return 0;
}
