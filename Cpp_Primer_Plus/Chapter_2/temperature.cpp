#include <iostream>

using namespace std;
void change_temperary(double temperaty){
    cout << temperaty * 1.8 + 32.0 <<endl;
}

int main(){
    double temperary;
    cin >> temperary;
    change_temperary(temperary);
    return 0;

}