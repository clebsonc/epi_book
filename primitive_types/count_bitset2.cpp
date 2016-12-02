#include <iostream>

short print_bits(int x){
  unsigned short bits=0;
  int rm=0;
  while(x){
    rm = x & (~x+1);
    bits += (rm > 0 ? 1 : 0);
    x ^= rm;
  }
  return bits;
}

int main(){
  int x;
  std::cin >> x;
  std::cout << "Bits set to one: " << print_bits(x) << std::endl;

  return 0;
}
