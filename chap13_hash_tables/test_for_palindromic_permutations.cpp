#include <iostream>
#include <unordered_map>
#include <string>

bool is_palindromic_permutation(std::string s){
  std::unordered_map<char, int> hash;
  std::unordered_map<char, int>::iterator it;
  for (char v: s){
    it = hash.find(v);
    if (it != hash.end()){
      it->second++;
    } else {
      hash.emplace(v, 1);
    }
  }
  it = hash.begin();
  int even = 0, odd = 0;
  for (it = hash.begin(); it != hash.end(); it++){
    if (it->second % 2 == 0)
      even++;
    else
      odd++;
  }
  if (s.size() % 2 == 0 && odd > 0 || s.size() % 2 != 0 && odd != 1) {
    return false;
  }
  return true;
}


int main(){
  bool palindromic = is_palindromic_permutation("edifid");
  if (palindromic)
    std::cout << "palindromic word" << std::endl;
  else
    std::cout << "not a palindrome" << std::endl;

  return 0;
}

