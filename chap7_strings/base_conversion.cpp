#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>


std::string decimalToBase(const std::string & s1, int b){
  std::string s2;
  int value = std::stoi(s1);
  while (value != 0){
    int remainder = value % b;
    value = value / b;
    if (remainder >= 10){
      int b10r = remainder % 10;
      s2.push_back('A'+b10r);
    }
    else {
      s2.push_back('0'+remainder);
    }
  }
  std::reverse(s2.begin(), s2.end());
  return s2;
}

std::string baseToDecimal(const std::string & s1, int b){
  int decimal = 0;
  int p = 0;
  for (int i = s1.size()-1; i >= 0; i--){
    int sn = s1.at(i) - '0';
    decimal += sn * std::pow(b, p);
    p++;
  }
  return std::to_string(decimal);
}

std::string base_conversion(const std::string & s1, int b1, int b2){
  std::string s2 = baseToDecimal(s1, b1);
  s2 = decimalToBase(s2, b2);
  return s2;
}

int main(){
  std::cout << base_conversion("615", 7, 13) << std::endl;


  return 0;
}

