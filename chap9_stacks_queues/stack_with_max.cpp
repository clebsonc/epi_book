#include <iostream>
#include <stack>
#include <iostream>

template <typename T>
class MyStack{
  private:
    std::stack<T> max_stack;
    std::stack<T> stack_element;

  public:
    /**
    * Default Constructor
    */
    MyStack(){ }

    /**
    * Constructor that initializes the stack with a given element
    */
    MyStack(T element){
      this->stack_element.emplace(element);
      this->max_stack.emplace(element);
    }


    /**
    * Push element on the stack
    */
    void push(const T & value){
      stack_element.emplace(value);

      if (max_stack.empty()){
        max_stack.emplace(value);
      }
      else if (max_stack.top() <= value){
        max_stack.emplace(value);
      }
    }

    /**
    * Pop element from the stack
    */
    T pop(){
      if (stack_element.empty()){
        return false;
      }
      T removed = stack_element.top();
      stack_element.pop();
      
      if (removed == max_stack.top()){
        max_stack.pop();
      }
      return removed;
    }

    /**
    * Return max element from the stack;
    */
    T max() const{
      if (max_stack.empty()){
        return false;
      }
      return max_stack.top();
    }
};



int main(){
  int n = 0;
  MyStack<int> ms;
  do{
    std::cout << "\n1) push.";
    std::cout << "\n2) pop.";
    std::cout << "\n3) max.";
    std::cout << "\n0) sair.\n>>";
    std::cin >> n;
    if (n == 1){
      int value;
      std::cin >> value;
      ms.push(value);
    }
    else if (n == 2){
      ms.pop();
    }
    else if (n == 3){
      std::cout << "\nMax: " << ms.max() << std::endl;
    }
  } while (n != 0);
  return 0;
}

