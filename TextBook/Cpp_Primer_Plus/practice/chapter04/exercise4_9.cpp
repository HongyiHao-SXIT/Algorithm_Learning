// Create by Shujia Huang on 2021-07-25

#include <iostream>
#include <string>

struct CandyBar {
  std::string name;
  double weight;
  int calories;
};

int main() {
  using namespace std;

  CandyBar *p_candybar = new CandyBar[3]{
      {"Mocha Munch", 2.3, 350}, {"Big Rabbit", 5, 300}, {"Joy Boy", 4.1, 430}};

  // Output the first structure element as an array
  cout << "The name of the CandyBar: " << p_candybar[0].name << "\n"
       << "The weight of the candy: " << p_candybar[0].weight << "\n"
       << "The calories information: " << p_candybar[0].calories << "\n\n";

  // Output the second structure element, which can be output according to the logic of the pointer
  cout << "The name of the CandyBar: " << (p_candybar + 1)->name << "\n"
       << "The weight of the candy: " << (p_candybar + 1)->weight << "\n"
       << "The calories information: " << (p_candybar + 1)->calories << "\n\n";

  // Output the third structure element, again in the form of data
  cout << "The name of the CandyBar: " << p_candybar[2].name << "\n"
       << "The weight of the candy: " << p_candybar[2].weight << "\n"
       << "The calories information: " << p_candybar[2].calories << endl;

  delete[] p_candybar;

  return 0;
}
