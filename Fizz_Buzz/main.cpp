// Mason Bennett
// FizzBuzz project
// April 2, 2023

#include <iostream>
#include <string>

void fizzBuzz(int num_fizzes) {
  
  for(int i = 1; i <= num_fizzes; i++) {
    if (i % 3 != 0 && i % 5 != 0)
      std::cout << i << std::endl;
      else if (i % 3 == 0 && i % 5 != 0)
        std::cout << "Fizz" << std::endl;
      else if (i % 3 != 0 && i % 5 == 0)
        std::cout << "Buzz" << std::endl;
      else if (i % 3 == 0 && i % 5 == 0)
        std::cout << "FizzBuzz" << std::endl; 
  }

}

int main() {

  fizzBuzz(100);

  return 0;
}