#include <iostream>

int main(){
  int x = 0;
  std::cin >> x;
  int s = 0; 
  while(x){
    s+= (x & 1) == 0 ? 0 : 1;
    x = x>>1;
  }
  std::cout << s << std::endl;

  return 0;
}
