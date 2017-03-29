#include <iostream>
#include <unordered_map>
#include <string>


std::unordered_map<char, int> count_characters (const std::string & s){
  std::unordered_map<char, int> hash;
  for (char c : s){
    std::unordered_map<char, int>::iterator it = hash.find(c);
    if (it != hash.end()){
      it->second++;
    }
    else{
      hash.emplace(c, 1);
    }
  }
  return hash;
}

/**
* Finds out if the anonymous letter is constructible. The anonymous letter is
* constructible if the amount of characters it has is no more than the amount 
* of equal character that the magazine has.
*/
bool is_anonymous_letter_constructible (const std::string & letter, 
                                       const std::string & magazine){
  std::unordered_map<char, int> hash = count_characters(magazine);
  for (char l : letter){
    std::unordered_map<char, int>::iterator it = hash.find(l);
    if (it != hash.end()){
      it->second--;
      if (it->second == 0)
        hash.erase(l);
    }
    else{
      return false;
    }
  }
  return true;
}


int main(){
  std::string a = "abacate verde nao e amarelo";
  std::string b = "abacate amarelo nao e verde";
  bool is_constructible = is_anonymous_letter_constructible(a, b);
  if (is_constructible)
    std::cout << "Is constructible" << std::endl;
  else
    std::cout << "Not constructible" << std::endl;

  return 0;
}

