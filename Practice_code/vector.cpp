#include <iostream>
#include <string>
#include <vector>


int main() {
  std::vector<std::string> websites;

  websites.push_back("nhooo");
  websites.push_back(".com");

  for (std::vector<std::string>::iterator it = websites.begin(); it != websites.end();
       ++it) {
    std::cout << *it;
  }

  return 0;
}
