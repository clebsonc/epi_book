#include <iostream>
#include <string>
#include <vector>

/**
* Find the indexes of characters c in the string s. The index of each character
* c is emplaced at the end of the the vector v.
* c: the character to be searched on the string s.
* s: string that is being searched
* v: the vector in which the indexes of the character is going to be appended.
*/
void find_letters(const char c, const std::string & s, std::vector<int> & v){
  for(unsigned int i = 0; i<s.size(); i++){
    if(s.at(i) == c)
      v.emplace_back(i);
  }
}

/**
* Find if the string s1 is a rotation of the string s2.
* return: true in case s1 is a rotation of s2, false otherwise.
*/
bool is_rotation(const std::string & s1, const std::string & s2){
  if(s1.size() != s2.size()){
    return false;
  }
  std::vector<int> start;
  find_letters(s1.at(0), s2, start);
  bool rot = true;
  for(int i2 : start){
    rot = true;
    unsigned int bg = i2+1;
    for(unsigned int index = 1; index < s1.size(); index++){
      if(bg == s2.size())
        bg = 0;
      if(s1.at(index) != s2.at(bg)){
        rot = false;
        break;
      }
      bg++;
    }
    if(rot)
      break;
  }
  return rot;
}


int main(){
  std::string s1, s2;
  std::cin >> s1 >> s2;
  bool rot = is_rotation(s1, s2);
  if(rot)
    std::cout << s1 << " is a rotation of " << s2 << std::endl;
  else
    std::cout << s1 << " is not a rotation of " << s2 << std::endl;
  return 0;
}
