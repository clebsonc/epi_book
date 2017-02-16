#include <iostream>
#include <new>
#include <cstdlib>

void swap(int * array, int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void even_odd(int * array, int lenght) {
  int i = 0, j = lenght-1;
  while (i < j) {
    while (array[i] % 2 == 0)
      i++;
    while (array[j] % 2 != 0)
      j--;
    if (i < j)
      swap(array, i, j);
  }
}

void print_array(int * array, int length){
  for(int i=0; i < length; i++){
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}


int main(){
  int n=0;
  std::cin >> n;
  
  int * p = nullptr;
  try{
    p = new int[n];
  } catch(const std::bad_alloc & ba){
    std::cerr << "Error allocating memory.\n" << ba.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for(int i = 0; i < n; i++){
    std::cin >> *(p+i);
  }
  
  print_array(p, n);
  even_odd(p, n);
  print_array(p, n);
  


  delete[] p;

  return 0;
}
