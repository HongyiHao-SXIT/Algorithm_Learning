#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Hello, C++!" << std::endl;
  std::cout << "Number of arguments: " << argc << std::endl;
  for (int i = 0; i < argc; ++i)
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  return 0;
}
