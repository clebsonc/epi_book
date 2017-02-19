#include <iostream>
#include <string>
#include <cmath>

std::string intToString(int x){
  std::string s;
  bool is_negative = x < 0 ? true : false;
  if(is_negative)
    x*=-1;

  while(x > 0){
    int mod = x % 10;
    x = x / 10;
    s.push_back('0'+mod);
  }

  if(is_negative)
    s.push_back('-');
  s = {s.rbegin(), s.rend()};
  
  return s;
}


int stringToInteger(const std::string & s){
  int number = 0;
  bool is_negative = s.at(0) == '-' ? true : false;
  int index = (is_negative ? 1 : 0);
  int power = s.size() - 1 - index;
  while(index < s.size()){
    number += (s.at(index) - '0') * std::pow(10, power);
    power--;
    index++;
  }
  if(is_negative)
    number*=-1;
  return number;
}


int main(){
  std::string s = intToString(-723);
  std::cout << "Converted: " << s << std::endl;

  int number = stringToInteger("-22302");
  std::cout << "Converted: " << number << std::endl;

  return 0;
}

