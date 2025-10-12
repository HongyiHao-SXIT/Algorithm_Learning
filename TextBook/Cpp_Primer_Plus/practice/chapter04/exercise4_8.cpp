// Create by Shujia Huang on 2021-07-25
#include <iostream>
#include <string>

struct Pizza {
  std::string company;
  double diameter;
  double weight;
};

int main() {
  using namespace std;

  Pizza *pizza = new Pizza;

  cout << "Enter the diameter of pizza: ";
  cin >> pizza->diameter;

  cout << "Enter the weight of pizza: ";
  cin >> pizza->weight;

  // Note that after entering weight in the above statement, the Enter key remains in the input stream. The following getline
  // When it encounters a carriage return in the input stream, it is considered to be over, so if there is no such cin.get(), read first
  // Get the carriage, then the user will always get the value of company.
  cin.get();

  cout << "Enter the pizza company: ";
  getline(cin, pizza->company);

  cout << "\nHere is the pizza information: \n"
       << "Company: " << pizza->company << "\n"
       << "Diameter: " << pizza->diameter << "\n"
       << "Weight: " << pizza->weight << endl;

  delete pizza;

  return 0;
}
