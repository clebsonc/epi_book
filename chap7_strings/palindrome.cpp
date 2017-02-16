#include <string>
#include <iostream>

bool is_palindrome(const std::string & s){
  int i = 0, j = s.size()-1;
  while(i < j){
    if(s.at(i) == s.at(j)){
      i++;
      j--;
    } 
    else{
      return false;
    }
  }
  return true;
}


int main(){
  std::string s;
  std::cin >> s;

  std::cout << s << (is_palindrome(s) == true ? " is " : " is not ") << 
              "a palindromic string.\n";

  return 0;
}
