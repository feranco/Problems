#include "StackFromQueues.h"
#include <iostream>

int main (void) {
  StackFromQueues<int> s;
  s.push(1);
  s.push(2);
  std::cout << s.pop() << std::endl;
  s.push(4);
  std::cout << s.pop() << std::endl;
  std::cout << s.pop() << std::endl;
}
